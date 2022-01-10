"""
ID: chenant1
LANG: PYTHON3
TASK: ttwo
"""
def move(matrix, pos):
  row, col, dir = pos
  #print(row, col)
  if dir == "N":
    if row - 1 < 0 or matrix[row - 1][col] == "*":
      return (row, col, "E")
    return (row - 1, col, "N")
  if dir == "E":
    if col + 1 > 9 or matrix[row][col + 1] == "*":
      return (row, col, "S")
    return (row, col + 1, "E")
  if dir == "S":
    if row + 1 > 9 or matrix[row + 1][col] == "*":
      return (row, col, "W")
    return (row + 1, col, "S")
  if dir == "W":
    if col - 1 < 0 or matrix[row][col - 1] == "*":
      return (row, col, "N")
    return (row, col - 1, "W")

with open("ttwo.in", "r") as fin, open("ttwo.out", "w") as fout:
  matrix = []
  lines = fin.readlines()
  for l in range(len(lines)):
    row = []
    string = lines[l].strip()
    for i in range(len(string)):
      if string[i] == "F":
        f_pos = (l, i, "N")
        row.append(".")
      elif string[i] == "C":
        c_pos = (l, i, "N")
        row.append(".")
      else:
        row.append(string[i])
    matrix.append(row)
  
  intersect = set()
  solution = False
  f_path = {f_pos}
  c_path = {c_pos}
  f_loop = False
  c_loop = False
  f_i = None
  c_i = None
  c_pos_ = None
  f_pos_ = None

  moves = 0

  while True:
    #print(moves)

    f_pos = move(matrix, f_pos)
    c_pos = move(matrix, c_pos)

    moves += 1

    if f_pos[0] == c_pos[0] and f_pos[1] == c_pos[1]:
      solution = True
      break

    if not f_loop:
      if f_pos in f_path:
        f_loop = True
      else:
        f_path.add(f_pos)

    if not c_loop:
      if c_pos in c_path:
        c_loop = True
      else:
        c_path.add(c_pos)

    if f_loop and c_loop:
      if f_pos_ is None and c_pos_ is None:
        f_pos_ = f_pos
        c_pos_ = c_pos
        continue

    if f_pos_ is not None and f_pos == f_pos_ and c_pos_ is not None and c_pos == c_pos_:
      break

  if solution:
    fout.write(str(moves) + "\n")
  else:
    fout.write("0\n")
  

  
  


  
  

  

  
  
