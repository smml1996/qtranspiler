from typing import List, Any, Optional, Dict
from qiskit import QuantumCircuit # pyright: ignore
import json
import logging
import heapq 

class Instruction:
    target: int
    c_target: int
    controls: List[int]
    gate_name: str
    params: List[float]

    def __init__(self, gate_name: str, targets: List[int], c_target: int=-1, params: List[float]=[]):
        self.gate_name = gate_name
        self.c_target = c_target
        self.params = params
        if len(targets) > 3 or len(targets) == 0:
            raise Exception(f"unexpected number of target in instruction {gate_name}, targets={targets}, params={params}")

        if len(targets) == 1:
            self.controls = []
            self.target = targets[0]
        else:
            if gate_name not in ["cx", "ecr", "cz", "rzz"]:
                logging.warning(f"not expected gate_name in instruction: {gate_name}")
            self.target = targets[1]
            self.controls = [targets[0]]

    def serialize(self) -> Dict[str, Any]:
        return {
            "c_target": self.c_target,
            "controls": self.controls,
            "gate_name": self.gate_name,
            "instruction_type": "unitary",
            "matrix": [],
            "params": self.params,
            "params_": [],
            "target": self.target
        }


class Action:
    name: str
    instruction_sequence: List[Instruction]

    def __init__(self, name: str, instruction_sequence: List[Instruction]):
        self.name = name
        self.instruction_sequence = instruction_sequence

    def serialize(self) -> Dict[str, Any]:
        seq_serialized: List[Dict[str, Any]] = []
        for instruction in self.instruction_sequence:
            seq_serialized.append(instruction.serialize())
        return {
            "name": self.name,
            "seq": seq_serialized
        }


class Algorithm:
    classical_state: int
    children: List[Any] # list of other algorithms
    depth: int
    action: Action

    def __init__(self, action: Action, classical_state: int=0, depth: int=0):
        self.action = action
        self.classical_state = classical_state
        self.depth = depth
        self.children = []

    def serialize(self) -> Dict[str, Any]:
        serialized_children: List[Dict[str, Any]] = []

        for child in self.children:
            serialized_children.append(child.serialize())

        return {
            "action": self.action.serialize(),
            "children": serialized_children,
            "children_probs": [],
            "classical_state": self.classical_state,
            "depth": self.depth,
            "precision": 64
        }

    def dump_json(self, path: str) -> None:
        json_string = json.dumps(self.serialize(), indent=4)
        f = open(path, "w")
        f.write(json_string)
        f.close()


def to_algorithm(qc: QuantumCircuit) -> Optional[Algorithm]:
    head : Optional[Algorithm] = None
    current: Optional[Algorithm] = None
    current_depth = 0
    for instruction in qc.data: # pyright: ignore
        # 1. The Gate/Operation object (contains name, params, matrix)
        op: str = instruction.operation # pyright: ignore

        # 2. The specific Qubits involved (returns Qubit objects)
        # We use q.index to get the number (e.g., 0, 1)
        qubits = [q._index for q in instruction.qubits] # pyright: ignore
        
        if len(qubits) == 0:
            raise Exception(f"no target qubits in instruction {op}")

        # 3. The parameters (angles, etc.)
        params: List[float] = op.params # pyright: ignore

        instruction = Instruction(op.name, qubits, params=params) # pyright: ignore
        action = Action(op.__str__(), [instruction]) # pyright: ignore
        temp = Algorithm(action, depth=current_depth)
        current_depth += 1
        if head is None:
            head = temp
            current = head
        else:
            current.children.append(temp) # pyright: ignore
            current = temp

    return head

class BlockResult:
    qc: QuantumCircuit
    score: float
    def __init__(self, qc: QuantumCircuit, score: float) -> None:
        self.qc = qc
        self.score = score
        
    def __lt__(self, other: Any):
        return self.score < other.score
    
class PriorityQueue:
    pq: List[Any]
    def __init__(self) -> None:
        self.pq = []
        
    def push(self, element: Any) -> None:
        heapq.heappush(self.pq, element)
    
    def pop(self) -> Any:
        return heapq.heappop(pq) # pyright: ignore
    
    def is_empty(self) -> bool:
        return len(self.pq) == 0
    
    def len(self) -> int:
        return len(self.pq)

class ChoiState:
    def __init__(self, qc: QuantumCircuit, embedding: Dict[int, int]) -> None:
        pass

    def __eq__(self, other: Any) -> bool:
        pass

class POMDPState:
    qc: ChoiState
    def  __init__(self, qc: ChoiState) -> None:
        self.qc = qc

class POMDP:
    states: List[]
