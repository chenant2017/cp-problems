"""
ID: chenant1
LANG: PYTHON3
TASK: runround
"""

def is_runround(n):
  if not diff_digits(n):
    return False
  s = str(n)
  visited = [False for i in range(len(s))]
  at = 0
  visited[0] = True
  for i in range(len(s) - 1):
    at = (at + int(s[at])) % len(s)
    if visited[at]:
      return False
    visited[at] = True
  at = (at + int(s[at])) % len(s)
  if at == 0:
    return True
  return False
    

def diff_digits(n):
  digits = [None for i in range(10)]
  for i in str(n):
    if digits[int(i)] is not None:
      return False
    digits[int(i)] = 1
  return True

with open("runround.in", "r") as fin, open("runround.out", "w") as fout:
  N = int(fin.readline())
  n = N + 1
  while not is_runround(n):
    n += 1
  fout.write(str(n) + "\n")
