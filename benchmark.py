from typing import List, Dict, Any, Union
from qiskit import QuantumCircuit
from pathlib import Path
import tomli
import csv

from qiskit.qasm2 import QASM2ParseError
from qiskit.qasm3 import loads

CCZ_DEF = """
gate ccz a,b,c {
    h c;
    cx b,c;
    h c;
}
"""


class Benchmark:
    """
    Benchmark object
    """
    benchmark_name: str  # this is the name of the directory inside the benchamarks/ directory
    circuit_name: str  # filename (without extension) inside 'benchmark_name' directory
    qc: QuantumCircuit

    def __init__(self, benchmark_name: str, circuit_name: str, qc: QuantumCircuit):
        self.benchmark_name = benchmark_name
        self.circuit_name = circuit_name
        self.qc = qc

    def __str__(self):
        return f"{self.benchmark_name}/{self.circuit_name}"


def load_qasm_with_fallback(qasm_file: Path) -> QuantumCircuit:
    """
    Given a qasm file path it first tries to load it using QASM2 otherwise it uses QASM3
    :param qasm_file: path to the QASM file
    :return: quantum circuit
    """
    with open(qasm_file, "r") as f:
        text = f.read()

    if "ccz" in text and "gate ccz" not in text:
        text = text.replace(
            'include "qelib1.inc";',
            'include "qelib1.inc";\n' + CCZ_DEF
        )

    try:
        return QuantumCircuit.from_qasm_str(text)
    except QASM2ParseError:
        pass

    try:
        # try OPENQASM3
        return loads(text)
    except Exception as e:
        raise RuntimeError(
            f"Failed to load {qasm_file}"
        ) from e


def get_benchmarks() -> List[Benchmark]:
    """
    loads all benchmarks
    :return: a list of Benchmarks
    """
    result: List[Benchmark] = []
    with open("config.toml", "rb") as f:
        cfg = tomli.load(f)

    qasm_dir = Path(cfg["paths"]["benchmarks_dir"])

    for qasm_file in qasm_dir.rglob("*.qasm"):
        benchmark_name = qasm_file.parent.name
        circuit_name = qasm_file.stem

        qc = load_qasm_with_fallback(qasm_file)

        benchmark = Benchmark(benchmark_name, circuit_name, qc)
        result.append(benchmark)

    return result


def get_circuit_stats() -> List[Dict[str, Union[str, int, float]]]:
    benchmarks: List[Benchmark] = get_benchmarks()
    print("num. benchmarks:", len(benchmarks))

    result = []
    for benchmark in benchmarks:
        row: Dict[str, Union[str, int, float]] = dict()
        row["benchmark"] = benchmark.benchmark_name
        row["circuit"] = benchmark.circuit_name
        row["n_qubits"] = benchmark.qc.num_qubits
        row["depth"] = benchmark.qc.depth()
        row["n_ops"] = benchmark.qc.size()
        result.append(row)

    return result


def dump_benchmarks_stats() -> None:
    stats = get_circuit_stats()

    with open("config.toml", "rb") as f:
        cfg = tomli.load(f)

    stats_filename = Path(cfg["paths"]["benchmarks_stats"])

    assert len(stats) > 0
    fieldnames = [x for x in stats[0].keys()]

    with open(stats_filename, "w", newline="") as f:
        writer = csv.DictWriter(f, fieldnames=fieldnames)
        writer.writeheader()
        writer.writerows(stats)


if __name__ == "__main__":
    dump_benchmarks_stats()
