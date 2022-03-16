import sys
import io
import os
from collections import defaultdict, deque

def Run(input, output):
  
  readline = io.BytesIO(
      os.read(
        input, 
        os.fstat(input).st_size
      )
    ).readline
  ## input using readline()
  ## output using fout.write()

  N, M = map(int, readline().split())
  switches = defaultdict(list)
  for m in range(M):
    x, y, a, b = map(int, readline().split())
    switches[(x, y)].append((a, b))
  
  lit = [[False for _ in range(N + 1)] for __ in range(N + 1)]
  lit[1][1] = True

  visited = set()

  total_lit = flood_fill(lit, visited, switches, 1,1)
  
  output.write("{}\n".format(total_lit))

def flood_fill(lit, visited, switches, x, y):
  lit_chng = 1
  queue = deque([(x, y)])

  while queue:
    x, y = queue.pop()
    
    if (x, y) in visited:
      continue

    visited.add((x, y))
    for x_adj, y_adj in switches[(x, y)]:
      if not lit[x_adj][y_adj]:
        lit[x_adj][y_adj] = True
        lit_chng += 1
        for x_, y_ in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
          if (x_adj + x_, y_adj + y_) in visited:
            queue.append((x_adj, y_adj))

    for x_, y_ in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
      if x_ == y_ and x_ == 0:
        continue
      x_adj = x + x_
      y_adj = y + y_
      if x_adj  == 0 or y_adj == 0:
        continue
      if x_adj  >= len(lit) or y_adj >= len(lit):
        continue

      if lit[x_adj][y_adj] and (x_adj, y_adj) not in visited:
        queue.append((x_adj, y_adj))

  return lit_chng
    

def RunFileWrapper(input, output):
  fin = os.open(input, os.O_RDONLY)
  with open(output, 'w') as fout:
    stringio = io.StringIO()
    Run(fin, stringio)
    fout.write(stringio.getvalue())
  os.close(fin)

RunFileWrapper("lightson.in", "lightson.out")