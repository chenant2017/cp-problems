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

  cows = set()
  roads = set()

  N, K, R = map(int, readline().split())
  for i in range(R):
    r, c, r2, c2 = map(int, readline().split())
    roads.add((r, c, r2, c2))
  for i in range(K):
    cow = tuple(map(int, readline().split()))
    cows.add(cow)

  visited = set()
  pairs = 0

  for i in cows:
    if i not in visited:
      cows_met = flood_fill(cows, i, visited, roads, N)
      pairs += (cows_met) * (cows_met - 1) // 2
  
  ans = (N) * (N - 1) // 2 - pairs

  output.write("{}\n".format(ans))


  
  

def flood_fill(cows, start, visited, roads, N):
  cows_met = 0
  queue = deque([start])
  while queue:
    curr = queue.pop()
    if curr in visited:
      continue
    visited.add(curr)
    if curr in cows:
      cows_met += 1
    r, c = curr
    for dr, dc in ((0, 1), (0, -1), (-1, 0), (1, 0)):
      r2 = r + dr
      c2 = c + dc 
      if 1 <= r2 <= N and 1 <= c2 <= N:
        if (r, c, r2, c2) not in roads and (r2, c2, r, c) not in roads:
          queue.append((r2, c2))
  return cows_met
      
def RunFileWrapper(input, output):
  fin = os.open(input, os.O_RDONLY)
  with open(output, 'w') as fout:
    stringio = io.StringIO()
    Run(fin, stringio)
    fout.write(stringio.getvalue())
  os.close(fin)

RunFileWrapper("countcross.in", "countcross.out")