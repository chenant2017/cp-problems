import sys

def get_added_cows(cows, i):
  cows_ = set(cows[:i])
  adjacent = {}
  for c in cows_:
    adjacent[c] = set()
    for p in get_adjacent_points(c):
      if p in cows_:
        adjacent[c].add(p)
  return get_result(cows_, adjacent, 0)

def get_result(cows_, adjacent, n):
  b = True
  for c in list(adjacent):
    if len(adjacent[c]) == 3:
      b = False
      for p in get_adjacent_points(c):
        if p not in adjacent[c]:
          if p not in adjacent:
            adjacent[p] = set()
            cows_.add(p)
            n += 1
          for q in get_adjacent_points(p):
            if q in cows_:
              adjacent[q].add(p)
              adjacent[p].add(q)
          break
  if b:
    return n
  else:
    return get_result(cows_, adjacent, n)

def get_adjacent_points(c):
  return ((c[0] + 1, c[1]), (c[0], c[1] + 1), (c[0] - 1, c[1]), (c[0], c[1] - 1))

with sys.stdin as fin, sys.stdout as fout:
  N = int(fin.readline())
  cows = [tuple(int(a) for a in l.split()) for l in fin.readlines()]
  if N < 4:
    for i in range(1, N + 1):
      fout.write("0\n")
  else:
    for a in range(3):
      fout.write("0\n")
    for i in range(4, N + 1):
      fout.write(str(get_added_cows(cows, i)) + "\n")
  

  