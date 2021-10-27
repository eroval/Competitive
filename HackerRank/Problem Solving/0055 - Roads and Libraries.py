#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'roadsAndLibraries' function below.
#
# The function is expected to return a LONG_INTEGER.
# The function accepts following parameters:
#  1. INTEGER n
#  2. INTEGER c_lib
#  3. INTEGER c_road
#  4. 2D_INTEGER_ARRAY cities
#


def roadsAndLibraries(n, c_lib, c_road, cities):
    if c_lib<=c_road:
        return n*c_lib
    else:
        cityMatrix = dict()
        boolMask = dict()
        for key in cities:
            boolMask[key[0]]=False
            boolMask[key[1]]=False
            if key[0] not in cityMatrix:
                cityMatrix[key[0]] = list()
            if key[1] not in cityMatrix:
                cityMatrix[key[1]] = list()
            cityMatrix[key[0]].extend([key[1]])
            cityMatrix[key[1]].extend([key[0]])
         
        # import tha gad dayumn que
        from queue import Queue
        Sum = (n-len(cityMatrix))*c_lib
        q = Queue()
        for key in cityMatrix:
            if(boolMask[key]==False):
                boolMask[key]=True
                Sum+=c_lib
                q.put(key)
                while(q.empty()==False):
                    tmp = q.get()
                    for subkey in cityMatrix[tmp]:
                        if(boolMask[subkey]==False):
                            q.put(subkey)
                            Sum+=c_road
                            boolMask[subkey]=True

        return Sum

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input().strip())

    for q_itr in range(q):
        first_multiple_input = input().rstrip().split()

        n = int(first_multiple_input[0])

        m = int(first_multiple_input[1])

        c_lib = int(first_multiple_input[2])

        c_road = int(first_multiple_input[3])

        cities = []

        for _ in range(m):
            cities.append(list(map(int, input().rstrip().split())))

        result = roadsAndLibraries(n, c_lib, c_road, cities)

        fptr.write(str(result) + '\n')

    fptr.close()
