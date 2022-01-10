"""
ID: chenant1
LANG: PYTHON3
TASK: frac1
"""

def gcd(a, b): #a >= b
  if a % b == 0:
    return b
  else:
    return gcd(b, a % b)

def is_coprime(a, b):
  return True if gcd(a, b) == 1 else False  
  
def find_fracs(N):
  result = {(0, 1), (1, 1)}
  for i in range(2, N + 1): #denominator
    for j in range(1, i): #numerator
      if is_coprime(i, j):
        result.add((j, i))
  return sorted(result, key=lambda x: x[0]/x[1])

with open("frac1.in", "r") as fin, open("frac1.out", "w") as fout:
  N = int(fin.readline())
  for f in find_fracs(N):
    fout.write("{}/{}\n".format(f[0], f[1]))