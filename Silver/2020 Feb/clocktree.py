def bfs(room, adjacencies, positions):
  print(positions)
  total = positions[room]
  level = 1
  queue = adjacencies[room]
  points_odd = 0
  points_even = 1
  visited = {room}
  while len(queue) > 0:
    to_add = []
    for j in queue:
      print("j", j)
      print('level', level)
      visited.add(j)
      if level % 2 == 0:
        total += positions[j]
        points_even += 1
      else:
        total -= positions[j]
        points_odd += 1
      for k in adjacencies[j]:
        if k not in visited:
          to_add.append(k)
    queue = to_add
    level += 1
    
  return [total, points_odd, points_even]


def Run(input, output):
  with open(input, 'r') as fin, open(output, "w") as fout:
    N = int(fin.readline())
    positions = [0] + [int(i) for i in fin.readline().split()]
    adjacencies = {}
    for line in fin.readlines():
      rooms = tuple(int(i) for i in line.split())
      if rooms[0] in adjacencies.keys():
        adjacencies[rooms[0]].append(rooms[1])
      else:
        adjacencies[rooms[0]] = [rooms[1]]
      if rooms[1] in adjacencies.keys():
        adjacencies[rooms[1]].append(rooms[0])
      else:
        adjacencies[rooms[1]] = [rooms[0]]
    total, points_odd, points_even = bfs(1, adjacencies, positions)
    print(total, points_odd, points_even)
    ways = 0
    #points_even is starting from first level (level 0)
    if total % 12 == 0 or total % 12 == 1:
      ways += points_even
    if (-1 * total) % 12 == 0 or (-1 * total) % 12 == 1:
      ways += points_odd
    fout.write("{}\n".format(ways))
    
Run("clocktree.in", "clocktree.out")
