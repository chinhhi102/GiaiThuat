from itertools import permutations
from random import randint
n = 100
use = [False for i in range(n + 1)]
print (n)
k = n // 2
for i in range(1, k):
  x = randint(1, n)
  if not use[x]: 
    print (x, end = " ")
    use[x] = True
for i in range(1, n + 1):
  if not use[i]:
    print (i, end = " ")

