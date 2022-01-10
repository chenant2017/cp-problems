"""
ID: chenant1
LANG: PYTHON3
TASK: maze1
"""

def bfs(i, j):
  moves = 1
  visited = {(i, j)}
  queue = [(i, j)]
  queue_ = []
  while len(queue) > 0:
    i, j = queue.pop(0)
    if (i, j) in dists:
      if moves < dists[(i, j)]:
        dists[(i, j)] = moves
    else:
      dists[(i, j)] = moves
    neighbors = get_neighbors(i, j)
    for n in neighbors:
      if n not in visited:
        visited.add(n)
        queue_.append(n)
    if len(queue) == 0:
      moves += 1
      queue = queue_
      queue_ = []

def get_neighbors(i, j):
  neighbors = []
  r_dir = [0, 0, -1, 1]
  c_dir = [-1, 1, 0, 0]
  for d in range(4):
    r = r_dir[d]
    c = c_dir[d]
    if 0 <= (i + 2 * r) <= 2 * h and 0 <= (j + 2 * c) <= 2 * w:
      if maze[i + r][j + c] == " " and maze[i + 2 * r][j + 2 * c] == " ":
        neighbors.append((i + 2 * r, j + 2 * c))
  return neighbors

  
with open("maze1.in", "r") as fin, open("maze1.out", "w") as fout:
  w, h = (int(i) for i in fin.readline().split())
  maze = []
  exits = []
  for l in fin.readlines():
    maze.append([i for i in l.strip("\n")])
  for j in range(1, len(maze[0]) - 1):
    if maze[0][j] == " ":
      exits.append((1, j))
    if maze[2 * h][j] == " ":
      exits.append((2 * h - 1, j))
  for i in range(1, len(maze) - 1):
    if maze[i][0] == " ":
      exits.append((i, 1, 0, 1))
    if maze[i][2 * w] == " ":
      exits.append((i, 2 * w - 1))
  dists = {}
  for i in exits:
    bfs(i[0], i[1])
  fout.write(str(max(dists.values())) + "\n")
  