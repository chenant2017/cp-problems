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


  for k in range(K):
    a, b = map(int, readline().split())
    stacks[a] += 1
    if b + 1 <= N:
      stacks[b + 1] -= 1
  
  for i in range(1, N + 1):
    stacks[i] += stacks[i - 1]
  
  stacks = sorted(stacks)
  output.write("{}\n".format(stacks[len(stacks)//2]))
  
Run(0, sys.stdout)