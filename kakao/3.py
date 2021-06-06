#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'minimumMovement' function below.
#
# The function is expected to return an INTEGER.
# The function accepts INTEGER_ARRAY obstacleLanes as parameter.
#

from collections import deque


def move_car(coordinate, obstacleLanes):
    for idx in range(coordinate[1], len(obstacleLanes)):
        if obstacleLanes[idx] == coordinate[0]:
            return [coordinate[0], idx]
    return [coordinate[0], -1]


def minimumMovement(obstacleLanes):
    queue = deque([move_car([2, 0], obstacleLanes)])  # [lane, time]
    cnt = 0
    while queue:
        for _ in range(len(queue)):
            cur = queue.popleft()
            bestLine = [0, -1]
            for lane in range(1, 4):
                tmp = move_car([lane, cur[1]], obstacleLanes)
                if tmp[1] == -1:
                    if tmp[0] != cur[0]:
                        cnt += 1
                    return cnt
                elif tmp[1] > bestLine[1]:
                    bestLine = [lane, tmp[1]]
            queue.append(bestLine)
        cnt += 1


print(minimumMovement([2,1,2]))

