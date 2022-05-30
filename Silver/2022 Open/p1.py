import sys
from collections import deque

def Run(fin, fout):
  readline = fin.readline
  N = int(readline())
  to = [None] * (N + 1)
  from_ = [set() for _ in range(N + 1)]

  for i in range(1, N + 1):
    a, v = map(int, readline().split())
    to[i] = (a, v)
    from_[a].add((i, v))

  visited = set()
  ans = 0

  for i in range(1, N + 1):
    if i in visited:
      continue
    loop = find_loop(to, from_, i)
    totals = []
    for j in loop:
      total = dfs(to, from_, visited, loop, j)
      totals.append(total)
    ans += sum(totals) - min(totals)
    
    
  fout.write("{}\n".format(ans))
  
  

def dfs(to, from_, visited, loop, start): #start = node in loop
  sum = to[start][1]
  queue = deque([(start, 0)])

  while queue:
    curr, v = queue.pop()
    if curr in visited:
      continue 

    visited.add(curr)
    sum += v

    for i, v in from_[curr]:
      if i not in loop:
        queue.append((i, v))
  
  return sum

def find_loop(to, from_, start):
  last_seen = [None] * len(to)
  path = []
  i = 0

  curr = start
  while True:
    if last_seen[curr] is not None:
      return set(path[last_seen[curr]:])
    path.append(curr)
    last_seen[curr] = i
    curr = to[curr][0]
    i += 1
    
Run(sys.stdin, sys.stdout)