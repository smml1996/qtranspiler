from qiskit import QuantumCircuit, generate_preset_pass_manager, qasm2, transpile
from qiskit_aer import AerSimulator
from qiskit_aer.noise import NoiseModel

from qiskit_ibm_runtime.fake_provider import FakeTorino
from qiskit.quantum_info import SuperOp, process_fidelity, DensityMatrix



def test_superop():
    qc = QuantumCircuit(3)
    qc.h(0)
    qc.cx(0, 1)
    qc.cx(1, 2)
    backend = FakeTorino()

    pm = generate_preset_pass_manager(
        optimization_level=3,
        backend=backend,
        seed_transpiler=1123131
    )
    qiskit_qc = pm.run(qc)
    layout = qiskit_qc.layout.initial_layout
    physical_qubits = [layout[v] for v in qc.qubits]
    print(f"Best Physical Qubits found: {physical_qubits}")

    # 3. Create the Mapping Dictionary
    # "Physical 112 becomes logical 0", "Physical 113 becomes logical 1"
    mapping = {
        physical_qubits[0]: 0,
        physical_qubits[1]: 1
    }

    for instruction in qiskit_qc.data:
        # 1. The Gate/Operation object (contains name, params, matrix)
        op = instruction.operation

        # 2. The specific Qubits involved (returns Qubit objects)
        # We use q.index to get the number (e.g., 0, 1)
        qubits = [q._index for q in instruction.qubits]

        # 3. The parameters (angles, etc.)
        params = op.params

        print(f"{op.name:<10} | {str(qubits):<10} | {params}")


if __name__ == "__main__":
    # test_superop()
