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

  N = int(readline())
  xg, yg = (int(i) for i in readline().split())

  moves1 = [tuple(int(j) for j in readline().split()) for i in range(N//2)]
  moves2 = [tuple(int(j) for j in readline().split()) for i in range(N//2, N)]
  
  counts1 = defaultdict(int)
  counts2 = defaultdict(int)

  get_combos(moves1, 0, 0, 0, counts1, 0)
  get_combos(moves2, 0, 0, 0, counts2, 0)

  #print(counts1)
  #print(counts2)

  for K in range(1, N + 1):
    ans = 0

    for m, x, y in counts1:
      if (K - m, xg - x, yg - y) in counts2:
        ans += counts1[m, x, y] * counts2[K - m, xg - x, yg - y]

    output.write("{}\n".format(ans))

def get_combos(moves, i, sx, sy, counts, m):
  if i == len(moves):
    counts[(m, sx, sy)] += 1
  else:
    x, y = moves[i]
    sx_ = sx + x
    sy_ = sy + y
    get_combos(moves, i + 1, sx, sy, counts, m)
    get_combos(moves, i + 1, sx_, sy_, counts, m + 1)
  return counts

Run(0, sys.stdout)