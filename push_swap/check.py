import os
import random
import sys

num = 500
a = [0] * num
b = []
answer = ""
while (len(b) < num):
    tmp = random.randrange(0,num)
    if a[tmp] == 0:
        b.append(tmp)
        a[tmp] = -1
for i in b:
    answer += str(i) + " "
print(answer)
os.environ['ARG'] = answer
