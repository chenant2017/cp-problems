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

  C, N = map(int, readline().split())

  times = []
  intervals = []

  for c in range(C):
    times.append(int(readline()))
  
  for n in range(N):
    a, b = map(int, readline().split())
    intervals.append((a, b))
  
  times = sorted(times)
  intervals = sorted(intervals, key=lambda x: x[1])

  ans = 0
  visited = set()

  for t in range(C):
    I = 0
    while I < len(intervals):
      if I in visited:
        I += 1
        continue
      a, b = intervals[I] 
      if a <= times[t] <= b:
        ans += 1
        visited.add(I)
        break
      else:
        I += 1
  
  output.write("{}\n".format(ans))
      

def RunFileWrapper(input, output):
  fin = os.open(input, os.O_RDONLY)
  with open(output, 'w') as fout:
    stringio = io.StringIO()
    Run(fin, stringio)
    fout.write(stringio.getvalue())
  os.close(fin)

RunFileWrapper("helpcross.in", "helpcross.out")