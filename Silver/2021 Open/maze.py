import sys
import io
import os
from collections import defaultdict

def Run(input, output):
  with open(input, 'r') as fin, open(output, "w") as fout:
    N = int(fin.readline())
    maze = [[None for __ in range(N)] for _ in range (N)]
    for i in range(N):
      for j in range(N):
        space = fin.read(3)
        maze[i][j] = space
        if space == "BBB":
          start = (i, j)
      fin.read(1)
    for m in maze:
      print(m)
    ans = dfs(maze, [["." for _ in range(3)] for __ in range(3)], set(), start)
    print("asdlkfj", ans)

def dfs(maze, board, visited, start):
  result = 0
  i, j = start
  visited.add((i, j, encode(board)))
  print(i, j)
  for b in board:
    print(b)
  print("-" * 15)

  if maze[i][j] != "..." and maze[i][j] != "BBB":
    letter, k, l = maze[i][j]
    k = int(k) - 1
    l = int(l) - 1
    if board[k][l] == ".":
      board[k][l] = letter
      if won(board):
        board[k][l] = "."
        return result + 1
      for a, b in [(i - 1, j), (i, j + 1), (i + 1, j), (i, j - 1)]:
        if (a, b, encode(board)) not in visited and maze[a][b] != "###":
          result += dfs(maze, board, visited, (a, b))
      board[k][l] = "."
  else:
    for a, b in [(i - 1, j), (i, j + 1), (i + 1, j), (i, j - 1)]:
      if (a, b, encode(board)) not in visited and maze[a][b] != "###":
        result += dfs(maze, board, visited, (a, b))
  return result

def won(board):
  for i in range(3):
    if board[i] == ["M", "O", "O"] or board[i] == ["O", "O", "M"]:
      return True
  for i in range(3):
    col = [board[j][i] for j in range(3)]
    if col == ["M", "O", "O"] or col == ["O", "O", "M"]:
      return True
  diag1 = [board[0][0], board[1][1], board[2][2]] 
  diag2 = [board[2][0], board[1][1], board[0][2]]
  for i in (diag1, diag2):
    if i == ["M", "O", "O"] or i == ["O", "O", "M"]:
      return True
  return False

def encode(board):
  total = 0
  power = 8
  for i in range(3):
    for j in range(3):
      if board[i][j] == "O":
        total += 3**power
      elif board[i][j] == "M":
        total += 2 * 3**power
      power -= 1
  return total

def RunFileWrapper(input, output):
  fin = os.open(input, os.O_RDONLY)
  with open(output, 'w') as fout:
    Run(fin, fout)
  os.close(fin)

def RunIO():
  Run(0, sys.stdout)

# RunIO()
Run("fin", "fout")