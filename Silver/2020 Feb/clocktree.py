def bfs(room, adjacencies, positions):
  #print(positions)
  total = 0
  queue = [room]
  signs = [0] * (len(positions) + 1)
  signs[room] = 1
  while len(queue) > 0:
    to_add = []
    for j in queue:
      #print("j", j)
      total += positions[j] * signs[j]
      for k in adjacencies[j]:
        if signs[k] == 0:
          to_add.append(k)
          signs[k] = -signs[j]
    queue = to_add

  return [total, signs]
    

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
    total, signs = bfs(1, adjacencies, positions)
    total_pos = 0
    for i in signs:
      if i == 1:
        total_pos += 1
    ways = 0
    #points_even is starting from first level (level 0)
    if total % 12 == 0 or total % 12 == 1:
      ways += total_pos
    if (-1 * total) % 12 == 0 or (-1 * total) % 12 == 1:
      ways += N - total_pos
    print(ways)
    fout.write("{}\n".format(ways))
    
    
    
Run("clocktree.in", "clocktree.out")

