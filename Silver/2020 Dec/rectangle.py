import sys
from collections import defaultdict

def find_rects(points, p1, p2):
  above = 0
  below = 0
  x1, y1 = points[p1]
  x2, y2 = points[p2]
  for p in range(p1 + 1, p2):
    x3, y3 = points[p]
    if y3 > max(y1, y2):
      above += 1
    elif y3 < min(y1, y2):
      below += 1
  return (above + 1) * (below + 1)

def Run(input, output):
  with input as fin, output as fout:
    N = int(fin.readline())
    points = []
    for i in range(N):
      x, y = (int(i) for i in fin.readline().split())
      points.append((x, y))
    points = sorted(points)
    total = 1 + N
    for i in range(len(points) - 1):
      for j in range(i + 1, len(points)):
        #print(points[i], points[j])
        rects = find_rects(points, i, j)
        total += rects
        #print(rects)
    #print(total)
    fout.write("{}\n".format(total))


Run(sys.stdin, sys.stdout)