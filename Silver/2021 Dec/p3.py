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

  a_ = {}
  b_ = {}
  
  for n in range(N):
    a, b = (int(i) for i in readline().split())
    if a in a_:
      a_[a] += 1
    else:
      a_[a] = 1
    if b in b_:
      b_[b] += 1
    else:
      b_[b] = 1
  
  starts = [0] * (2*M + 1)
  ends = [0] * (2*M + 1)
  
  for i, ai in a_.items():
    for j, aj in a_.items():
      start = i + j
      starts[start] += ai * aj
  
  for i, bi in b_.items():
    for j, bj in b_.items():
      end = i + j
      ends[end] += bi * bj
  
  count = 0
  for i in range(2*M + 1):
    count += starts[i]
    output.write("{}\n".format(count))
    count -= ends[i]

Run(0, sys.stdout)