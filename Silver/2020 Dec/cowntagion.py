import math
def dfs_iter(adj):
  days = 0
  queue = [1]
  visited = set()

  while queue:
    curr = queue.pop(-1)
    visited.add(curr)
    children = len(adj[curr])
    for i in adj[curr]:
      if i not in visited:
        queue.append(i)
      else:
        children -= 1

    days += math.ceil(math.log(children + 1, 2)) + children
  return days
    
  
  
    
    
import sys
from collections import defaultdict
def Run(input, output):
  with input as fin, output as fout:
    N = int(fin.readline())
    adj = defaultdict(set)
    for i in range(N - 1):
      a, b = (int(i) for i in fin.readline().split())
      adj[a].add(b)
      adj[b].add(a)
    
    ans = dfs_iter(adj)
    fout.write("{}\n".format(ans))
    

Run(sys.stdin, sys.stdout)