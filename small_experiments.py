from qiskit import generate_preset_pass_manager
from qiskit_ibm_runtime.fake_provider import *
import tomli
from pathlib import Path
import csv
import logging

from benchmark import get_benchmarks
from utils import to_algorithm

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
transpiled_circuits_dir = exp_dir / cfg["small_experiments"]["transpiled_circuits_dir"]

logs_path = exp_dir / cfg["small_experiments"]["logs_file"]
results_path = exp_dir / cfg["small_experiments"]["qiskit_indices"]

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
                        pm = generate_preset_pass_manager(
                            optimization_level=opt_level,
                            backend=backend,
                            seed_transpiler=seed
                        )
                        qiskit_qc = pm.run(benchmark.qc)

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
                        }
                        rows.append(row)

                        # save transpiled circuit
                        circuit_path = (transpiled_circuits_dir /
                                        f"{benchmark.benchmark_name}_{benchmark.circuit_name}_{seed}.json")
                        algorithm = to_algorithm(qiskit_qc)
                        algorithm.dump_json(circuit_path)
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
