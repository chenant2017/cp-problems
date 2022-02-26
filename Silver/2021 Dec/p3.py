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
  intervals = []
  
  for n in range(N):
    a, b = (int(i) for i in readline().split())
    intervals.append((a, b))
  
  starts = [0] * (2*M + 1)
  ends = [0] * (2*M + 1)
  
  for i in range(len(intervals)):
    for j in range(i, len(intervals)):
      ai, bi = intervals[i]
      aj, bj = intervals[j]
      starts[ai + aj] += 1
      ends[bi + bj] += 1
      if i != j:
        starts[ai + aj] += 1
        ends[bi + bj] += 1
  
  count = 0
  for i in range(2*M + 1):
    count += starts[i]
    output.write("{}\n".format(count))
    count -= ends[i]
  
Run(0, sys.stdout)