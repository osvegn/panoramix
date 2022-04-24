#!/bin/python3

import sys
from weakref import ref
import math

def villagers_go_to_battle(file, nb_villagers):
    nb = 0
    nfile = []
    for line in file:
        if line.find("Villager") == 0 and line.find("Going into battle!") >= 0:
            nb += 1
        else:
            nfile.append(line)
    if nb != nb_villagers:
        print("ERROR : invalide number of villagers go into battle")
    return (nfile)

def villagers_come_back(file, nb_villagers):
    nb = 0
    nfile = []
    for line in file:
        if line.find("Villager") == 0 and line.find("I'm going to sleep now.") >= 0:
            nb += 1
        else:
            nfile.append(line)
    if nb != nb_villagers:
        print("ERROR : invalide number of villagers come back")
    return (nfile)

def druid_start(file):
    nb = 0
    nfile = []
    for line in file:
        if line.find("Druid: I'm ready... but sleepy...") == 0:
            nb += 1
        else:
            nfile.append(line)
    if nb != 1:
        print("ERROR: invalide number of druid start")
    return nfile

def druid_stop(file):
    nb = 0
    nfile = []
    for line in file:
        if (line.find("Druid: I'm out of viscum. I'm going back to... zZz") == 0):
            nb += 1
        else:
            nfile.append(line)
    if nb != 1:
        print("ERROR: invalide number of druid stop")
    return nfile

def druid_refill(file, refill_number):
    villager_nb = 0
    druid_nb = 0
    nfile = []
    for line in file:
        if line.find("Hey Pano wake up! We need more potion.") > 0:
            villager_nb += 1
        elif line.find("Druid: Ah! Yes, yes, I'm awake! Working on it! Beware I can only make ") == 0:
            druid_nb += 1
        else:
            nfile.append(line)
    print(f"refill number: {refill_number}, druid: {druid_nb}, villagers: {villager_nb}")
    if villager_nb != druid_nb:
        print("ERROR: druid and villagers haven't the same amout of refill")
    if villager_nb != refill_number:
        print("ERROR: invalide number of villager need refill")
    if druid_nb != refill_number:
        print("ERROR: invalide number of druid refill")
    return nfile

def main():
    if len(sys.argv) != 5:
        print("USAGE: ./panoramix X X X X | ./test_sentances X X X X")
        print("Need same panoramix parameters")
        exit(0)
    file = []
    for line in sys.stdin:
        file.append(line)
    file = villagers_go_to_battle(file, int(sys.argv[1]))
    file = villagers_come_back(file, int(sys.argv[1]))
    file = druid_start(file)
    file = druid_stop(file)
    potions = int(sys.argv[2]) * int(sys.argv[4])
    fights = int(sys.argv[1]) * int(sys.argv[3])
    refill_number = math.ceil(fights / int(sys.argv[2])) - 1
    if refill_number > int(sys.argv[4]):
        refill_number = int(sys.argv[4])
    file = druid_refill(file, refill_number)
    print("All good")

main()