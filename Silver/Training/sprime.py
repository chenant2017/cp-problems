"""
ID: chenant1
LANG: PYTHON3
TASK: sprime
"""

from math import floor

def get_children(strn): 
  result = []
  for i in range(1, 10):
    new = strn + str(i)
    if is_prime(int(new)):
      result.append(new)
  return result

def is_prime(n):
  if n == 1:
    return False
  for i in range(2, floor(n**(1/2)) + 1):
    if n % i == 0:
      return False
  return True

def dfs(strn, length): 
  if len(strn) == length:
    sprimes_.append(strn)
    return 
  for i in get_children(strn):
    dfs(i, length)

with open("sprime.in", "r") as fin, open("sprime.out", "w") as fout:
  length = int(fin.readline())
  sprimes_ = []
  dfs("", length)
  for s in sprimes_:
    fout.write(s + "\n")