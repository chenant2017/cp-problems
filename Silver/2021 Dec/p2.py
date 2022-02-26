import sys
import io
import os
from collections import deque

def Run(input, output):
  readline = io.BytesIO(
      os.read(
        input, 
        os.fstat(input).st_size
      )
    ).readline
  ## input using readline()
  ## output using fout.write()

  T = int(readline())
  
  for t in range(T):
    visited = set()
    paths = {}
    N, M = (int(i) for i in readline().split()) # points, connections

    for m in range(M):
      f1, f2 = (int(i) for i in readline().split())
      if f1 in paths:
        paths[f1].append(f2)
      else:
        paths[f1] = [f2]
      if f2 in paths:
        paths[f2].append(f1)
      else:
        paths[f2] = [f1]
    
    min_cost = get_cost(paths, visited, N)
    output.write("{}\n".format(min_cost))

def get_path(paths, start, visited):
  path = []
  queue = deque([start])
  while queue:
    curr = queue.pop()
    path.append(curr)
    visited.add(curr)
    if curr in paths:
      for i in paths[curr]:
        if i not in visited:
          queue.append(i)
  return sorted(path)

def get_cost(paths, visited, N):
  min_cost = 2*N**2
  paths2 = []
  path1 = None
  pathN = None

  for i in range(1, N + 1):
    if i not in visited:
      path = get_path(paths, i, visited)
      if path1 is None and 1 in visited:
        path1 = path
        if pathN is None and N in visited:
          return 0
      elif pathN is None and N in visited:
        pathN = path
      else:
        paths2.append(path)

  diff = get_diff(path1, pathN)
  cost = diff**2
  if cost < min_cost:
    min_cost = cost
    if min_cost <= 1:
      return min_cost

  for p in paths2:
    diff1 = get_diff(p, path1)
    diffN = get_diff(p, pathN)
    cost = diff1**2 + diffN**2
    if cost < min_cost:
      min_cost = cost
      if min_cost <= 2:
        return min_cost
  
  return min_cost

def get_diff(path1, path2):
  min_diff = 2*10**5
  i = 0
  j = 0

  while i < len(path1) and j < len(path2):
    diff = abs(path2[j] - path1[i])
    if diff < min_diff:
      min_diff = diff
    if path1[i] < path2[j]:
      i += 1
    else:
      j += 1

  return min_diff
    
Run(0, sys.stdout)