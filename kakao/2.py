#!/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'processLogs' function below.
#
# The function is expected to return a STRING_ARRAY.
# The function accepts following parameters:
#  1. STRING_ARRAY logs
#  2. INTEGER maxSpan
#

from collections import defaultdict

def processLogs(logs, maxSpan):
    dic = defaultdict(list)
    res = []
    for log in logs:
        ID, time, cmd = log.split()
        dic[ID].append(int(time))
    for key in dic:
        if len(dic[key]) == 2 and abs(dic[key][0] - dic[key][1]) <= maxSpan:
            res.append(int(key))
    return list(map(str, sorted(res)))
if __name__ == '__main__':
