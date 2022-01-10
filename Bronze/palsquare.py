"""
ID: chenant1
LANG: PYTHON3
TASK: palsquare
"""

import math

def is_pal(n): #n is string
  for c in range(len(n)//2):
    if n[c] != n[len(n) - 1 - c]:
      return False
  return True
  
def method(base, fin, fout):
  def tobase10(n):#n is string
    base10 = 0
    d = 0
    for i, j in enumerate(n):
      if ord(j) >= 65:
        d = ord(j) - 54
      else:
        d = int(j)
      a = d * (base ** (len(n) - 1 - i))
      base10 += a
    return base10

  def tobase(n10): #n10 is int
    n = ""
    start = math.floor(math.log(n10, base))
    for i in range(start, -1, -1):
      p = 0
      while n10 >= 0:
        n10 -= base**i
        p += 1
      p -= 1
      n10 += base**i
      if p > 9:
        p = chr(ord("A") + p - 10)
      n += str(p)
    return n

  for N in range(1, 300):
    squared = tobase(N**2)
    print(N, tobase(N), squared)
    if is_pal(squared):
      fout.write(tobase(N) + " " + squared + "\n")

with open('palsquare.in', 'r') as fin, open('palsquare.out', 'w') as fout:
  method(int(fin.readline().strip()), fin, fout)