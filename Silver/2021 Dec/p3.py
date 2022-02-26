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
  ## input using readline()
  ## output using fout.write()

  N, M = (int(i) for i in readline().split())
  counts = [0] * (2*M + 1)
  intervals = []
  
  for n in range(N):
    a, b = (int(i) for i in readline().split())
    intervals.append((a, b))
  
  for i in range(len(intervals)):
    for j in range(i, len(intervals)):
      ai, bi = intervals[i]
      aj, bj = intervals[j]
      for k in range(ai + aj, bi + bj + 1):
        counts[k] += 1
        if i != j:
          counts[k] += 1
  
  for i in counts:
    output.write("{}\n".format(i))

Run(0, sys.stdout)