import sys
import io
import os
from collections import defaultdict

def Run(input, output):
  
  readline = io.BytesIO(
      os.read(
        input, 
        os.fstat(input).st_size
      )
    ).readline
  ## input using readline()
  ## output using fout.write()

  N = int(readline())
  green_100 = [[0 for _ in range(N)] for __ in range(N)]
  green_u100 = [[0 for _ in range(N)] for __ in range(N)]

  ans = 0
  
  for i in range(N):
    row = [int(j) for j in readline().split()]
    for k in range(N):
      if row[k] == 100:
        green_100[i][k] = 1
        ans += 1
      elif row[k] < 100:
        green_u100[i][k] = 1
  
  make_prefix(green_100, N)
  make_prefix(green_u100, N)

  
  for i1 in range(N):
    for j1 in range(N):
      min_bad_j = N
      for i2 in range(i1, N):
        for j2 in range(j1, N):
          if i1 == i2 and j1 == j2:
            continue
          if j2 == min_bad_j:
            break
          if prefix_sum(green_100, i1, j1, i2, j2) >= 1:
            if prefix_sum(green_u100, i1, j1, i2, j2) == 0:
              ans += 1
            else:
              min_bad_j = j2
              break



  output.write("{}\n".format(ans))

def prefix_sum(prefixes, min_i, min_j, max_i,max_j):
  result = prefixes[max_i][max_j]
  if min_i > 0:
    result -= prefixes[min_i - 1][max_j]
    if min_j > 0:
      result += prefixes[min_i - 1][min_j - 1]
  if min_j > 0:
    result -= prefixes[max_i][min_j - 1]
  
  return result



def make_prefix(matrix, N):
  for i in range(N):
    row = matrix[i]
    for j in range(1, N):
      row[j] += row[j - 1]

  for i in range(1, N):
    for j in range(N):
      matrix[i][j] += matrix[i - 1][j]

def RunFileWrapper(input, output):
  fin = os.open(input, os.O_RDONLY)
  with open(output, 'w') as fout:
    Run(fin, fout)
  os.close(fin)

def RunIO():
  Run(0, sys.stdout)

RunIO()