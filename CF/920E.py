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
  N, M = map(int, readline().split())
  not_adj = [set() for _ in range(N + 1)]
  
  for i in range(M):
    x, y = map(int, readline().split())
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
  output.write(" ".join(map(str, sorted(sizes))))
  output.write("\n")

def dfs(not_adj, N, not_visited):
  for start in not_visited:
    break
  queue = deque([start])
  while queue:
    curr = queue.pop()
    if curr not in not_visited:
      continue
    not_visited.remove(curr)
    queue.extend(not_visited - not_adj[curr])

def RunIO():
  Run(0, sys.stdout)

RunIO()