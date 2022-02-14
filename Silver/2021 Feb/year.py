import sys
import io
import os
import heapq
import math

def Run(input, output):
  
  readline = io.BytesIO(
      os.read(
        input, 
        os.fstat(input).st_size
      )
    ).readline
  ## input using readline()
  ## output using fout.write()

  N, K = (int(i) for i in readline().split())
  jumps = []
  heapq.heapify(jumps)
  
  cows = [int(readline()) for i in range(N)]
  cows.append(0)
  
  cows = sorted(cows, reverse=True)
  
  curr = cows[0]
  ans = 12 * math.ceil(curr / 12)

  for i in range(N):
    next = cows[i + 1]
    dist = (curr - curr % 12) - (12 * math.ceil(next / 12))
    if dist >= 12:
      heapq.heappush(jumps, -1 * (dist - dist % 12))
    curr = next
  
  for i in range(K - 1):
    if i == len(jumps) - 1:
      break
    else: 
      ans -= -1 * heapq.heappop(jumps)

  output.write("{}\n".format(ans))

    

def RunFileWrapper(input, output):
  fin = os.open(input, os.O_RDONLY)
  with open(output, 'w') as fout:
    Run(fin, fout)
  os.close(fin)

def RunIO():
  Run(0, sys.stdout)

RunIO()