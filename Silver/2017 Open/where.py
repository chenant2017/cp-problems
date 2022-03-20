import sys
import io
import os
from collections import defaultdict, deque

def check(image, comp_dict, i, j, k, l):
  color_comp = defaultdict(set)
  for m in range(i, k + 1):
    for n in range(j, l + 1):
      color_comp[image[m][n]].add(comp_dict[(m, n)])
      if len(color_comp) > 2:
        return False
  if len(color_comp) < 2:
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
  

def flood_fill(image, start, comp_dict, a, i, j, k, l):
  N = len(image)
  queue = deque([start])

  while queue:
    x, y = queue.pop()
    if (x, y) in comp_dict:
      continue
    comp_dict[(x, y)] = a
    for dx, dy in [(0, -1), (0, 1), (1, 0), (-1, 0)]:
      x_new = x + dx
      y_new = y + dy
      if i <= x_new <= k and j <= y_new <= l:
        if image[x_new][y_new] == image[x][y] and (x_new, y_new) not in comp_dict:
          queue.append((x_new, y_new))
        

def RunFileWrapper(input, output):
  fin = os.open(input, os.O_RDONLY)
  with open(output, 'w') as fout:
    stringio = io.StringIO()
    Run(fin, stringio)
    fout.write(stringio.getvalue())
  os.close(fin)

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

  pcl = set()

  a = 0

  for i in range(N): #minx
    for j in range(N): #miny
      for k in range(i, N): #maxx
        for l in range(j, N): #maxy
          comp_dict = {}
          for m in range(i, k + 1):
            for n in range(j, l + 1):
              if (m, n) not in comp_dict:
                a += 1
                flood_fill(image, (m, n), comp_dict, a, i, j, k, l)
          if check(image, comp_dict, i, j, k, l):
            pcl.add((i, j, k, l))
  
  l_pcl = list(pcl)

  for i in range(len(l_pcl)):
    if l_pcl[i] not in pcl:
      continue
    m, n, p, q = l_pcl[i] 
    for j in range(len(l_pcl)):
      if i == j:
        continue
      if l_pcl[j] not in pcl:
        continue
      r, s, t, u = l_pcl[j]
      if m <= r <= p and m <= t <= p and n <= s <= q and n <= u <= q:
        pcl.remove((r, s, t, u))
            
  output.write("{}\n".format(len(pcl)))

RunFileWrapper("where.in", "where.out")