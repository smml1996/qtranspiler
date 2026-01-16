from qiskit import QuantumCircuit, generate_preset_pass_manager
from qiskit.quantum_info import Statevector
from qiskit_ibm_runtime.fake_provider import *
from qiskit_aer import AerSimulator
from qiskit_aer.noise import NoiseModel
import tomli
from pathlib import Path
import csv
from qiskit.quantum_info import SuperOp, process_fidelity
import logging

from benchmark import get_benchmarks

trials_ = 1  # since the transpiler follows randomized heuristics we try this many times for each quantum circuit
max_qubits = 5  # we consider benchmarks that utilize at most this amount of qubit
opt_levels = [opt_level for opt_level in range(4)]  # experiments with all possible optimization levels
backends = FakeProviderForBackendV2().backends()
benchmarks = [
    x for x in get_benchmarks()
    if x.qc.num_qubits <= max_qubits
]  # benchmarks that use at most max_qubits


# paths used in these experiments
with open("config.toml", "rb") as f:
    cfg = tomli.load(f)

results_dir = Path(cfg["paths"]["results_dir"])
exp_dir = results_dir / cfg["small_experiments"]["dir"]

logs_path = exp_dir / cfg["small_experiments"]["logs_file"]
results_path = exp_dir / cfg["small_experiments"]["results_file"]

exp_dir.mkdir(parents=True, exist_ok=True)

# setup logger
logging.basicConfig(
    filename=logs_path,
    level=logging.INFO,
    format="%(asctime)s | %(name)s | %(levelname)s | %(message)s",
)

logger = logging.getLogger(__name__)
logger.info("Benchmark started")

# actual experiments
rows = []
for benchmark in benchmarks:
    for backend in backends:

        if backend.num_qubits >= benchmark.qc.num_qubits:
            for opt_level in opt_levels:
                trials = trials_ if opt_level > 0 else 1   # at optimization level 0 there is no randomization,
                # therefore we just need to test once
                for seed in range(trials):
                    try:
                        simulator = AerSimulator(method="superop",
                                                 noise_model=NoiseModel.from_backend(backend))
                        pm = generate_preset_pass_manager(
                            optimization_level=opt_level,
                            backend=simulator,
                            seed_transpiler=seed
                        )
                        qiskit_qc = pm.run(benchmark.qc)
                        qiskit_qc.save_superop()
                        res_qiskit = simulator.run(qiskit_qc).result()
                        simulator.set_options(noise_model=None)
                        res_ideal = simulator.run(qiskit_qc).result()

                        superop_ideal = res_ideal.data()['superop']
                        superop_qiskit = res_qiskit.data()['superop']

                        row = {
                            'benchmark': benchmark.benchmark_name,
                            'circuit': benchmark.circuit_name,
                            'backend': backend.name,
                            'seed': seed,
                            # original data
                            'n_qubits': benchmark.qc.num_qubits,
                            'depth': benchmark.qc.depth(),
                            'n_ops': benchmark.qc.size(),

                            # raw qiskit results
                            'q_depth': qiskit_qc.depty(),
                            'q_n_ops': qiskit_qc.size(),
                            'q_fidelity': round(process_fidelity(superop_ideal, superop_qiskit), 8),

                            # method results
                            'our_depth': our_depth,
                            'our_n_ops': our_n_ops,
                            'our_fidelity': our_fidelity
                        }
                        rows.append(row)
                    except Exception as e:
                        logger.warning(f"{backend.name}--seed={seed}--opt_level={opt_level}--{benchmark.benchmark_name}/{benchmark.circuit_name}: {e.__str__()}")

# dump results into results file
assert(len(rows) > 0)
fieldnames = [x for x in rows[0].keys()]
with open(results_path, "w", newline="") as f:
    writer = csv.DictWriter(f, fieldnames=fieldnames)
    writer.writeheader()
    writer.writerows(rows)


# TODO: for each seed report std, mean, min, max
