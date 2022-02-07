def traverse(cycle, reaches):
  visited = set()
  ans = [None] * len(reaches)

  for i in range(len(cycle)):
    curr = i
    cycle_ = []
    cycle_reaches = set()
    while curr not in visited:
      visited.add(curr)
      #cycle_reaches = cycle_reaches.union(reaches[curr])
      cycle_reaches |= reaches[curr]
      cycle_.append(curr)
      curr = cycle[curr]
    cycle_ans = len(cycle_reaches)
    for i in cycle_:
      ans[i] = cycle_ans
  return ans


import sys
import io
import os
from collections import defaultdict

def Run(input, output):
  
  readline = io.BytesIO(
      os.read(
        input, 
        os.fstat(input).st_size
      )
    ).readline
  ## input using readline()
  ## output using output.write()

  N, K = (int(i) for i in readline().split())

  cows = list(range(N + 1))
  
  reaches = [{i} for i in range(N + 1)]

  for i in range(K):
    a, b = (int(i) for i in readline().split())

    reaches[cows[a]].add(b)
    reaches[cows[b]].add(a)

    cows[a], cows[b] = cows[b], cows[a]

  cycle = [None] * (N + 1)
  for i in range(N + 1):
    cycle[cows[i]] = i

  ans = traverse(cycle, reaches)

  for i in range(1, N + 1):
    output.write("{}\n".format(ans[i]))


def RunFileWrapper(input, output):
  fin = os.open(input, os.O_RDONLY)
  with open(output, 'w') as fout:
    Run(fin, fout)
  os.close(fin)

def RunIO():
  Run(0, sys.stdout)

RunIO()