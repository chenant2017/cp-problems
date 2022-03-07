import os
import io
import sys
from collections import deque, defaultdict

def Run(fin, fout):
  readline = io.BytesIO(
    os.read(
      fin, 
      os.fstat(fin).st_size
    )
  ).readline

  N, M = (int(i) for i in readline().split()) #cows, cereals
  cereals = defaultdict(set)
  cows = [None if i == 0 else tuple(int(j) for j in readline().split()) for i in range(0, N + 1)]
  for i, (a, b) in enumerate(cows[1:], 1):
    cereals[a].add(i)
    cereals[b].add(i)
  
  final_filled = 0
  final_path = deque([])
  visited = set()

  queue = deque([])
  taken = set()

  for i in range(1, N + 1):
    if i not in visited:
      start = get_start(cows, i, cereals, M)
      queue.append(start)
      final_filled = dfs(cows, start, cereals, M, visited, final_filled, final_path, queue, taken)

  fout.write("{}\n".format(N - final_filled))
  for i in final_path:
    fout.write("{}\n".format(i))

def dfs(cows, start, cereals, M, visited, filled, path, queue, taken): #start is the cow int
  N = len(cows) - 1

  while queue:
    curr = queue.pop()
    if curr in visited:
      continue
    visited.add(curr)
    path.append(curr)
    first, second = cows[curr]

    if first in taken and second in taken:
      continue
    if first in taken:
      taken.add(second)
      filled += 1
      for i in cereals[second]:
        if i not in visited:
          queue.append(i)
    else:
      taken.add(first)
      filled += 1
      for i in cereals[first]:
        if i not in visited:
          queue.append(i)
  return filled

def get_start(cows, start, cereals, M):
  N = len(cows) - 1
  queue = deque([start])
  visited = set()
  taken = set()

  while queue:
    curr = queue.pop()
    if curr in visited:
      continue
    visited.add(curr)
    first, second = cows[curr]

    if first in taken and second in taken:
      return curr
    else:
      taken.add(first)
      taken.add(second)

    for i in cereals[first] | cereals[second]:
      if i not in visited:
        queue.append(i)
  return start
  
Run(0, sys.stdout)