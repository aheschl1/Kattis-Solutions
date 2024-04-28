import sys
from sys import stdin
import math


def main():
    inpoo = stdin.readlines()
    solved = 0
    penalty = {}
    time_total = 0
    for line in inpoo[0:-1]:
        time, problem, win = line.strip().split(" ")
        win = win == "right"
        if not win:
            penalty[problem] = (penalty.get(problem, 0) + 1)
        else:
            solved += 1
            time_total += int(time) + 20*penalty.get(problem, 0)
    print(solved, time_total)

        

if __name__ == "__main__":
    main()