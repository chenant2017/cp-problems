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

  N, K = map(int, readline().split())
  diamonds = [None] * N
  for i in range(N):
    diamonds[i] = int(readline())
  
  diamonds = sorted(diamonds)

  intervals = [None] * N

  p2 = 0

  for p1 in range(N):
    while p2 < N - 1 and diamonds[p2] - diamonds[p1] <= K:
      p2 += 1
    if diamonds[p2] - diamonds[p1] > K:
      intervals[p1] = p2 - p1
    else:
      intervals[p1] = p2 - p1 + 1
  
  maxes = [None] * N
  
  maxes[-1] = intervals[-1]
  for i in range(N - 2, -1, -1):
    if intervals[i] > maxes[i + 1]:
      maxes[i] = intervals[i]
    else:
      maxes[i] = maxes[i + 1]
  
  ans = 0
  for i in range(N):
    test = intervals[i]
    if i + intervals[i] < N:
      test += maxes[i + intervals[i]]
    if test > ans:
      ans = test

  output.write("{}\n".format(ans))

def RunFileWrapper(input, output):
  fin = os.open(input, os.O_RDONLY)
  with open(output, 'w') as fout:
    stringio = io.StringIO()
    Run(fin, stringio)
    fout.write(stringio.getvalue())
  os.close(fin)

RunFileWrapper("diamond.in", "diamond.out")
