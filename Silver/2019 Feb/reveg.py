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
  S_adj = defaultdict(list)
  D_adj = defaultdict(list)

  N, M = map(int, readline().split()) #pastures, cows
  for m in range(M):
    sd, p1, p2 = readline().split()
    p1 = int(p1)
    p2 = int(p2)
    if sd == "S":
      S_adj[p1].append(p2)
      S_adj[p2].append(p1)
    else:
      D_adj[p1].append(p2)
      D_adj[p2].append(p1)
  
  visited = [None] * (N + 1)
  comps = 0

  for i in range(1, N+1):
    if visited[i] is None:
      valid = False
      valid = dfs(S_adj, D_adj, i, visited)
      if valid:
        comps += 1
      else:
        output.write("0\n")
        break
  if valid:
    output.write("{}\n".format(10**(comps)))
      

def dfs(S_adj, D_adj, start, visited):
  queue = deque([(start, 1, "S")])
  while queue:
    curr, prev, sd = queue.pop()
    if sd == "S":
      if visited[curr] is None:
        visited[curr] = prev
      elif visited[curr] == prev:
        continue
      else:
        return False
    else:
      if visited[curr] is None:
        visited[curr] = prev
      elif visited[curr] != prev:
        continue
      else:
        return False
    
    for i in S_adj[curr]:
      queue.append(i, curr, "S")
    for i in D_adj[curr]:
      queue.append((i, curr, "D"))
  return True

def RunFileWrapper(input, output):
  fin = os.open(input, os.O_RDONLY)
  with open(output, 'w') as fout:
    stringio = io.StringIO()
    Run(fin, stringio)
    fout.write(stringio.getvalue())
  os.close(fin)

RunFileWrapper("revegetate.in", "revegetate.out")