from qiskit import QuantumCircuit, transpile
from qiskit_ibm_runtime.fake_provider.fake_backend import FakeBackendV2
from utils import Vertex
from typing import Optional, List, Tuple, Dict
from copy import deepcopy

def is_physical_qc_repeated(qcs: List[QuantumCircuit], new_qc) -> bool:
    for qc in qcs:
        if qc == new_qc:
            return True
    return False

def get_logical_circuit(current_vertex, p_qc: QuantumCircuit, only_first: bool) -> Tuple[QuantumCircuit, Dict[int, int]]:
    embedding = deepcopy(current_vertex.embedding)
    num_qubits = current_vertex.num_qubits
    layout = p_qc.layout

    if layout:
        # The 'initial_layout' shows which physical qubit each virtual qubit started on
        input_mapping = layout.initial_layout
        # Iterate to see the specific mapping
        for virtual_bit, physical_bit in input_mapping.get_virtual_bits().items():
            if virtual_bit not in embedding:
                embedding[virtual_bit] =  physical_bit
                assert 0 <= virtual_bit < num_qubits
            else:
                assert embedding[virtual_bit] == physical_bit
    else:
        raise Exception("no layout")

    rev_embedding = dict()
    for key,value in embedding.iterms():
        assert value not in rev_embedding.keys()
        rev_embedding[value] = key

    logical_qc = QuantumCircuit(num_qubits)
    n = 1 if only_first else len(p_qc.data)
    for inst, qargs, cargs in p_qc.data[:n]:
        logical_qargs = []
        for q in qargs:
            if q not in rev_embedding:
                # This instruction acts on an ancilla-only qubit
                logical_qargs = None
                raise Exception("not expecting this")
            logical_qargs.append(rev_embedding[q])

        if logical_qargs is not None:
            logical_qc.append(inst, logical_qargs, cargs)

    return logical_qc, embedding


def query_oracle(current_state: Vertex, hardware_spec: FakeBackendV2, m: int,
                  k: int,) -> List[Tuple[QuantumCircuit, Dict[int, int]]]:

    current_layout = current_state.embedding

    # create a logical circuit that contains the closest_unitary
    remaining_op = QuantumCircuit(current_state.num_qubits)
    remaining_op.unitary(current_state.closest_unitary, range(current_state.num_qubits), label='U_prime')

    physical_circuits: List[QuantumCircuit] = []
    for i in range(m):
        qc_transpiled = transpile(remaining_op, backend=hardware_spec, optimization_level=3,
                  initial_layout=current_layout)
        if not is_physical_qc_repeated(physical_circuits, qc_transpiled):
            physical_circuits.append(qc_transpiled)

    answer = []
    for pc in physical_circuits:
        if k == 1:
            answer.append(get_logical_circuit(pc, only_first=False))
        else:
            answer.append(get_logical_circuit(pc, only_first=True))
    return answer


def find_circuit(current_state: Vertex, hardware_spec: FakeBackendV2, k: int, m: int,
                 target_qc: QuantumCircuit, num_qubits: int) -> Vertex:
    if k == 0:
        # if horizon is 0 then we do not look anymore for better circuits
        return current_state

    actions = query_oracle(current_state, hardware_spec, m, k) # query oracle for gates to append to the current vertex

    answer: Optional[Vertex] = current_state # stores the vertex that provides the better score (process fidelity)
    for (next_op, new_embedding) in actions:
        assert isinstance(next_op, QuantumCircuit)
        assert len(new_embedding.keys()) <= num_qubits
        new_vertex = deepcopy(current_state)
        new_vertex.embedding = new_embedding
        new_vertex.logical_qc.compose(next_op, inplace=True)
        new_vertex = find_circuit(new_vertex, hardware_spec, k-1, m, target_qc, num_qubits)
        if new_vertex.score > answer.score:
            answer = new_vertex
    return answer


def my_transpile(
        qc: QuantumCircuit, # desired quantum circuit to transpile (logical circuit)
        k: int, # horizon
        m: int, # max points to keep at each step
        hardware_spec: FakeBackendV2
) -> Vertex:
    num_qubits = qc.num_qubits
    initial_state = Vertex(None, None, num_qubits,
                           hardware_spec, qc) # initializes to an empty circuit and embedding
    answer: Vertex = find_circuit(initial_state, hardware_spec, k, m, qc, num_qubits)
    return answer

