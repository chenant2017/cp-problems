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

  not_visited = set(range(1, N + 1))
  count = 0
  sizes = []

  while not_visited:
    len1 = len(not_visited)
    dfs(not_adj, N, not_visited)
    len2 = len(not_visited)
    count += 1
    sizes.append(len1 - len2)
  
  output.write("{}\n".format(count))
  for i in sorted(sizes):
    output.write("{} ".format(i))
  output.write("\n")

def dfs(not_adj, N, not_visited):
  start = not_visited.pop()
  queue = deque([start])
  while queue:
    curr = queue.pop()
    if curr != start:
      if curr not in not_visited:
        continue
      not_visited.remove(curr)
    for i in not_visited:
      if i not in not_adj[curr]:
        queue.append(i)

Run(0, sys.stdout)