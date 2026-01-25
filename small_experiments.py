from qiskit import generate_preset_pass_manager, QuantumCircuit # pyright: ignore
from qiskit_ibm_runtime.fake_provider import * # pyright: ignore
import tomli
from pathlib import Path
import csv
import logging
from typing import List, Dict, Any

from benchmark import get_benchmarks
from utils import to_algorithm

trials_: int = 1  # since the transpiler follows randomized heuristics we try this many times for each quantum circuit
max_qubits = 5  # we consider benchmarks that utilize at most this amount of qubit
opt_levels = [opt_level for opt_level in range(4)]  # experiments with all possible optimization levels
backends = FakeProviderForBackendV2().backends()
benchmark_name = "rigetti"
benchmarks = [
    x for x in get_benchmarks()
    if x.qc.num_qubits <= max_qubits and x.benchmark_name == benchmark_name
]  # benchmarks that use at most max_qubits


# paths used in these experiments
with open("config.toml", "rb") as f:
    cfg = tomli.load(f)

results_dir = Path(cfg["paths"]["results_dir"])
exp_dir = results_dir / cfg["small_experiments"]["exp_dir"]
transpiled_circuits_dir = exp_dir / cfg["small_experiments"]["transpiled_circuits_dir"]

logs_path = exp_dir / cfg["small_experiments"]["logs"]
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
logging.getLogger("qiskit").setLevel(logging.WARNING)

# actual experiments
rows: List[Dict[str, Any]] = []
for benchmark in benchmarks:
    for backend in backends:
        if backend.num_qubits >= benchmark.qc.num_qubits:
            for opt_level in opt_levels:
                trials = trials_ if opt_level > 0 else 1   # at optimization level 0 there is no randomization,
                # therefore we just need to test once
                for seed in range(trials):
                    logger.info(f"{backend.name}--seed={seed}--opt_level={opt_level}--{benchmark.benchmark_name}/{benchmark.circuit_name}")
                    try:
                        pm = generate_preset_pass_manager( # pyright: ignore
                            optimization_level=opt_level,
                            backend=backend,
                            seed_transpiler=seed
                        ) # pyright: ignore
                        qiskit_qc: QuantumCircuit = pm.run(benchmark.qc) # pyright: ignore

                        # save transpiled circuit
                        circuit_path = (transpiled_circuits_dir /
                                        f"{benchmark.benchmark_name}_{benchmark.circuit_name}_{backend.name}_{seed}_{opt_level}.json")
                        algorithm = to_algorithm(qiskit_qc) # pyright: ignore
                        if algorithm is None:
                            raise Exception("Algorithm is None")
                        algorithm.dump_json(circuit_path)
                        row = { # pyright: ignore
                            'benchmark': benchmark.benchmark_name,
                            'circuit': benchmark.circuit_name,
                            'backend': backend.name,
                            'seed': seed,
                            # original data
                            'n_qubits': benchmark.qc.num_qubits,
                            'depth': benchmark.qc.depth(), # pyright: ignore
                            'n_ops': benchmark.qc.size(),

                            # raw qiskit results
                            'q_n_qubits': qiskit_qc.num_qubits, # pyright: ignore
                            'q_depth': qiskit_qc.depth(), # pyright: ignore
                            'q_n_ops': qiskit_qc.size(), # pyright: ignore
                        } # pyright: ignore
                        rows.append(row) # pyright: ignore
                    except Exception as e:
                        logger.warning(f"{backend.name}--seed={seed}--opt_level={opt_level}--{benchmark.benchmark_name}/{benchmark.circuit_name}: {e.__str__()}")

# dump results into results file
fieldnames: List[str] = [x for x in rows[0].keys()]
with open(results_path, "w", newline="") as f:
    writer = csv.DictWriter(f, fieldnames=fieldnames)
    writer.writeheader()
    writer.writerows(rows)
