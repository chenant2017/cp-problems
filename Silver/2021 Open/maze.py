import sys
import io
import os
from collections import defaultdict

def Run(input, output):
  with input as fin, output as fout:
    N = int(fin.readline())
    maze = [[None for __ in range(N)] for _ in range (N)]
    for i in range(N):
      for j in range(N):
        space = fin.read(3)
        maze[i][j] = space
        if space == "BBB":
          start = (i, j)
      fin.read(1)
    boards = set()
    dfs(maze, [["." for _ in range(3)] for __ in range(3)], set(), start, boards)
    fout.write("{}\n".format(len(boards)))

def dfs(maze, board, visited, start, boards):
  i, j = start
  visited.add((i, j, encode(board)))

  if maze[i][j] != "..." and maze[i][j] != "BBB":
    letter, k, l = maze[i][j]
    k = int(k) - 1
    l = int(l) - 1
    if board[k][l] == ".":
      board[k][l] = letter
      if won(board):
        boards.add(encode(board))
        board[k][l] = "."
        return 
      for a, b in [(i - 1, j), (i, j + 1), (i + 1, j), (i, j - 1)]:
        if (a, b, encode(board)) not in visited and maze[a][b] != "###":
          dfs(maze, board, visited, (a, b), boards)
      board[k][l] = "."
      return 
  for a, b in [(i - 1, j), (i, j + 1), (i + 1, j), (i, j - 1)]:
    if (a, b, encode(board)) not in visited and maze[a][b] != "###":
      dfs(maze, board, visited, (a, b), boards)
  return 

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

Run(sys.stdin, sys.stdout)
