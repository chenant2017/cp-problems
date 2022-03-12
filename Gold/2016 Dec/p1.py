import sys
import io
import os

def Run(input, output):
  
  readline = io.BytesIO(
      os.read(
        input, 
        os.fstat(input).st_size
      )
    ).readline
  
  N = int(readline())
  dists = [[None for _ in range(N)] for __ in range(N)]
  points = []
  for i in range(N):
    x, y = (int(j) for j in readline().split())
    points.append((x, y))
    for j in range(i):
      x2, y2 = points[j]
      dist = (x2 - x)**2 + (y2 - y)**2
      dists[i][j] = dist
      dists[j][i] = dist
  ans = bin_search(1, 2 * (25000**2), dists)
  output.write("{}\n".format(ans))

def bin_search(min_X, max_X, dists):
  N = len(dists)
  while max_X - min_X > 1: 
    mid = (min_X + max_X)//2
    visited = set()
    dfs_check(mid, dists, 0, visited)
    if len(visited) == N:
      max_X = mid
    else:
      min_X = mid
  return max_X

def dfs_check(X, dists, start, visited):
  visited.add(start)
  N = len(dists)
  for i in range(N):
    if i in visited or i == start:
      continue
    if dists[start][i] <= X:
      dfs_check(X, dists, i, visited)

def RunFileWrapper(input, output):
  fin = os.open(input, os.O_RDONLY)
  with open(output, 'w') as fout:
    Run(fin, fout)
  os.close(fin)

RunFileWrapper("moocast.in", "moocast.out")