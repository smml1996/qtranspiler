from utils import *
from qiskit_ibm_runtime.fake_provider import * # pyright: ignore
from benchmark import *
from qiskit import generate_preset_pass_manager # pyright: ignore
import os
import sys 
seed = 0
backend = FakeAlgiers()
opt_level = 3
sys.setrecursionlimit(2000)

path = os.path.join("benchmarks", "ibm", "heisenberg_step_30_4.qasm")
qc = load_qasm_with_fallback(path)
benchmark = Benchmark("ibm", "heisenberg_step_30_4", qc)
pm = generate_preset_pass_manager( # pyright: ignore
    optimization_level=opt_level,
    backend=backend,
    seed_transpiler=seed
) # pyright: ignore
qiskit_qc: QuantumCircuit = pm.run(benchmark.qc) # pyright: ignore
algorithm = to_algorithm(qiskit_qc) # pyright: ignore

algorithm.dump_json("temp.json") # pyright: ignore