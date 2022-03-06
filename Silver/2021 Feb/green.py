import sys
import io
import os
import copy

def Run(input, output):
  
  readline = io.BytesIO(
      os.read(
        input, 
        os.fstat(input).st_size
      )
    ).readline

  N = int(readline())
  grass = [None for _ in range(N)]
  for i in range(N):
    grass[i] = [int(i) for i in readline().split()]
  prefix_100 = get_prefix(grass, N, 100)
  prefix_101 = get_prefix(grass, N, 101)
  rect_100 = get_n_rectangles(prefix_100, N)
  rect_101 = get_n_rectangles(prefix_101, N)
  output.write("{}\n".format(rect_100 - rect_101))

def get_prefix(matrix, N, threshold):
  prefix = copy.deepcopy(matrix)
  for i in range(N):
    if prefix[i][-1] >= threshold:
      prefix[i][-1] = 1
    else:
      prefix[i][-1] = 0
    for j in range(N - 2, -1, -1):
      if prefix[i][j] >= threshold:
        prefix[i][j] = prefix[i][j + 1] + 1
      else:
        prefix[i][j] = 0
  return prefix

def get_n_rectangles(prefix, N):
  total = 0
  for i in range(N):
    for j in range(N):
      min = N
      for k in range(i, N):
        if prefix[k][j] < min:
          min = prefix[k][j]
        total += min
  return total

Run(0, sys.stdout)