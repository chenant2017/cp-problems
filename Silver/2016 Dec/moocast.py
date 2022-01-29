def flood_fill(start, adj):
  print("NEW START", start)
  visited = set()
  reached = 0
  queue = [start]
  while len(queue) > 0:
    curr = queue.pop(0)
    visited.add(curr)
    reached += 1
    print("reached", curr)
    for i in adj[curr]:
      if i not in visited:
        queue.append(i)
        visited.add(i)
  return reached

from collections import defaultdict
import math

def Run(input, output):
  with open(input, 'r') as fin, open(output, "w") as fout:
    N = int(fin.readline())
    cows = []
    adj = defaultdict(lambda: set())

    for i in range(N):
      x, y, p = (int(j) for j in fin.readline().split())
      cows.append((x, y, p))

    for point1 in range(N):
      x1, y1, p1 = cows[point1]
      for point2 in range(point1 + 1, N):
        x2, y2, p2 = cows[point2]

        dist = math.sqrt( (x1 - x2)**2 + (y1 - y2)**2 )

        if p1 >= dist:
          adj[point1].add(point2)
        if p2 >= dist:
          adj[point2].add(point1)
    
    print(adj)
    
    ans = 1

    for point in range(N):
      reached = flood_fill(point, adj)
      if reached > ans:
        ans = reached
    
    fout.write("{}\n".format(ans))


Run("moocast.in", "moocast.out")

