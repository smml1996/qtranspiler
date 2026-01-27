from qiskit import QuantumCircuit, transpile
from typing import Optional, Dict
from qiskit.quantum_info import Operator, Choi, Kraus, state_fidelity, DensityMatrix
from qiskit_ibm_runtime.fake_provider.fake_backend import FakeBackendV2
import scipy.linalg as la
from qiskit_aer import AerSimulator
import numpy as np


def get_closest_unitary(current_qc: QuantumCircuit,
                        embedding: Dict[int, int],
                        hardware_spec: FakeBackendV2,
                        target_qc: QuantumCircuit) -> Operator:
    '''
    compute closest_unitary such that target_qc ~~ closest_unitary * current_qc
    Parameters
    ----------
    current_qc
    embedding
    hardware_spec
    target_qc

    Returns
    -------

    '''
    noise_model = hardware_spec.noise_model
    # noisy real density matrix
    sim_dm = AerSimulator(
        method="density_matrix",
        noise_model=noise_model
    )
    qc1_t = transpile(current_qc, sim_dm, initial_layout=embedding, optimization_level=0)
    res1 = sim_dm.run(qc1_t).result()

    rho1 = res1.data(0)["density_matrix"]
    kraus = Kraus(rho1)
    K0 = kraus.data[0]  # assuming this is the dominant kraus operator

    # 2. Get the matrix for your target unitary T
    T_mat = Operator(target_qc).data

    # 3. Calculate the matrix we want to approximate as unitary
    # Since U' * K0 = T  =>  U' = T * (K0_inverse)
    # To find the closest unitary, we analyze A = T @ K0.conj().T
    A = T_mat @ K0.conj().T

    V, S, Wh = la.svd(A)

    # 5. Construct the closest unitary U_prime
    U_prime_mat = V @ Wh
    U_prime_gate = Operator(U_prime_mat)
    return U_prime_gate

def get_score(
        current_qc: QuantumCircuit, # executed using hardware specification (+embedding)
        embedding: Dict[int, int],
        hardware_spec: FakeBackendV2,
        target_qc: QuantumCircuit # executed noiseless
) -> float:
    '''
    Compares how 'close' are current_qc and target_qc when current_qc is executed in the given hardware specification
    (+ embedding) and target_qc is executed noiseless
    '''
    # Noisy current qc density matrix
    noise_model = hardware_spec.noise_model
    sim_dm = AerSimulator(
        method="density_matrix",
        noise_model=noise_model
    )
    qc1_t = transpile(current_qc, sim_dm, initial_layout=embedding, optimization_level=0)
    res1 = sim_dm.run(qc1_t).result()
    rho1 = res1.data(0)["density_matrix"]

    # noise free target density matrix
    sim_sv = AerSimulator(method="density_matrix")
    qc2_t = transpile(target_qc, sim_sv)
    res2 = sim_sv.run(qc2_t).result()
    rho2 = res2.data(0)["density_matrix"]
    return state_fidelity(rho1, rho2)

class Vertex:
    logical_qc: QuantumCircuit
    embedding: Dict[int, int]
    closest_unitary: Operator
    score: float
    num_qubits: int
    def __init__(self, qc: Optional[QuantumCircuit],
                 embedding: Optional[Dict[int, int]],
                 num_qubits: int,
                 hardware_spec: FakeBackendV2,
                 target_qc: QuantumCircuit):
        '''
        :param qc: logical quantum circuit representing
        :param embedding: mapping for the current logical circuit into physical qubits
        :param num_qubits: this is used to create quantum circuit and to catch data so we do not repetedly recompute
        :param hardware_spec: hardware specification used to catch data and not recompute
        :param target_qc: (logical) target quantum circuit used to computed catched data
        Parameters
        ----------
        qc
        embedding
        num_qubits
        hardware_spec
        target_qc
        '''
        self.num_qubits = num_qubits
        if embedding is None:
            self.embedding = {}
        else:
            self.embedding = embedding
        if qc is None:
            self.logical_qc = QuantumCircuit(num_qubits)
            self.closest_unitary = Operator(QuantumCircuit(num_qubits))
        else:
            self.logical_qc = qc
            # we are going to ask the oracle to find synthesize a unitary and this is the closest unitary such that
            # target_qc ~~ closest_unitary * logical_qc
            self.closest_unitary = get_closest_unitary(self.logical_qc,
                                                       self.embedding,
                                                       hardware_spec, target_qc)
        self.score = get_score(self.logical_qc, self.embedding, hardware_spec, target_qc)


    def __eq__(self, other):
        u1 = Operator(self.logical_qc)
        u2 = Operator(other.logical_qc)
        return self.embedding == other.embedding and u1.equiv(u2)

    def get_score(self, hardware_spec: FakeBackendV2, target_qc: QuantumCircuit) -> float:
        return self.score

