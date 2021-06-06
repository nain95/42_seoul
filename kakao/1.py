#!/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'arrayChallenge' function below.
#
# The function is expected to return a LONG_INTEGER_ARRAY.
# The function accepts LONG_INTEGER_ARRAY arr as parameter.
#

def arrayChallenge(arr):
    res = []
    sum_list = [0]
    for idx, num in enumerate(arr):
        res.append((num * idx) - sum_list[-1])
        sum_list.append(sum_list[-1] + arr[idx])
    return res


if __name__ == '__main__':
    a = arrayChallenge([2,1,3])
    print(a)
