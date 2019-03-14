#!/usr/bin/python3.7
import sys
import subprocess

prog = "./build/main"
number_of_algos = 3
algs = ['word_file_idiom', 'tristan_algorithm', 'boost_algorithm']


def get_result(filename):
    word = None
    with open(filename, 'r', encoding='utf-8', errors='ignore') as file:
        word = [line.strip() for line in file]
    return word[0]


if __name__ == "__main__":
    if len(sys.argv) != 4:
        raise ValueError("Wrong amount of args")
    num, inp, out = int(sys.argv[1]), sys.argv[2], sys.argv[3]
    previous_result = None
    for i in range(1, number_of_algos + 1):
        min_time = float('inf')
        for experiment in range(num):
            res = subprocess.run([prog, "1", inp, out], shell=False,
                                 stdout=subprocess.PIPE)
            cur_time = int(res.stdout.decode().strip())
            if cur_time < min_time:
                min_time = cur_time
        if previous_result is None:
            previous_result = get_result(out)
        elif previous_result != get_result(out):
            raise ValueError("Results don`t match")
        print("\n{}  {}".format(algs[i-1],str(min_time)))