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
      add_cow(cows, x, y)
      for j in ((x,y), (x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)):
        if j in cows and len(cows[j]) == 1:
          floodfill(cows, j)
    output.write("{}\n".format(len(cows) - (i + 1)))

def floodfill(cows, point):
  queue = [point]
  while queue: 
    curr = queue.pop()
    if len(cows[curr]) != 1:
      continue
    x2, y2 = list(cows[curr])[0]

    if (x2, y2) not in cows:
      add_cow(cows, x2, y2)
  
    for i in ((x2, y2), (x2 - 1, y2), (x2 + 1, y2), (x2, y2 - 1), (x2, y2 + 1)):
      if i in cows and len(cows[i]) == 1:
        queue.append(i)

def add_cow(cows, x, y):
  cows[(x, y)] = {(x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)}
  for i in list(cows[(x, y)]):
    if i in cows:
      cows[(x, y)].remove(i)
      cows[i].remove((x, y))

      
Run(0, sys.stdout)