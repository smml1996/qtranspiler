from typing import List, Any, Optional, Dict
from qiskit import QuantumCircuit
import json


class Instruction:
    target: int
    c_target: int
    controls: List[int]
    gate_name: str
    params: List[float]

    def __init__(self, gate_name, targets, c_target=None, params=None):
        self.gate_name = gate_name
        self.c_target = c_target
        self.params = params
        assert len(targets) > 0
        assert len(targets) < 3

        if len(targets) == 1:
            self.controls = []
            self.target = targets[0]
        else:
            assert gate_name == "cx"
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
        seq_serialized = []
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

    def __init__(self, action: Action, classical_state=0, depth=0):
        self.action = action
        self.classical_state = classical_state
        self.depth = depth

    def serialize(self) -> Dict[str, Any]:
        serialized_children = []

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
    for instruction in qc.data:
        # 1. The Gate/Operation object (contains name, params, matrix)
        op = instruction.operation

        # 2. The specific Qubits involved (returns Qubit objects)
        # We use q.index to get the number (e.g., 0, 1)
        qubits = [q._index for q in instruction.qubits]

        # 3. The parameters (angles, etc.)
        params = op.params

        instruction = Instruction(op, qubits, params=params)
        action = Action(op, [instruction])
        temp = Algorithm(action, depth=current_depth)
        current_depth += 1
        if head is None:
            head = temp
            current = head
        else:
            current.children.append(temp)
            current = temp

    return head

