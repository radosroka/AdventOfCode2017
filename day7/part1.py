#!/usr/bin/python3

import sys

class Item(object):

    name = ""
    weight = 0

    childs = []

    def __init__(self, line):
        super(Item, self).__init__()
        tokens = line.split(" ")
        self.name = tokens[0]
        self.weight = tokens[1][1:-1]

        if len(tokens) > 2:
            arr = tokens[3:]
            for i in range(len(arr)):
                if arr[i][-1] == ",":
                    arr[i] = arr[i][:-1]
            self.childs = arr[:]

        #print(self.name, self.weight, self.childs)


def main():
    items = {}
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

    print(potential_roots)


main()
