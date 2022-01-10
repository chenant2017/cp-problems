import sys

def dfs(maze, start_, visited, path):
  i, j = start_
  visited.append((i, j))
  if is_move(maze, i, j):
    path.append(maze[i][j])
    if path[-1] in paths:
      paths[path[-1]].append(set(path[:-1]))
    else:
      paths[path[-1]] = [set(path[:-1])]
  dead_end = True
  for c in ((i + 1, j), (i - 1, j), (i, j + 1), (i, j - 1)):
    if (c not in visited and maze[c[0]][c[1]] != "###") or (is_move(maze, c[0], c[1]) and not is_move(maze, visited[-1][0], visited[-1][1])):
      dead_end = False
      dfs(maze, c, visited, path)
  if dead_end:
    if len(path) != 0:
      if is_move(maze, i, j):
        path.pop(-1)
    if start_ != start:
      dfs(maze, start, visited, [])

def is_move(maze, i, j):
  return maze[i][j][0] == "M" or maze[i][j][0] == "O"

def dfs_(arr, paths):
  for w in winning:
    if arr.issuperset(w):
      arrs.append(frozenset(arr))
      return
  children = get_children_(arr, paths)
  for c in children:
    dfs_(c, paths)

def get_children_(arr, paths):
  children = []
  for k in paths.keys():
    if not taken(arr, k):
      for p in paths[k]:
        if arr.issuperset(p):
          c = arr.union({k})
          if len(c) > len(arr):
            children.append(c)
  return children

def taken(arr, k):
  for i in arr:
    if (k[1], k[2]) == (i[1], i[2]):
      return True
  return False

with sys.stdin as fin, sys.stdout as fout:
  n = int(fin.readline())
  maze = [[] for i in range(n)]
  start = None
  for i in range(n):
    line = fin.readline()
    for j in range(n):
      s = line[3*j: 3*j+3]
      if s == "BBB":
        start = (i, j)
      maze[i].append(s)
  #for i in maze:
    #print(i)
  paths = {}
  dfs(maze, start, [], [])
  #print(paths)
  winning = ({'M11', 'O21', 'O31'}, 
             {'M13', 'O22', 'O31'}, 
             {'M11', 'O22', 'O33'}, 
             {'M33', 'O22', 'O11'}, 
             {'M11', 'O12', 'O13'}, 
             {'M33', 'O23', 'O13'}, 
             {'M31', 'O32', 'O33'}, 
             {'M31', 'O22', 'O13'}, 
             {'M31', 'O21', 'O11'}, 
             {'M13', 'O12', 'O11'}, 
             {'M33', 'O32', 'O31'}, 
             {'M13', 'O23', 'O33'})
  arrs = []
  dfs_(set(), paths)
  s = set(arrs)
  #print(s)
  fout.write(str(len(s)) + "\n")

  
