import sys

def Run(input, output):
  with input as fin, output as fout:
    N, M = (int(i) for i in fin.readline().split()) #cows, cereals
    adj = {}
    cows = [None]
    for i in range(1, N + 1):
      a, b = (int(j) for j in fin.readline().split())
      cows.append((a, b))
      adj[i] = []
      for j in adj:
        if cows[j][0] == a or cows[j][1] == a or cows[j][0] == b:
          adj[j].append(i)
          adj[i].append(j)
    
    final_filled = 0
    final_path = []
    visited = set()
    for i in range(1, N + 1):
      if i not in visited:
        filled, path = dfs(cows, i, adj, M, visited)
        final_filled += filled
        final_path += path

    fout.write("{}\n".format(N - final_filled))
    for i in final_path:
      fout.write("{}\n".format(i))
      


from collections import deque

def dfs(cows, start, adj, M, visited): #start is the cow int
  N = len(cows) - 1
  path = []
  taken = [False] * (M + 1)
  queue = deque([start])
  filled = 0

  while queue:
    curr = queue.pop()
    if curr in visited:
      continue
    visited.add(curr)
    path.append(curr)
    first, second = cows[curr]

    stop = False

    if taken[first]:
      if taken[second]:
        stop = True
      else:
        taken[second] = True
        filled += 1
    else:
      taken[first] = True
      filled += 1
    
    if not stop:
      for i in adj[curr]:
        if i not in visited:
          queue.append(i)

  return filled, path

  
Run(sys.stdin, sys.stdout)



