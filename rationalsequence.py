import sys
from sys import stdin
import math

def parent(p, q):
    if p > q:
        return p-q, q
    return p, q-p

def right(p, q):
    return p+q, q

def left(p, q):
    return p, p+q

def find_da_parent(p, q, step):
    while p > q:
        p, q = parent(p, q)
        step += 1
    return p, q, step

def solve_right(p, q):
    level = p//q
    return q, (2*level + 1)*q - p


def solve_right_edge(p):
    return 1, p+1

def main():
    inpoo = input()
    n, p, q = (inpoo.split(' ')[0], 
               int(inpoo.split(' ')[1].split('/')[0]), 
               int(inpoo.split(' ')[1].split('/')[1]))
    
    print(n, end=' ')
    if q == 1:
        nu, de = solve_right_edge(p)
    elif p < q:
        nu, de = right(*parent(p, q))
    else:
        nu, de = solve_right(p, q)
    print(f"{nu}/{de}")

if __name__ == "__main__":
    n = int(input())
    for _ in range(n):
        main()