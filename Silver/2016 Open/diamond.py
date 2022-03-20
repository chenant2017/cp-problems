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

  intervals = [0] * N

  p2 = 0

  for p1 in range(N):
    while p2 < N - 1 and diamonds[p2] - diamonds[p1] <= K:
      p2 += 1
    if diamonds[p2] - diamonds[p1] > K:
      intervals[p1] = p2 - p1
    else:
      intervals[p1] = p2 - p1 + 1
      break
  
  intervals = sorted(intervals, reverse=True)

  if len(intervals) >= 2:
    ans = intervals[0] + intervals[1]
  else:
    ans = intervals[0]

  output.write("{}\n".format(ans))

def RunFileWrapper(input, output):
  fin = os.open(input, os.O_RDONLY)
  with open(output, 'w') as fout:
    stringio = io.StringIO()
    Run(fin, stringio)
    fout.write(stringio.getvalue())
  os.close(fin)

RunFileWrapper("diamond.in", "diamond.out")
