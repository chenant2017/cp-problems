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
    
    comps = get_comps(adj)
    
    final_filled = 0
    final_path = []
    for i in comps:
      max_filled = -1
      max_path = None
      for j in i:
        max_filled, max_path = dfs(cows, j, adj, max_filled, max_path, M)
      final_filled += max_filled
      final_path += max_path

    rem = set(range(1, N + 1))
    for i in final_path:
      if i in rem:
        rem.remove(i)
    
    for i in rem:
      final_path.append(i)
    
    fout.write("{}\n".format(N - final_filled))
    for i in final_path:
      fout.write("{}\n".format(i))
      

from collections import deque

def dfs(cows, start, adj, max_filled, max_path, M): #start is the cow int
  N = len(cows) - 1
  path = []
  taken = [False] * (M + 1)
  queue = deque([(start, path)])
  visited = set()

  while queue:
    curr, path = queue.pop()
    visited.add(curr)
    first, second = cows[curr]

    stop = False

    if taken[first]:
      if taken[second]:
        filled = len(path)
        if filled > max_filled:
          max_filled = filled
          max_path = path
        stop = True
      else:
        path.append(curr)
        taken[second] = True
    else:
      path.append(curr)
      taken[first] = True
    
    if not stop:
      count = 0
      for i in adj[curr]:
        if i not in visited:
          queue.append((i, path))
          count += 1
      if count == 0:
        filled = len(path)
        if filled > max_filled:
          max_filled = filled
          max_path = path
  return max_filled, max_path

def get_comps(adj):
  visited = set()
  comps = []
  for i in adj:
    if i not in visited:
      comp = get_comp(i, adj, visited)
      comps.append(comp)
  return comps

def get_comp(start, adj, visited):
  comp = set()
  queue = deque([start])
  while queue:
    curr = queue.popleft()
    comp.add(curr)
    visited.add(curr)
    for i in adj[curr]:
      if i not in comp:
        queue.append(i)
  return comp
  
Run(sys.stdin, sys.stdout)



