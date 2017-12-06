#!/usr/bin/python3

import sys

data = []

for x in map(str.rstrip, sys.stdin):
    data.append(int(x))

pos = 0
minimum = 0
maximum = len(data) - 1
steps = 0

while(pos >= minimum and pos <= maximum):
    last = pos
    pos += data[pos]
    if data[last] >= 3:
        data[last] -= 1
    else:
        data[last] += 1
    steps += 1

print(steps)
