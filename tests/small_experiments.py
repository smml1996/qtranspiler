from qiskit import QuantumCircuit, generate_preset_pass_manager, qasm2, transpile
from qiskit_aer import AerSimulator
from qiskit_aer.noise import NoiseModel

from qiskit_ibm_runtime.fake_provider import FakeTorino
from qiskit.quantum_info import SuperOp, process_fidelity, DensityMatrix


def remap_noise_model(original_noise_model, map_dict):
    """
    Creates a new NoiseModel by extracting errors from specific qubits
    and remapping them to new indices (e.g., {112: 0, 113: 1}).
    """
    new_noise_model = NoiseModel()

    # 1. Helper to remap a list of qubits [112, 113] -> [0, 1]
    def get_remapped_qubits(qubits):
        if not qubits: return []
        try:
            return [map_dict[q] for q in qubits]
        except KeyError:
            # If the error involves a qubit we don't care about, ignore it
            return None

    # 2. Copy Quantum Errors (Gate Errors, T1/T2)
    # The noise model stores errors as (instruction_name, qubits, error_obj)
    # We access the internal dictionary carefully
    for inst_name, noise_dict in original_noise_model._local_quantum_errors.items():
        for qubits_tuple, error in noise_dict.items():
            # Convert tuple (112,) to list [112]
            q_list = list(qubits_tuple)

            # Check if these are the qubits we want
            remapped_q = get_remapped_qubits(q_list)

            if remapped_q is not None:
                # Add this error to the new model using the NEW indices
                new_noise_model.add_quantum_error(error, inst_name, remapped_q)

    # 3. Copy Readout Errors
    for qubits_tuple, error in original_noise_model._local_readout_errors.items():
        q_list = list(qubits_tuple)
        remapped_q = get_remapped_qubits(q_list)

        if remapped_q is not None:
            new_noise_model.add_readout_error(error, remapped_q)

    # Copy basis gates so the transpiler knows what is allowed
    new_noise_model.add_basis_gates(original_noise_model.basis_gates)

    return new_noise_model

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
    qiskit_qc_ = pm.run(qc)
    layout = qiskit_qc_.layout.initial_layout
    physical_qubits = [layout[v] for v in qc.qubits]
    print(f"Best Physical Qubits found: {physical_qubits}")

    # 3. Create the Mapping Dictionary
    # "Physical 112 becomes logical 0", "Physical 113 becomes logical 1"
    mapping = {
        physical_qubits[0]: 0,
        physical_qubits[1]: 1
    }

    # 4. Extract the Custom Noise Model
    full_noise_model = NoiseModel.from_backend(backend)
    custom_noise_model = remap_noise_model(full_noise_model, mapping)
    simulator = AerSimulator(method="superop",
                             noise_model=custom_noise_model)
    qiskit_qc = transpile(qc, simulator)
    qiskit_qc.save_superop()
    res_qiskit = simulator.run(qiskit_qc).result()
    simulator.set_options(noise_model=None)
    res_ideal = simulator.run(qiskit_qc).result()

    superop_ideal: SuperOp = res_ideal.data()['superop']
    superop_qiskit: SuperOp = res_qiskit.data()['superop']

    assert superop_ideal.dim == superop_qiskit.dim

    # rho_in = DensityMatrix.from_label('00')
    # rho_out = rho_in.evolve(superop_ideal)
    # assert(rho_out == DensityMatrix.from_label('1+') or rho_out == DensityMatrix.from_label('+1'))
    print(process_fidelity(superop_ideal, superop_qiskit))


if __name__ == "__main__":
    test_superop()
