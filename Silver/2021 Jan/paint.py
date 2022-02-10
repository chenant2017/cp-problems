import sys
import io
import os
from collections import defaultdict

def get_strokes(fence):
  add_stroke = [True] * 26 
  add_stroke[fence[0] - ord("A")] = False
  N = len(fence)
  strokes = [1] * N
  
  for i in range(1, N):
    strokes[i] = strokes[i - 1]
    asi = fence[i] - ord("A")
    if add_stroke[asi]:
      strokes[i] += 1
      add_stroke[asi] = False
    for j in range(len(add_stroke)):
      if fence[i] < (j + ord("A")):
        add_stroke[j] = True

  return strokes

def Run(input, output):
  
  readline = io.BytesIO(
      os.read(
        input, 
        os.fstat(input).st_size
      )
    ).readline

  N, Q = (int(i) for i in readline().split())
  fence = readline().strip()

  strokes = get_strokes(fence)
  strokes_r = get_strokes(fence[::-1])[::-1]

  for i in range(Q):
    start, end = (int(j) for j in readline().split())
    ans = 0
    if start - 2 >= 0:
      ans += strokes[start - 2]
    if end <= N - 1:
      ans += strokes_r[end]
    output.write("{}\n".format(ans))

def RunFileWrapper(input, output):
  fin = os.open(input, os.O_RDONLY)
  with open(output, 'w') as fout:
    Run(fin, fout)
  os.close(fin)

def RunIO():
  Run(0, sys.stdout)

RunIO()