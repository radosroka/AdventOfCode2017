#!/usr/bin/python3

import sys

def evaluate_condition(reg, cond):
    a = b = 0

    if cond[0] not in reg:
        try:
            a = int(cond[0])
        except ValueError:
            a = 0
    else:
        a = reg[cond[0]]

    if cond[2] not in reg:
        try:
            b = int(cond[2])
        except ValueError:
            b = 0
    else:
        b = reg[cond[2]]

    op = cond[1]

    if op == "==":
        return a == b
    elif op == ">":
        return a > b
    elif op == "<":
        return a < b
    elif op == ">=":
        return a >= b
    elif op == "<=":
        return a <= b
    elif op == "!=":
        return a != b

def process_instruction(reg, line):
    tokens = line.split()
    dest = tokens[0]
    op = tokens[1]
    value = int(tokens[2])

    condition = tokens[4:]
    if evaluate_condition(reg, condition):
        if dest not in reg:
            reg[dest] = 0

        if op == "inc":
            reg[dest] += value
        else:
            reg[dest] -= value

def main():
    registers = {}

    for line in map(str.rstrip, sys.stdin):
        process_instruction(registers, line)

    k, v = None, None
    for key, value in registers.items():
        if k is None or value > v:
            k, v = key, value

    print(registers)
    print("max is ", k, v)



main()
