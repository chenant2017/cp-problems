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
  stacks = [0] * (N + 1)

  starts = defaultdict(int)
  ends = defaultdict(int)


  for k in range(K):
    a, b = map(int, readline().split())
    starts[a] += 1
    ends[b] += 1
  
  value = 0
  for i in range(1, N + 1):
    value += starts[i]
    stacks[i] = value
    value -= ends[i]
  
  stacks = sorted(stacks)
  output.write("{}\n".format(stacks[len(stacks)//2]))

Run(0, sys.stdout)