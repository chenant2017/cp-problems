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

  N = int(readline())
  counts = [None] * N
  h, p, s = 0, 0, 0
  for i in range(N):
    c = readline().strip()
    if c == b"S":
      s += 1
    elif c == b"P":
      p += 1
    else:
      h += 1
    counts[i] = (h, p, s)
  
  ans = max(counts[-1])

  for i in range(N):
    h1, p1, s1 = counts[i]
    h2, p2, s2 = (counts[-1][j] - counts[i][j] for j in range(3))
    result = max(h1, p1, s1) + max(h2, p2, s2)
    if result > ans:
      ans = result
  
  output.write("{}\n".format(ans))

def RunFileWrapper(input, output):
  fin = os.open(input, os.O_RDONLY)
  with open(output, 'w') as fout:
    stringio = io.StringIO()
    Run(fin, stringio)
    fout.write(stringio.getvalue())
  os.close(fin)

RunFileWrapper("hps.in", "hps.out")