from typing import List, Set, Dict, Optional, Tuple
from enum import Enum
import os
import pandas as pd
import statistics
import math

parsed_results_path: str = ""

class Experiment(Enum):
    basic_zero_plus_discr =  "basic_zero_plus_discr"
    # basic_zero_plus_discr_therm =  "basic_zero_plus_discr_therm"
    bell_state_reach = "bell_state_reach"
    bitflip_cxh = "bitflip_cxh"
    bitflip_ipma = "bitflip_ipma"
    bitflip_ipma2 = "bitflip_ipma2"
    ghz3 = "ghz3"
    reset = "reset"
    # reset_therm = "reset_therm"
    
def get_nice_name (experiment: Experiment) -> str:
    if experiment in [Experiment.basic_zero_plus_discr]:
        return "state discr."
    
    if experiment == Experiment.bell_state_reach:
        return "Bell state reach"
    
    if experiment == Experiment.bitflip_cxh:
        return "Bitflip [CXH]"
    
    if experiment == Experiment.bitflip_ipma:
        return "Bitflip [IPMA]"
    
    if experiment == Experiment.bitflip_ipma2:
        return "Bitflip [IPMA2]"
    
    if experiment == Experiment.ghz3:
        return "GHZ"
    
    if experiment in [Experiment.reset]:
        return "Reset"
    
    raise Exception(f"Nice name not implemented for {experiment}")

def get_thermalization_str(experiment: Experiment) -> str:
    # if experiment in [Experiment.reset_therm, Experiment.basic_zero_plus_discr_therm]:
    #     return "yes"
    return "no"

class StatsFileLine:
    def __init__(self, line: str, is_verification=False):
        line = line.strip()
        elements = line.split(",")
        self.hardware = elements[0]
        self.embedding_index = int(elements[1])
        if is_verification:
            self.horizon = None
            self.pomdp_build_time = None
            self.probability = float(elements[3])
            self.method = elements[4]
            self.method_time = None
            self.algorithm_index = int(elements[2])
        else:
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

def get_improvements_path(experiment: Experiment) -> str:
    return os.path.join(get_experiment_path(experiment), "improvements.csv")

def get_all_hardware(experiment: Experiment, method: str) -> Set[str]:
    f = open(get_stats_path(experiment))
    lines = f.readlines()
    f.close()

    diff_hardware: Set[str] = set()
    for line in lines[1:]:
        stats_line = StatsFileLine(line)
        if stats_line.method == method:
            diff_hardware.add(stats_line.hardware)
    return diff_hardware

def get_embedding_count(experiment: Experiment, method: str) -> int:
    f = open(get_stats_path(experiment))
    lines = f.readlines()
    f.close()

    diff_embeddings: Set[Tuple[str, int]] = set()
    for line in lines[1:]:
        stats_line = StatsFileLine(line)
        if stats_line.method == method:
            diff_embeddings.add((stats_line.hardware, stats_line.embedding_index))
    return len(diff_embeddings)

def get_algorithms(experiment: Experiment, method: str) -> Set[int]:
    f = open(get_stats_path(experiment))
    lines = f.readlines()
    f.close()
    all_algorithms: Set[int] = set()
    for line in lines[1:]:
        stats_line = StatsFileLine(line)
        if stats_line.method == method:
            all_algorithms.add(stats_line.algorithm_index)
    return all_algorithms

def get_algorithms_count(experiment: Experiment, method: str) -> int:
    return len(get_algorithms(experiment, method))

def get_perfect_hardware_algorithms(experiment, method) -> List[Tuple[int, int]]:
    f = open(get_stats_path(experiment))
    lines = f.readlines()
    f.close()
    all_algorithms_sorted: List[Tuple[int, int]] = []
    for line in lines[1:]:
        stats_line = StatsFileLine(line)
        if stats_line.method == method and stats_line.hardware == "perfect_hardware":
            all_algorithms_sorted.append((stats_line.horizon, stats_line.algorithm_index))
    return sorted(all_algorithms_sorted)


def get_algorithms_at_horizon(experiment: Experiment, method: str, horizon: int) -> Set[int]:
    f = open(get_stats_path(experiment))
    lines = f.readlines()
    f.close()

    all_algorithms: Set[int] = set()
    for line in lines[1:]:
        stats_line = StatsFileLine(line)
        if stats_line.method == method and stats_line.horizon == horizon:
            all_algorithms.add(stats_line.algorithm_index)
    return all_algorithms


def get_methods_used(experiment: Experiment) -> Set[str]:
    f = open(get_stats_path(experiment))
    lines = f.readlines()
    f.close()

    all_methods: Set[str] = set()
    for line in lines[1:]:
        stats_line = StatsFileLine(line)
        all_methods.add(stats_line.method)
    return all_methods

def get_horizon_to_algorithms_count(experiment: Experiment, method:str) -> Dict[int, Set[int]]:
    f = open(get_stats_path(experiment))
    lines = f.readlines()
    f.close()

    result: Dict[int, Set[int]] = dict()
    for line in lines[1:]:
        stats_line = StatsFileLine(line)
        if method == stats_line.method:
            if stats_line.horizon not in result.keys():
                result[stats_line.horizon] = set()
            result[stats_line.horizon].add(stats_line.algorithm_index)
    return result


def get_hardware_count(experiment: Experiment, method: str) -> int:
    return len(get_all_hardware(experiment, method))

def get_perfect_hardware_accuracy(experiment: Experiment, method: str) -> str:
    f = open(get_stats_path(experiment))
    lines = f.readlines()
    f.close()

    result = ""
    for line in lines[1:]:
        stats_line = StatsFileLine(line)
        if stats_line.hardware == "perfect_hardware" and stats_line.method == method:
            if len(result) > 0:
                result += ", "
            result += str(stats_line.probability)
    return result

class Stat(Enum):
    minimum = 0
    maximum = 1
    average = 2
    std = 3

class StatField(Enum):
    probability = 0
    pomdp_build_time = 1
    method_time = 2
    total_time = 3


def get_stat(experiment: Experiment, field: StatField,  stat: Stat, method: str) -> Optional[float]:
    f = open(get_stats_path(experiment))
    lines = f.readlines()
    f.close()

    result: Optional[float] = None
    if stat == Stat.average:
        count = 0
    else:
        count = 1

    for line in lines[1:]:
        stats_line = StatsFileLine(line)
        if stats_line.method == method:
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
    if result is None:
        raise Exception("get stat result is None")
    return round(result/count, 5)

def get_algorithms_stat(experiment: Experiment, method_: str) -> List[Tuple[int, float, float, float]]:
    # returns the algorithm index and the improvement
    f = open(get_verification_path(experiment))
    lines = f.readlines()
    f.close()
    alg_to_improvements: Dict[int, List[float]] = dict()

    for line in lines[1:]:
        stats_line = StatsFileLine(line, True)
        method = stats_line.method
        if method == method_:
            algorithm_index = stats_line.algorithm_index
            if algorithm_index not in alg_to_improvements.keys():
                alg_to_improvements[algorithm_index] = []
            alg_to_improvements[algorithm_index].append(stats_line.probability)

    answer: List[Tuple[int, float, float, float]] = []
    for algorithm_index in alg_to_improvements.keys():
        x = alg_to_improvements[algorithm_index]
        answer.append((algorithm_index, max(x), sum(x)/len(x), statistics.stdev(x)))

    return sorted(answer, key=lambda x: (x[1], x[3], x[2], x[0]), reverse=True)

def get_max_improvement(experiment: Experiment, method: str) -> float:
    result = 0
    perfect_hard_algos = get_perfect_hardware_algorithms(experiment, method)
    for (horizon, _) in perfect_hard_algos:
        algorithm_index = get_baseline_index(experiment, method, horizon)
        stats = get_improvements(experiment, method, horizon, algorithm_index)
        if len(stats) > 0:
            result = max(result, stats[0][1][0])
    return result

def get_improvements(experiment: Experiment, method: str, horizon: int, algorithm_index: int) -> List[Tuple[int, Tuple[float, Tuple[str, int]], float, float]]:

    algorithms_to_evaluate = get_algorithms_at_horizon(experiment, method, horizon)
    alg_to_scenario_acc = dict()

    f = open(get_verification_path(experiment))
    lines = f.readlines()
    f.close()

    for line in lines[1:]:
        stats_line = StatsFileLine(line, True)
        if (stats_line.method == method and stats_line.algorithm_index in algorithms_to_evaluate) or stats_line.algorithm_index == algorithm_index:
            hardware_scenario = (stats_line.hardware, stats_line.embedding_index)
            if stats_line.algorithm_index not in alg_to_scenario_acc.keys():
                alg_to_scenario_acc[stats_line.algorithm_index] = dict()
            alg_to_scenario_acc[stats_line.algorithm_index][hardware_scenario] = stats_line.probability

    answer = []
    for other_alg_index in alg_to_scenario_acc.keys():
        if other_alg_index == algorithm_index:
            continue

        current_max = None
        current_hard_max = None
        points = []
        count = 0

        for (hardware_scenario, new_alg_prob) in alg_to_scenario_acc[other_alg_index].items():
            perfect_acc = alg_to_scenario_acc[algorithm_index][hardware_scenario]
            count += 1
            points.append(new_alg_prob - perfect_acc)
            if current_max is None or current_max < new_alg_prob - perfect_acc:
                current_max = new_alg_prob - alg_to_scenario_acc[algorithm_index][hardware_scenario]
                current_hard_max = hardware_scenario

        answer.append((other_alg_index, (current_max, current_hard_max), sum(points)/ len(points), statistics.stdev(points)))

    return sorted(answer, key=lambda x : (x[1][0], x[3], x[2]) , reverse=True)

def get_count_improvements(experiment: Experiment, method: str) -> int:
    result = 0
    perfect_hard_algos = get_perfect_hardware_algorithms(experiment, method)
    for (horizon, _) in perfect_hard_algos:
        result += get_improvements_per_horizon(experiment, method, horizon)
    return result

def dump_summary_table(method, save: bool=True):
    experiment_name: List[str] = []
    horizons: List[int] = []
    hardware_count: List[int] = []
    num_embeddings: List[int] = []
    num_algorithms: List[int] = []
    max_improvements: List[float] = []
    count_improvements: List[float] = []

    avg_build: List[Optional[float]] = []
    max_build: List[Optional[float]] = []

    avg_method: List[Optional[float]] = []
    max_method: List[Optional[float]] = []

    for experiment in Experiment:
        methods_used = get_methods_used(experiment)
        if method in methods_used:
            experiment_name.append(get_nice_name(experiment))
            horizons.append(max(get_horizon_to_algorithms_count(experiment, method).keys()))
            hardware_count.append(get_hardware_count(experiment, method=method))
            num_embeddings.append(get_embedding_count(experiment, method=method))
            num_algorithms.append(get_algorithms_count(experiment, method=method))
            max_improvements.append(get_max_improvement(experiment, method))
            count_improvements.append(get_count_improvements(experiment, method))

            avg_build.append(get_stat(experiment, StatField.pomdp_build_time, Stat.average, method=method))
            max_build.append(get_stat(experiment, StatField.pomdp_build_time, Stat.maximum, method=method))

            avg_method.append(get_stat(experiment, StatField.method_time, Stat.average, method=method))
            max_method.append(get_stat(experiment, StatField.method_time, Stat.maximum, method=method))
            
    df = pd.DataFrame({
        "experiment": experiment_name,
        "horizon": horizons,
        "#hard.": hardware_count,
        "#emb.": num_embeddings,
        "#diff. algo.": num_algorithms,
        "#improv.": count_improvements,
        "max. improv.": max_improvements,
        "avg. build time": avg_build,
        "max. build time": max_build,
        "avg. method time": avg_method,
        "max. method time": max_method,
    })
    
    if save:
        df.to_csv(f"summary_{method}.csv")
    return df

def get_baseline_index(experiment: Experiment, method: str, horizon: int) -> int:
    # CHANGE ME IF EXPERIMENTS CHANGE
    indices = [-1] * 15
    if experiment == Experiment.basic_zero_plus_discr:
        assert method == "convex"
        indices[1] = 278 # perfect hardware
        indices[2] = 281
        indices[3] = 282
    elif experiment == Experiment.bell_state_reach:
        if method == "bellman":
            indices[1] = 0 # perfect hardware
            indices[2] = 2 # perfect hardware
            indices[3] = 18
        elif method == "convex":
            indices[1] = 1 # perfect hardware
            indices[2] = 2 # perfect hardware
            indices[3] = 18
        else:
            raise Exception("Invalid method", method)
    elif experiment == Experiment.bitflip_cxh:
        assert method == "bellman"
        indices[7] = 0
    elif experiment == Experiment.bitflip_ipma:
        assert method == "bellman"
        for i in range(3, 8):
            indices[i] = 22 + i - 3
    elif experiment == Experiment.bitflip_ipma2:
        assert method == "bellman"
        for i in range(3, 9):
            indices[i] = 34 + i - 3
    elif experiment == Experiment.ghz3:
        indices[3] = 8
    elif experiment == Experiment.reset:
        if method == "bellman":
            for i in range(2, 10):
                indices[i] = 151 + i - 2
        else:
            assert method == "convex"
            indices[1] = 135
            indices[2] = 151
            indices[3] = 152
    else:
        raise Exception("invalid experiment", experiment)
    assert indices[horizon] != -1
    return indices[horizon]
def get_improvements_per_horizon(experiment: Experiment, method: str, horizon: int) -> int:
    f = open(get_stats_path(experiment)) # read files where optimal algorithms performance is
    lines = f.readlines()
    f.close()

    hard_to_prob: Dict[Tuple[str, int], float] = dict()
    perfect_alg_index = get_baseline_index(experiment, method, horizon)

    for line in lines[1:]:
        stats_line = StatsFileLine(line, is_verification=False)
        if stats_line.method == method and stats_line.horizon == horizon and stats_line.algorithm_index != perfect_alg_index:
            hardware_scenario = (stats_line.hardware, stats_line.embedding_index)
            assert hardware_scenario not in hard_to_prob.keys()
            hard_to_prob[hardware_scenario] = stats_line.probability # optimal algorithm

    f = open(get_verification_path(experiment)) # read file where all algorithms is executed in all hardware specs
    lines = f.readlines()
    f.close()
    hardware_scenarios: Set[Tuple[str, int]] = set()
    for line in lines[1:]:
        stats_line = StatsFileLine(line, is_verification=True)
        if stats_line.algorithm_index == perfect_alg_index:
            hardware_scenario = (stats_line.hardware, stats_line.embedding_index)
            assert hardware_scenario not in hardware_scenarios
            if hardware_scenario in hard_to_prob.keys():
                if stats_line.probability < hard_to_prob[hardware_scenario]:
                    hardware_scenarios.add(hardware_scenario)
    return len(hardware_scenarios)

def dump_stats_summary(experiment: Experiment):
    methods = get_methods_used(experiment)
    for method in methods:
        with open(f"summary_{experiment.value}_{method}.txt", "w") as f:
            print("------", experiment, "------", file=f)
            print(f"%%%%%%%%%%%% {method} %%%%%%%%%%%%", file=f)
            print(f"count hardware ({method}): ", get_hardware_count(experiment, method=method), file=f)

            print(f"count embeddings ({method}): ", get_embedding_count(experiment, method=method), file=f)
            print(f"total diff. algorithms ({method}): ", get_algorithms_count(experiment, method=method), file=f)
            print(f"accuracy perfect hardware ({method}):", get_perfect_hardware_accuracy(experiment, method=method), file=f)
            print(file=f)

            print(f"min. accuracy ({method}):", get_stat(experiment, StatField.probability, Stat.minimum, method=method), file=f)
            print(f"avg. accuracy ({method}):", get_stat(experiment, StatField.probability, Stat.average, method=method), file=f)
            print(f"max. accuracy ({method}):", get_stat(experiment, StatField.probability, Stat.maximum, method=method), file=f)
            print(file=f)

            print(f"min. pomdp build time ({method}):", get_stat(experiment, StatField.pomdp_build_time, Stat.minimum, method=method), file=f)
            print(f"avg. pomdp build time ({method}):", get_stat(experiment, StatField.pomdp_build_time, Stat.average, method=method), file=f)
            print(f"max. pomdp build time ({method}):", get_stat(experiment, StatField.pomdp_build_time, Stat.maximum, method=method), file=f)
            print(file=f)

            print(f"min. method time ({method}):", get_stat(experiment, StatField.method_time, Stat.minimum, method=method), file=f)
            print(f"avg. method time ({method}):", get_stat(experiment, StatField.method_time, Stat.average, method=method), file=f)
            print(f"max. method time ({method}):", get_stat(experiment, StatField.method_time, Stat.maximum, method=method), file=f)
            print(file=f)

            print(f"min. total time ({method}):", get_stat(experiment, StatField.total_time, Stat.minimum, method=method), file=f)
            print(f"avg. total time ({method}):", get_stat(experiment, StatField.total_time, Stat.average, method=method), file=f)
            print(f"max. total time ({method}):", get_stat(experiment, StatField.total_time, Stat.maximum, method=method), file=f)
            print(file=f)

            print(f"min. total time ({method}):", get_stat(experiment, StatField.total_time, Stat.minimum, method=method), file=f)
            print(f"avg. total time ({method}):", get_stat(experiment, StatField.total_time, Stat.average, method=method), file=f)
            print(f"max. total time ({method}):", get_stat(experiment, StatField.total_time, Stat.maximum, method=method), file=f)
            print(file=f)

            horizon_to_algorithms_count = get_horizon_to_algorithms_count(experiment, method)
            if len(horizon_to_algorithms_count) > 0:
                print(f"num. algorithms per horizon (method={method})", file=f)
            for (horizon, algos) in horizon_to_algorithms_count.items():
                print(horizon, ": ", len(algos), file=f)
            print("--", file=f)
            print(file=f)
            print(file=f)

            print("number of improvements per horizon:", file=f)
            for horizon in horizon_to_algorithms_count.keys():
                print(f"--> horizon {horizon}: {get_improvements_per_horizon(experiment, method, horizon)} ", file=f)

            perfect_hard_algos = get_perfect_hardware_algorithms(experiment, method)

            # print("--- ALGORITHMS ---", file=f)
            # print("perfect hardware algorithm: ", perfect_hard_algos, file=f)
            # improvements = get_algorithms_stat(experiment, method)
            #
            # for (algorithm_index, max_, avg_, std_) in improvements:
            #     print(f"Algorithm {algorithm_index}", file=f)
            #     print(f"\t max: {max_}", file=f)
            #     print(f"\t avg: {avg_}", file=f)
            #     print(f"\t std: {std_}", file=f)

            print(file=f)
            print(file=f)
            print("Improvements with respect to perfect algorithms per horizon", file=f)
            for (horizon, _) in perfect_hard_algos:
                algorithm_index = get_baseline_index(experiment, method, horizon)
                stats = get_improvements(experiment, method, horizon, algorithm_index)
                print(f"Horizon = {horizon}", file=f)
                for (algorithm_index , max_val, avg_val, stdev_val) in stats:
                    if max_val != 0 or avg_val != 0 or stdev_val != 0:
                        print("-> Algorithm:", algorithm_index, file=f)
                        print("--> Max:", max_val, file=f)
                        print("--> Avg:", avg_val, file=f)
                        print("--> Std:", stdev_val, file=f)
                print(file=f)

            print(file=f)
            print(file=f)


def get_improvements_df(experiment: Experiment, method: str):
    perfect_algorithms_ = get_perfect_hardware_algorithms(experiment, method)

    perfect_algorithms = dict()

    perfect_alg_probs = dict()

    for (horizon, alg_index) in perfect_algorithms_:
        if alg_index not in perfect_algorithms.keys():
            perfect_algorithms[alg_index] = []
        perfect_algorithms[alg_index].append(horizon)
        perfect_alg_probs[horizon] = dict()

    f = open(get_verification_path(experiment))
    lines = f.readlines()[1:]
    f.close()

    for line in lines:
        stat_line = StatsFileLine(line, is_verification=True)
        if stat_line.method == method:
            hardware_scenario = (stat_line.hardware, stat_line.embedding_index)
            if stat_line.algorithm_index in perfect_algorithms.keys():
                horizons = perfect_algorithms[stat_line.algorithm_index]
                for horizon in horizons:
                    assert hardware_scenario not in perfect_alg_probs[horizon].keys()
                    perfect_alg_probs[horizon][hardware_scenario] = stat_line.probability

    hardwares = []
    horizons = []
    embeddings = []
    probabilities = []
    perfect_probabilities = []

    f = open(get_stats_path(experiment))
    lines = f.readlines()[1:]
    f.close()

    for line in lines:
        stat_line = StatsFileLine(line, is_verification=False)
        if stat_line.method == method:
            hardware = stat_line.hardware
            embedding_index = stat_line.embedding_index
            hardware_scenario = (hardware, embedding_index)
            if hardware_scenario not in perfect_alg_probs[stat_line.horizon]:
                print(stat_line.horizon)
            perfect_prob = perfect_alg_probs[stat_line.horizon][hardware_scenario]
            if stat_line.probability > perfect_prob:
                hardwares.append(hardware)
                horizons.append(stat_line.horizon)
                embeddings.append(embedding_index)
                probabilities.append(stat_line.probability)
                perfect_probabilities.append(perfect_prob)

    return pd.DataFrame({
        "hardware": hardwares,
        "embedding_index": embeddings,
        "horizon": horizons,
        "probability_opt": probabilities,
        "perfect_opt": perfect_probabilities
    })

def get_all_improvements_df():
    final_df = None
    for experiment in Experiment:
        if experiment not in [Experiment.ghz3]:
            all_methods = get_methods_used(experiment)
            for method in all_methods:
                if method == "bellman":
                    temp_df = get_improvements_df(experiment, method)
                    temp_df["experiment"] = get_nice_name(experiment) + f"[{method}]"

                    if final_df is None:
                        final_df = temp_df
                    else:
                        final_df = pd.concat([final_df,  temp_df], ignore_index=True)

    return final_df

class UnitarySpec:
    is_multiqubit: bool
    succ_prob: float
    gate_name: str
    hardware: str
    embedding_index: int
    def __init__(self, line: str):
        elements = line.split(",")
        self.hardware = elements[0]
        self.embedding_index = int(elements[1])
        self.gate_name = elements[2]
        self.succ_prob = float(elements[3])
        if self.gate_name == "CNOT":
            self.is_multiqubit = True
        else:
            self.is_multiqubit = False
            if self.gate_name not in ["SX", "RZ", "X", "U2", "H", "U3", "RY", "RX", "U1"]:
                raise Exception("unknown gate:", self.gate_name)


class MeasSpec:
    hardware: str
    embedding_index: int
    success0: float
    success1: float
    meas_succ: float
    diff_meas: float
    abs_meas_diff: float

    def __init__(self, line):
        elements = line.split(",")
        self.hardware = elements[0]
        self.embedding_index = int(elements[1])
        self.success0 = float(elements[2])
        self.success1 = float(elements[3])
        self.meas_succ = (self.success1 + self.success0)/2.0
        self.diff_meas = self.success0 - self.success1
        self.abs_meas_diff = abs(self.success0 - self.success1)

def get_algorithms_to_specs(experiment: Experiment, method: str) -> Dict[int, Set[Tuple[str, int]]]:
    f = open(get_stats_path(experiment))
    lines = f.readlines()[1:]
    f.close()

    result = dict()
    for line in lines:
        stat_line = StatsFileLine(line, is_verification=False)
        if stat_line.method == method:
            if stat_line.algorithm_index not in result:
                result[stat_line.algorithm_index] = set()
            result[stat_line.algorithm_index].add((stat_line.hardware, stat_line.embedding_index))

    return result



def dump_summary_specs_per_algo(experiment: Experiment, method: str) -> None:
    experiment_path = get_experiment_path(experiment)

    # load specifications
    meas_specs_path = os.path.join(experiment_path, "measurement_specs.csv")
    meas_specs_file = open(meas_specs_path)
    meas_specs_ = meas_specs_file.readlines()[1:]
    meas_specs = []
    for line in meas_specs_:
        meas_specs.append(MeasSpec(line))
    meas_specs_file.close()

    unitary_specs_path = os.path.join(experiment_path, "unitary_specs.csv")
    unitary_specs_file = open(unitary_specs_path)
    unitary_specs_ = unitary_specs_file.readlines()[1:]
    unitary_specs = []
    for line in unitary_specs_:
        unitary_specs.append(UnitarySpec(line))
    unitary_specs_file.close()

    algorithms_to_specs = get_algorithms_to_specs(experiment, method)
    summary_specs_path = os.path.join(experiment_path, f"specs_summary_per_alg_{method}.csv")
    summary_file = open(summary_specs_path, "w")
    summary_file.write(f"algorithm_index,min_success0,avg_success0,max_success0,min_success1,avg_success1,max_success1,min_meas_succ,avg_meas_succ,max_meas_succ,min_diff_meas,avg_diff_meas,max_diff_meas,min_abs_diff_meas,avg_abs_diff_meas,max_abs_diff_meas,min_succ_1Q,avg_succ_1Q,max_succ_1Q,min_succ_2Q,avg_succ_2Q,max_succ_2Q,num_hardwares\n")
    for (algorithm_index, specs) in algorithms_to_specs.items():
        min_success0 = 100
        avg_success0 = 0.0
        max_success0 = 0.0
        min_success1 = 100
        avg_success1 = 0.0
        max_success1 = 0.0
        min_meas_succ = 100
        avg_meas_succ = 0.0
        max_meas_succ = 0.0
        min_diff_meas = 100
        avg_diff_meas = 0.0
        max_diff_meas = 0.0
        min_abs_diff_meas = 100
        avg_abs_diff_meas = 0.0
        max_abs_diff_meas = 0.0
        min_succ_1Q = 100
        avg_succ_1Q = 0.0
        max_succ_1Q = 0.0
        min_succ_2Q = 100
        avg_succ_2Q = 0.0
        max_succ_2Q = 0.0
        num_hardware_specs = 0
        for spec_ in meas_specs:
            if (spec_.hardware, spec_.embedding_index) in specs:
                min_success0 = min(min_success0, spec_.success0)
                avg_success0 = avg_success0 + spec_.success0
                max_success0 = max(max_success0, spec_.success0)
                min_success1 = min(min_success1, spec_.success1)
                avg_success1 = avg_success1 + spec_.success1
                max_success1 = max(max_success1, spec_.success1)
                min_meas_succ = min(min_meas_succ, spec_.meas_succ)
                avg_meas_succ += spec_.meas_succ
                max_meas_succ = max(max_meas_succ, spec_.meas_succ)
                min_diff_meas = min(min_diff_meas, spec_.diff_meas)
                avg_diff_meas += spec_.diff_meas
                max_diff_meas = max(max_diff_meas, spec_.diff_meas)
                min_abs_diff_meas = min(min_abs_diff_meas, spec_.abs_meas_diff)
                avg_abs_diff_meas += spec_.abs_meas_diff
                max_abs_diff_meas = max(max_abs_diff_meas, spec_.abs_meas_diff)

        count_1Q = 0
        count_2Q = 0
        for spec_ in unitary_specs:
            if (spec_.hardware, spec_.embedding_index) in specs:
                if spec_.is_multiqubit:
                    count_2Q += 1
                    min_succ_2Q = min(min_succ_2Q, spec_.succ_prob)
                    avg_succ_2Q += spec_.succ_prob
                    max_succ_2Q = max(max_succ_2Q, spec_.succ_prob)
                else:
                    count_1Q += 1
                    min_succ_1Q = min(min_succ_1Q, spec_.succ_prob)
                    avg_succ_1Q += spec_.succ_prob
                    max_succ_1Q = max(max_succ_1Q, spec_.succ_prob)
        avg_success0 /= len(specs)
        avg_success1 /= len(specs)
        avg_meas_succ /= len(specs)
        avg_diff_meas /= len(specs)
        avg_abs_diff_meas /= len(specs)
        avg_abs_diff_meas /= len(specs)
        num_hardware_specs = len(specs)
        avg_succ_1Q /= count_1Q
        if count_2Q != 0:
            avg_succ_2Q /= count_2Q
        summary_file.write(f"{algorithm_index},{min_success0},{avg_success0},{max_success0},{min_success1},{avg_success1},{max_success1},{min_meas_succ},{avg_meas_succ},{max_meas_succ},{min_diff_meas},{avg_diff_meas},{max_diff_meas},{min_abs_diff_meas},{avg_abs_diff_meas},{max_abs_diff_meas},{min_succ_1Q},{avg_succ_1Q},{max_succ_1Q},{min_succ_2Q},{avg_succ_2Q},{max_succ_2Q},{num_hardware_specs}\n")
    summary_file.close()

def dump_all_summary_specs():
    for experiment in Experiment:
        methods = get_methods_used(experiment)
        for method in methods:
            dump_summary_specs_per_algo(experiment, method)


def get_class(algorithm: int, d: Dict[int, Set[int]]):
    for (key, vals) in d.items():
        if key == algorithm:
            return key
        if algorithm in vals:
            return key

    return -1

def have_same_stats(stats: List[StatsFileLine], algorithm1: int, algorithm2: int) -> bool:
    stats1 = set()
    stats2 = set()
    for stat_line in stats:
        if stat_line.algorithm_index == algorithm1:
            stats1.add((stat_line.hardware, stat_line.embedding_index, stat_line.probability))
        elif stat_line.algorithm_index == algorithm2:
            stats2.add((stat_line.hardware, stat_line.embedding_index, stat_line.probability))
    assert len(stats1) == len(stats2)
    return stats1 == stats2

def find_witness(stats: List[StatsFileLine], algorithm1: int, algorithm2: int) -> Optional[Tuple[str, int, float]]:
    stats1 = set()
    for stat_line in stats:
        if stat_line.algorithm_index == algorithm1:
            stats1.add((stat_line.hardware, stat_line.embedding_index, stat_line.probability))

    for stat_line in stats:
        if stat_line.algorithm_index == algorithm2:
            if (stat_line.hardware, stat_line.embedding_index, stat_line.probability) not in stats1:
                return (stat_line.hardware, stat_line.embedding_index, stat_line.probability)
    return None

def truncate(x, n):
    factor = 10 ** n
    return math.trunc(x * factor) / factor

def get_algorithms_classes(experiment: Experiment, method: str) -> Dict[int, Set[int]]:
    # load stats
    p = get_verification_path(experiment)
    f = open(p)
    lines = f.readlines()[1:]
    f.close()

    all_stats = []
    for line in lines:
        stat_line = StatsFileLine(line, is_verification=True)
        stat_line.probability = truncate(stat_line.probability, 6)
        all_stats.append(stat_line)

    all_algorithms = get_algorithms(experiment, method)

    result = dict()
    for algorithm1 in all_algorithms:
        found = False
        for algorithm2 in result.keys():
            if have_same_stats(all_stats, algorithm1, algorithm2):
                found = True
                result[algorithm2].add(algorithm1)
                break
            else:
                witness = find_witness(all_stats, algorithm1, algorithm2)
                assert witness is not None
                print(f"{algorithm1} {algorithm2} are not equal because: {witness}")

        if not found:
            result[algorithm1]  = set()

    return result


