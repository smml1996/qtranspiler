from typing import Set, Dict, Optional

import numpy as np
import pandas as pd
from enum import Enum
import os

parsed_results_path = ""
class Experiment(Enum):
    basic_zero_plus_discr =  "basic_zero_plus_discr"
    bell_state_reach = "bell_state_reach"
    bitflip_cxh = "bitflip_cxh"
    bitflip_ipma = "bitflip_ipma"
    bitflip_ipma2 = "bitflip_ipma2"
    ghz3 = "ghz3"
    reset = "reset"

class StatsFileLine:
    def __init__(self, line: str):
        elements = line.split(",")
        self.hardware = elements[0]
        self.embedding_index = int(elements[1])
        self.horizon = int(elements[2])
        self.pomdp_build_time = float(elements[3])
        self.probability = float(elements[4])
        self.method = elements[5]
        self.method_time = float(elements[6])
        self.algorithm_index = int(elements[7])

def get_experiment_path(experiment: Experiment) -> str:
    return os.path.join(parsed_results_path, experiment.value)

def get_stats_path(experiment: Experiment) -> str:
    return os.path.join(get_experiment_path(experiment), "stats.csv")

def get_verification_path(experiment: Experiment) -> str:
    return os.path.join(get_experiment_path(experiment), "verification.csv")

def get_all_hardware(experiment: Experiment) -> Set[int]:
    f = open(get_stats_path(experiment))
    lines = f.readlines()
    f.close()

    diff_hardware = set()
    for line in lines[1:]:
        stats_line = StatsFileLine(line)
        diff_hardware.add(stats_line.hardware)
    return diff_hardware

def get_embedding_count(experiment: Experiment) -> int:
    f = open(get_stats_path(experiment))
    lines = f.readlines()
    f.close()

    diff_embeddings = set()
    for line in lines[1:]:
        stats_line = StatsFileLine(line)
        diff_embeddings.add((stats_line.hardware, stats_line.embedding_index))
    return len(diff_embeddings)

def get_algorithms_count(experiment: Experiment, method: str) -> int:
    f = open(get_stats_path(experiment))
    lines = f.readlines()
    f.close()

    all_algorithms = set()
    for line in lines[1:]:
        stats_line = StatsFileLine(line)
        if stats_line.method == method:
            all_algorithms.add(stats_line.algorithm_index)
    return len(all_algorithms)

def get_methods_used(experiment: Experiment) -> Set[str]:
    f = open(get_stats_path(experiment))
    lines = f.readlines()
    f.close()

    all_methods = set()
    for line in lines[1:]:
        stats_line = StatsFileLine(line)
        all_methods.add(stats_line.method)
    return all_methods

def get_horizon_to_algorithms_count(experiment: Experiment, method:str) -> Dict[int, Set[int]]:
    f = open(get_stats_path(experiment))
    lines = f.readlines()
    f.close()

    result = dict()
    for line in lines[1:]:
        stats_line = StatsFileLine(line)
        if method == stats_line.method:
            if stats_line.horizon not in result.keys():
                result[stats_line.horizon] = set()
            result[stats_line.horizon].add(stats_line.algorithm_index)
    return result


def get_hardware_count(experiment: Experiment) -> int:
    return len(get_all_hardware(experiment))

def get_perfect_hardware_accuracy(experiment: Experiment) -> str:
    f = open(get_stats_path(experiment))
    lines = f.readlines()
    f.close()

    result = ""
    for line in lines[1:]:
        stats_line = StatsFileLine(line)
        if stats_line.hardware == "perfect_hardware":
            if len(result) > 0:
                result += ", "
            result += str(stats_line.probability)
    return result

class Stat(Enum):
    minimum = 0
    maximum = 1
    average = 2

class StatField(Enum):
    probability = 0
    pomdp_build_time = 1
    method_time = 2
    total_time = 3


def get_stat(experiment: Experiment, field: StatField,  stat: Stat) -> Optional[float]:
    f = open(get_stats_path(experiment))
    lines = f.readlines()
    f.close()

    result = None
    if stat == Stat.average:
        count = 0
    else:
        count = 1

    for line in lines[1:]:
        stats_line = StatsFileLine(line)
        if result is None:
            result = stats_line.probability
        else:
            if stat == Stat.minimum:
                if field == StatField.probability:
                    result = min(result, stats_line.probability)
                elif field == StatField.pomdp_build_time:
                    result = min(result, stats_line.pomdp_build_time)
                elif field == StatField.method_time:
                    result = min(result, stats_line.method_time)
                else:
                    assert(field == StatField.total_time)
                    result = min(result, stats_line.method_time + stats_line.pomdp_build_time)

            elif stat == Stat.maximum:
                if field == StatField.probability:
                    result = max(result, stats_line.probability)
                elif field == StatField.pomdp_build_time:
                    result = max(result, stats_line.pomdp_build_time)
                elif field == StatField.method_time:
                    result = max(result, stats_line.method_time)
                else:
                    assert(field == StatField.total_time)
                    result = max(result, stats_line.method_time + stats_line.pomdp_build_time)
            else:
                count += 1
                assert(stat == Stat.average)
                if field == StatField.probability:
                    result += stats_line.probability
                elif field == StatField.pomdp_build_time:
                    result += stats_line.pomdp_build_time
                elif field == StatField.method_time:
                    result += stats_line.method_time
                else:
                    assert(field == StatField.total_time)
                    result += stats_line.method_time + stats_line.pomdp_build_time
    return round(result/count, 5)

def dump_stats_summary(experiment: Experiment):
    with open(f"summary_{experiment.value}.txt", "w") as f:
        print("------", experiment, "------", file=f)
        print("count hardware: ", get_hardware_count(experiment), file=f)
        print("methods used: ", get_methods_used(experiment), file=f)
        print("count embeddings: ", get_embedding_count(experiment), file=f)
        print("total diff. algorithms (bellman): ", get_algorithms_count(experiment, method="bellman"), file=f)
        print("total diff. algorithms (convex): ", get_algorithms_count(experiment, method="convex"), file=f)
        print("accuracy perfect hardware:", get_perfect_hardware_accuracy(experiment), file=f)
        print(file=f)

        print("min. accuracy:", get_stat(experiment, StatField.probability, Stat.minimum), file=f)
        print("avg. accuracy:", get_stat(experiment, StatField.probability, Stat.average), file=f)
        print("max. accuracy:", get_stat(experiment, StatField.probability, Stat.maximum), file=f)
        print(file=f)

        print("min. pomdp build time:", get_stat(experiment, StatField.pomdp_build_time, Stat.minimum), file=f)
        print("avg. pomdp build time:", get_stat(experiment, StatField.pomdp_build_time, Stat.average), file=f)
        print("max. pomdp build time:", get_stat(experiment, StatField.pomdp_build_time, Stat.maximum), file=f)
        print(file=f)

        print("min. method time:", get_stat(experiment, StatField.method_time, Stat.minimum), file=f)
        print("avg. method time:", get_stat(experiment, StatField.method_time, Stat.average), file=f)
        print("max. method time:", get_stat(experiment, StatField.method_time, Stat.maximum), file=f)
        print(file=f)

        print("min. total time:", get_stat(experiment, StatField.total_time, Stat.minimum), file=f)
        print("avg. total time:", get_stat(experiment, StatField.total_time, Stat.average), file=f)
        print("max. total time:", get_stat(experiment, StatField.total_time, Stat.maximum), file=f)
        print(file=f)

        horizon_to_algorithms_count = get_horizon_to_algorithms_count(experiment, "bellman")
        if len(horizon_to_algorithms_count) > 0:
            print("num. algorithms per horizon (method=bellman)", file=f)
        for (horizon, algos) in horizon_to_algorithms_count.items():
            print(horizon, ": ", len(algos), file=f)
        print("--", file=f)
        print(file=f)

        horizon_to_algorithms_count = get_horizon_to_algorithms_count(experiment, "convex")
        if len(horizon_to_algorithms_count) > 0:
            print("num. algorithms per horizon (method=convex)", file=f)
        for (horizon, algos) in horizon_to_algorithms_count.items():
            print(horizon, ": ", len(algos), file=f)
            
def print_stats_summary(experiment: Experiment) -> None:
    print("------", experiment, "------")
    print("count hardware: ", get_hardware_count(experiment))
    print("methods used: ", get_methods_used(experiment))
    print("count embeddings: ", get_embedding_count(experiment))
    print("total diff. algorithms (bellman): ", get_algorithms_count(experiment, method="bellman"))
    print("total diff. algorithms (convex): ", get_algorithms_count(experiment, method="convex"))
    print("accuracy perfect hardware:", get_perfect_hardware_accuracy(experiment))
    print()

    print("min. accuracy:", get_stat(experiment, StatField.probability, Stat.minimum))
    print("avg. accuracy:", get_stat(experiment, StatField.probability, Stat.average))
    print("max. accuracy:", get_stat(experiment, StatField.probability, Stat.maximum))
    print()

    print("min. pomdp build time:", get_stat(experiment, StatField.pomdp_build_time, Stat.minimum))
    print("avg. pomdp build time:", get_stat(experiment, StatField.pomdp_build_time, Stat.average))
    print("max. pomdp build time:", get_stat(experiment, StatField.pomdp_build_time, Stat.maximum))
    print()
    print("min. method time:", get_stat(experiment, StatField.method_time, Stat.minimum))
    print("avg. method time:", get_stat(experiment, StatField.method_time, Stat.average))
    print("max. method time:", get_stat(experiment, StatField.method_time, Stat.maximum))
    print()

    print("min. total time:", get_stat(experiment, StatField.total_time, Stat.minimum))
    print("avg. total time:", get_stat(experiment, StatField.total_time, Stat.average))
    print("max. total time:", get_stat(experiment, StatField.total_time, Stat.maximum))
    print()

    horizon_to_algorithms_count = get_horizon_to_algorithms_count(experiment, "bellman")
    if len(horizon_to_algorithms_count) > 0:
        print("num. algorithms per horizon (method=bellman)")
    for (horizon, algos) in horizon_to_algorithms_count.items():
        print(horizon, ": ", len(algos))
    print("--")
    print()

    horizon_to_algorithms_count = get_horizon_to_algorithms_count(experiment, "convex")
    if len(horizon_to_algorithms_count) > 0:
        print("num. algorithms per horizon (method=convex)")
    for (horizon, algos) in horizon_to_algorithms_count.items():
        print(horizon, ": ", len(algos))

    print("---------------")
    print()
    print()
    print()

