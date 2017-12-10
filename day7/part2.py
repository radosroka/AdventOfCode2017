#!/usr/bin/python3

import sys
import statistics
from collections import Counter


items = {}


class Item(object):

    name = ""
    weight = 0
    weight_all = 0

    childs = []

    def __init__(self, line):
        super(Item, self).__init__()
        tokens = line.split(" ")
        self.name = tokens[0]
        self.weight = int(tokens[1][1:-1])
        self.weight_all = self.weight

        if len(tokens) > 2:
            arr = tokens[3:]
            for i in range(len(arr)):
                if arr[i][-1] == ",":
                    arr[i] = arr[i][:-1]
            self.childs = arr[:]

        #print(self.name, self.weight, self.childs)

def recursive(root, higher):
    for i in root.childs:
        recursive(i, root)

    if higher != None:
        higher.weight_all += root.weight_all

    if len(root.childs) == 0:
        return

    arr = list([ i.weight_all for i in root.childs])
    names = list([ i.name for i in root.childs])

    arr2 = list([ [i.name, i.weight, i.weight_all] for i in root.childs])
    print(root.name, root.weight, root.weight_all , "->", arr2)

    counted = Counter(arr)
    if len(counted) == 1:
        return

    for c in counted:
        if counted[c] == 1:
            index = arr.index(c)
            name = names[index]
            number = 0
            for i in arr:
                if i - c != 0:
                    number = i - c
                    break

            print(name, "->", items[name].weight + number)
            exit(0)


def main():
    for line in map(str.rstrip, sys.stdin):
        i = Item(line)
        items[i.name] = i

    potential_roots = list(items.keys())
    for i in items.values():
        for ch in i.childs:
            potential_roots.remove(ch)

    for i in items.values():
        childs = i.childs[:]

        ch = list([items[value] for value in childs])
        i.childs = ch[:]

    recursive(items[potential_roots[0]], None)


main()
