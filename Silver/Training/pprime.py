"""
ID: chenant1
LANG: PYTHON3
TASK: pprime
"""

import math

def get_pals(start, end):
  pals = []
  for i in range(1, 10000):
    n = int(str(i) + reverse(str(i)))
    if n > end:
      break
    if n >= start:
      pals.append(n)
  for i in range(1, 10000):
    n = int(str(i) + reverse(str(i))[1:])
    if n > end:
      break
    if n >= start:
      pals.append(n)
  return pals

def reverse(s):
  result = ""
  for c in range(len(s) - 1, -1, -1):
    result += s[c]
  return result

def is_prime(n):
  if n == 1:
    return False
  for i in range(2, math.floor(n**(1/2)) + 1):
    if n % i == 0:
      return False
  return True


def get_prime_pals(start, end):
  result = []
  pals = get_pals(start, end)
  for p in pals:
    if is_prime(p):
      result.append(p)
  return sorted(result)

with open("pprime.in", "r") as fin, open("pprime.out", "w") as fout:
  info = [int(i) for i in fin.readline().split()]
  for p in get_prime_pals(info[0], info[1]):
    fout.write(str(p) + "\n")