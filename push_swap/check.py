import random
import sys

num = 500
a = [0] * num
b = []
while (len(b) < num):
    tmp = random.randrange(0,num)
    if a[tmp] == 0:
        b.append(tmp)
        a[tmp] = -1
for num in b:
    sys.stdout.write(str(num) + " ")
    #print(num, end=" ")
