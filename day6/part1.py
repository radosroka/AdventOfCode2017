#!/usr/bin/python3
import sys
import time

data = [0,2,7,0]



data = list(map(int, input().split()))

history = [data[:]]

l = len(data)

cycle = 0

while(True):
    print(data)
    m = max(data)
    index_m = data.index(m)
    data[index_m] = 0

    for i in range(1, m+1):
        data[(index_m + i) % l] += 1

    cycle += 1
    if (data in history):
        break
    history.append(data[:])


print(cycle)
