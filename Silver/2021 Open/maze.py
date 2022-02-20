import sys

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
    dfs(maze, [["." for _ in range(3)] for __ in range(3)], set(), start, boards, 0)
    fout.write("{}\n".format(len(boards)))

def dfs(maze, board, visited, start, boards, encoded):
  i, j = start
  visited.add((i, j, encoded))
  a = 0
  if maze[i][j] != "..." and maze[i][j] != "BBB":
    letter, k, l = maze[i][j]
    k = int(k) - 1
    l = int(l) - 1
    if board[k][l] == ".":
      board[k][l] = letter
      if letter == "O":
        a = 3 ** (k * 3 + l)
      else:
        a = 2 * 3 ** (k * 3 + l)
      encoded += a
      if won(board, k, l):
        boards.add(encoded)
        board[k][l] = "."
        encoded -= a
        return 
      for a, b in [(i - 1, j), (i, j + 1), (i + 1, j), (i, j - 1)]:
        if (a, b, encoded) not in visited and maze[a][b] != "###":
          dfs(maze, board, visited, (a, b), boards, encoded)
      board[k][l] = "."
      encoded -= a
      return 
  for a, b in [(i - 1, j), (i, j + 1), (i + 1, j), (i, j - 1)]:
    if (a, b, encoded) not in visited and maze[a][b] != "###":
      dfs(maze, board, visited, (a, b), boards, encoded)
  return 

def won(board, i, j):
  moo = ["M", "O", "O"]
  oom = ["O", "O", "M"]

  if board[i] == moo or board[i] == oom:
    return True
  col = [board[0][j], board[1][j], board[2][j]]
  if col == moo or col == oom:
    return True

  if (i != 1 and j != 1) or (i == 1 and j == 1):
    if i == j:
      diag = [board[0][0], board[1][1], board[2][2]]
      if diag == moo or diag == oom:
        return True
    if i != j or (i == 1 and j ==1):
      diag = [board[0][2], board[1][1], board[2][0]]
      if diag == moo or diag == oom:
        return True
  return False

Run(sys.stdin, sys.stdout)