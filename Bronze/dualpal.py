"""
ID: chenant1
LANG: PYTHON3
TASK: dualpal
"""

import math

def is_pal(n): #n is string
  for c in range(len(n)//2):
    if n[c] != n[len(n) - 1 - c]:
      return False
  return True

def to_base(n10, base): #n10 is int
  n = ""
  start = math.floor(math.log(n10, base))
  for i in range(start, -1, -1):
    step = base**i
    p = n10 // step
    n10 %= step
    if p > 9:
      p = chr(ord("A") + p - 10)
    n += str(p)
  return n

def find_pals(N, S):
  nums = []
  count = 0
  pals = 0
  while count < N:
    S += 1
    pals = 0
    for i in range(2, 11):
      if is_pal(to_base(S, i)):
        pals += 1
    if pals >= 2:
      count += 1
      nums.append(S)
  return nums
  
with open('dualpal.in', 'r') as fin, open('dualpal.out', 'w') as fout:
  inputs = fin.readline().strip().split(" ")
  for i in find_pals(int(inputs[0]), int(inputs[1])):
    fout.write(str(i) + '\n')