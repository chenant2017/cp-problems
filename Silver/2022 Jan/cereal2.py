import sys
from collections import deque

def Run(input, output):
  with input as fin, output as fout:
    N, M = (int(i) for i in fin.readline().split()) #cows, cereals
    cereals = {}
    cows = [None]
    for i in range(1, N + 1):
      a, b = (int(j) for j in fin.readline().split())
      cows.append((a, b))
      if a in cereals:
        cereals[a].add(i)
      else:
        cereals[a] = {i}
      if b in cereals:
        cereals[b].add(i)
      else:
        cereals[b] = {i}
    
    final_filled = 0
    final_path = deque([])
    visited = set()

    queue = deque([])

    for i in range(1, N + 1):
      if i not in visited:
        start = get_start(cows, i, cereals, M)
        queue.append(start)
        final_filled = dfs(cows, start, cereals, M, visited, final_filled, final_path, queue)

    fout.write("{}\n".format(N - final_filled))
    for i in final_path:
      fout.write("{}\n".format(i))
      

def dfs(cows, start, cereals, M, visited, filled, path, queue): #start is the cow int
  N = len(cows) - 1
  taken = [False] * (M + 1)

  while queue:
    curr = queue.pop()
    if curr in visited:
      continue
    visited.add(curr)
    path.append(curr)
    first, second = cows[curr]

    if taken[first]:
      if not taken[second]:
        taken[second] = True
        filled += 1
        for i in cereals[second]:
          if i not in visited:
            queue.append(i)
      else:
        continue
    else:
      taken[first] = True
      filled += 1
      for i in cereals[first]:
        if i not in visited:
          queue.append(i)
  return filled

def get_start(cows, start, cereals, M):
  N = len(cows) - 1
  queue = deque([start])
  visited = set()
  taken = [False] * (M + 1)

  while queue:
    curr = queue.pop()
    if curr in visited:
      continue
    visited.add(curr)
    first, second = cows[curr]

    if taken[first] and taken[second]:
      return curr
    else:
      taken[first] = True
      taken[second] = True

    for i in cereals[first] | cereals[second]:
      if i not in visited:
        queue.append(i)
  return start

Run(sys.stdin, sys.stdout)

