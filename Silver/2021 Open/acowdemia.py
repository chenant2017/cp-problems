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
  
  N, K, L = (int(i) for i in readline().split())
  citations = [int(i) for i in readline().split()]
  citations = sorted(citations, reverse=True)
  
  h = bin_search(1, citations[0] + K*L + 1, K, L, citations)

  output.write("{}\n".format(h))

def bin_search(min_h, max_h, K, L, citations):
  while max_h - min_h > 1:
    mid = (min_h + max_h)//2
    if check(mid, K, L, citations):
      min_h = mid
    else:
      max_h = mid
  return min_h

def check(h, K, L, citations):
  cited = 0
  valid = 0
  for i in citations:
    if i >= h:
      valid += 1
    if i < h and h - i <= K:
      cited += h - i
      valid += 1
    if valid >= h and cited <= K*L:
      return True
  return False

Run(0, sys.stdout)
