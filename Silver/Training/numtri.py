"""
ID: chenant1
LANG: PYTHON3
TASK: numtri
"""

def max_sum(row, place):
  if row == len(triangle) - 1:
    val_triangle[row][place] = triangle[row][place]
  elif val_triangle[row][place] is None:
    val_triangle[row][place] = triangle[row][place] + max(val_triangle[row + 1][place], val_triangle[row + 1][place + 1])

def overall_max():
  for r in range(len(triangle) - 1, -1, -1):
    for p in range(len(triangle[r])):
      max_sum(r, p)
      
with open("numtri.in", "r") as fin, open("numtri.out", "w") as fout:
  n_lines = int(fin.readline())
  triangle = [[int(i) for i in line.split()] for line in fin.readlines()]
  val_triangle = [[None for j in range(i)] for i in range(1, n_lines + 1)] 
  overall_max()
  fout.write(str(val_triangle[0][0]) + "\n")