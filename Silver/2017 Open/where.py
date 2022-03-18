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

  N = int(readline())
  image = [None for _ in range(N)]
  for i in range(N):
    image[i] = [chr(c) for c in readline().strip()]

  comp_dict = {}
  k = 0

  for i in range(N):
    for j in range(N):
      if (i, j) not in comp_dict:
        k += 1
        flood_fill(image, (i, j), comp_dict, k)
  
  pcl = set()

  for i in range(N): #minx
    for j in range(N): #miny
      for k in range(i, N): #maxx
        for l in range(j, N): #maxy
          if check(image, comp_dict, i, j, k, l):
            works = True
            for m, n, p, q in list(pcl):
              if i <= m <= k and i <= p <= k and j <= n <= l and j <= q <= l:
                pcl.remove((m, n, p, q))
              if m <= i <= p and m <= k <= p and n <= j <= q and n <= l <= q:
                works = False
                break
            if works:
              pcl.add((i, j, k, l))
            
  output.write("{}\n".format(len(pcl)))



def check(image, comp_dict, i, j, k, l):
  color_comp = defaultdict(set)
  for m in range(i, k + 1):
    for n in range(j, l + 1):
      color_comp[image[m][n]].add(comp_dict[(m, n)])
      if len(color_comp) > 2:
        return False
  if valid(color_comp):
    return True
  return False

def valid(color_comp):
  cond1 = False
  cond2 = False
  for i in color_comp:
    if len(color_comp[i]) == 1:
      cond1 = True
    if len(color_comp[i]) > 1:
      cond2 = True
  if cond1 and cond2:
    return True
  return False
  



def flood_fill(image, start, comp_dict, i):
  N = len(image)
  x, y = start
  queue = deque([start])

  while queue:
    x, y = queue.pop()
    if (x, y) in comp_dict:
      continue
    comp_dict[(x, y)] = i
    for dx, dy in [(0, -1), (0, 1), (1, 0), (-1, 0)]:
      x_new = x + dx
      y_new = y + dy
      if 0 <= x_new <= N - 1 and 0 <= y_new <= N - 1:
        image[x_new][y_new]
        if image[x_new][y_new] == image[x][y] and (x_new, y_new) not in comp_dict:
          queue.append((x_new, y_new))
        

def RunFileWrapper(input, output):
  fin = os.open(input, os.O_RDONLY)
  with open(output, 'w') as fout:
    stringio = io.StringIO()
    Run(fin, stringio)
    fout.write(stringio.getvalue())
  os.close(fin)

RunFileWrapper("where.in", "where.out")