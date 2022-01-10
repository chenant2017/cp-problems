"""
ID: chenant1
LANG: PYTHON3
TASK: castle
"""

def get_walls(i, j):
  if all_walls[i][j] is not None:
    return all_walls[i][j]
  n = rooms[i][j]
  walls = set()
  if 1 & n > 0:
    walls.add("W")
  if 2 & n > 0:
    walls.add("N")
  if 4 & n > 0:
    walls.add("E")
  if 8 & n > 0: 
    walls.add("S")
  all_walls[i][j] = walls
  return walls

def get_components():
  components = []
  for i in range(len(rooms)):
    for j in range(len(rooms[i])):
      if (i, j) not in visited:
        result = set()
        dfs(i, j, result)
        components.append(result)
  return components

def dfs(i, j, result):
  result.add((i, j))
  visited.add((i, j))
  walls = get_walls(i, j)
  all_walls[i][j] = walls
  if i + 1 <= len(rooms) - 1 and (i + 1, j) not in visited and "S" not in walls and "N" not in get_walls(i + 1, j):
    dfs(i + 1, j, result)
  if j + 1 <= len(rooms[i]) - 1 and (i, j + 1) not in visited and "E" not in walls and "W" not in get_walls(i, j + 1):
    dfs(i, j + 1, result)
  if i - 1 >= 0 and (i - 1, j) not in visited and "N" not in walls and "S" not in get_walls(i - 1, j):
    dfs(i - 1, j, result)
  if j - 1 >= 0 and (i, j - 1) not in visited and "W" not in walls and "E" not in get_walls(i, j - 1):
    dfs(i, j - 1, result)

def get_mapped_components(components):
  mapped_components = [[None for i in j] for j in rooms]
  for i in range(len(components)):
    for j in components[i]:
      mapped_components[j[0]][j[1]] = i
  return mapped_components

def get_max_sum(mapped_components, sizes):
  area = None
  wall = None
  rows = len(mapped_components)
  columns = len(mapped_components[0])
  for j in range(columns):
    for i in range(rows - 1, -1, -1):
      component1 = mapped_components[i][j]
      walls = get_walls(i, j)
      if i > 0 and component1 != mapped_components[i - 1][j] and "N" in walls:
        new = sizes[component1] + sizes[mapped_components[i - 1][j]]
        if area is None or new > area:
          area = new
          wall = (i + 1, j + 1, "N")
      if j < columns - 1 and component1 != mapped_components[i][j + 1] and "E" in walls:
        new = sizes[component1] + sizes[mapped_components[i][j + 1]]
        if area is None or new > area:
          area = new
          wall = (i + 1, j + 1, "E")
  return area, wall


with open("castle.in", "r") as fin, open("castle.out", "w") as fout:
  fin.readline()
  rooms = [[int(i) for i in line.split()] for line in fin.readlines()]
  visited = set()
  all_walls = [[None for i in range(len(rooms[j]))] for j in range(len(rooms))]
  components = get_components()
  sizes = [len(c) for c in components]
  mapped_components = get_mapped_components(components)
  area, wall = get_max_sum(mapped_components, sizes)
  fout.write("{}\n{}\n{}\n{} {} {}\n".format(len(sizes), max(sizes), area, wall[0], wall[1], wall[2]))