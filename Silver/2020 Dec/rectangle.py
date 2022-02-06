import sys
from collections import defaultdict

def find_rects(matrix, points, p1, p2):
  #print("***", points[p1], points[p2])

  x1, y1 = points[p1]
  x2, y2 = points[p2]
  Y = max(y1, y2)
  y = min(y1, y2)
  X = max(x1, x2)
  x = min(x1, x2)

  num_above = matrix[x][Y]
  if y >= 1:
    num_above -= matrix[x][y - 1]
 
  num_below = matrix[-1][Y]
  if y >= 1:
    num_below -= matrix[-1][y - 1]
    if X >= 1:
      num_below += matrix[X - 1][y - 1]
  if X >= 1:
    num_below -= matrix[X - 1][Y]
  
  #print(num_above, num_below)
  
  return (num_above) * (num_below)

def make_prefix(matrix):
  for i in range(len(matrix)):
    for j in range(1, len(matrix[0])):
      matrix[i][j] += matrix[i][j - 1]
  
  for j in range(len(matrix[0])):
    for i in range(1, len(matrix)):
      matrix[i][j] += matrix[i - 1][j]

from collections import defaultdict
def Run(input, output):
  with input as fin, output as fout:
    N = int(fin.readline())
    matrix = [[0] * N for i in range(N)]
    points = []
    
    for i in range(N):
      x, y = (int(i) for i in fin.readline().split())
      points.append([x, y])
    
    points_x = sorted(points)
    points_y = sorted(points, key=lambda x: x[1])

    for i in points:
      i[0] = points_x.index(i)
      i[1] = points_y.index(i)
      matrix[i[0]][i[1]] = 1

    make_prefix(matrix)

    total = 1 + N #empty subsets and subsets w/ 2 points

    for i in range(N - 1):
      for j in range(i + 1, N):
        rects = find_rects(matrix, points, i, j)
        total += rects
        
    fout.write("{}\n".format(total))


Run(sys.stdin, sys.stdout)