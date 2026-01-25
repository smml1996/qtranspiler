from qiskit import QuantumCircuit # pyright: ignore
from qiskit_ibm_runtime.fake_provider.fake_backend import FakeBackendV2 # pyright: ignore
from qiskit.dagcircuit import DAGCircuit # pyright: ignore

def transpile(
    qc: QuantumCircuit, 
    hw: FakeBackendV2,
    max_actions: int, # we keep this many possibilities at each step
    num_oracle_guesses: int = 3, # we ask for the oracle for this many answers,
    max_horizon: int = 10
    ) -> QuantumCircuit:
    initial_state = QuantumCircuit()
