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
  ## output using output.write()

  N = int(readline())
  cows = {}

  for i in range(N):
    x, y = (int(j) for j in readline().split())
    if (x, y) not in cows:
      for j in add_cow(cows, x, y):
        floodfill(cows, j)
    output.write("{}\n".format(len(cows) - (i + 1)))

def floodfill(cows, point):
  queue = [point]
  while queue: 
    curr = queue.pop()
    if cows[curr] != 1:
      continue
    x, y = curr
    for i in ((x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)):
      if i not in cows:
        for j in add_cow(cows, i[0], i[1]):
          queue.append(j)
        break

def add_cow(cows, x, y):
  to_flood = []
  count = 0
  for i in ((x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)):
    if i in cows:
      cows[i] -= 1
      if cows[i] == 1:
        to_flood.append(i)
    else:
      count += 1
  if count == 1:
    to_flood.append((x, y))
  cows[(x, y)] = count
  return to_flood

def RunFileWrapper(input, output):
  fin = os.open(input, os.O_RDONLY)
  with open(output, 'w') as fout:
    Run(fin, fout)
  os.close(fin)

def RunIO():
  Run(0, sys.stdout)

RunIO()