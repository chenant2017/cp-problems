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
  N, M = (int(i) for i in readline().split())
  not_adj = defaultdict(set)
  
  for i in range(M):
    x, y = (int(j) for j in readline().split())
    not_adj[x].add(y)
    not_adj[y].add(x)
  
  visited = set()
  count = 0
  sizes = []

  for i in range(1, N + 1):
    if i not in visited:
      component = set()
      dfs(not_adj, i, N, visited, component)
      count += 1
      sizes.append(len(component))
  
  output.write("{}\n".format(count))
  for i in sorted(sizes):
    output.write("{} ".format(i))
  output.write("\n")

def dfs(not_adj, start, N, visited, component):
  queue = deque([start])
  while queue:
    curr = queue.pop()
    if curr in visited:
      continue
    component.add(curr)
    visited.add(curr)
    for i in range(1, N + 1):
      if i not in visited and i not in not_adj[curr]:
        queue.append(i)

Run(0, sys.stdout)