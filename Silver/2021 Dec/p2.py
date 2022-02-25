import sys
import io
import os
from collections import defaultdict, deque

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
    paths = defaultdict(list)
    N, M = (int(i) for i in readline().split()) # points, connections
    min_cost = 2*N**2

    for m in range(M):
      f1, f2 = (int(i) for i in readline().split())
      paths[f1].append(f2)
      paths[f2].append(f1)

    path1 = get_path(paths, 1, visited)
    pathN = get_path(paths, N, visited)

    diff = get_diff(path1, pathN)
    cost = diff**2
    if cost < min_cost:
      min_cost = cost
      if min_cost <= 1:
        output.write("{}\n".format(min_cost))
        continue

    if len(visited) < N:
      for i in range(2, N):
        if i not in visited:
          path = get_path(paths, i, visited)
          diff1 = get_diff(path, path1)
          diffN = get_diff(path, pathN)
          cost = diff1**2 + diffN**2
          if cost < min_cost:
            min_cost = cost
            if min_cost <= 2:
              break

    output.write("{}\n".format(min_cost))

def get_path(paths, start, visited):
  path = []
  queue = deque([start])
  while queue:
    curr = queue.pop()
    path.append(curr)
    visited.add(curr)
    for i in paths[curr]:
      if i not in visited:
        queue.append(i)
  return sorted(path)

def get_diff(path1, path2):
  min_diff = 2*10**5
  for i in path1:
    for j in path2:
      if abs(i - j) < min_diff:
        min_diff = abs(i - j)
        if min_diff == 0:
          return min_diff
  return min_diff


Run(0, sys.stdout)