"""
ID: chenant1
LANG: PYTHON3
TASK: milk3
"""

def bfs(node):
  visited = set()
  queue = []
  solutions = set()
  queue.append(node)
  while len(queue) != 0:
    x = queue.pop(0)
    if x[0] == 0:
      solutions.add(x[2])
    visited.add(x)
    for c in get_children(x):
      if c not in visited:
        queue.append(c)
  return solutions

def get_children(node):
  result = set()
  for i in range(3):
    for j in range(3):
      if i != j: #pouring from i to j
        node2 = list(node)
        if node2[j] + node2[i] > capacities_[j]:
          node2[i] = node2[i] - (capacities_[j] - node[j])
          node2[j] = capacities_[j]
        else:
          node2[j] = node2[j] + node2[i]
          node2[i] = 0
        result.add(tuple(node2))
  return result
  
with open("milk3.in", "r") as fin, open("milk3.out", "w") as fout:
  capacities_ = [int(i) for i in fin.readline().split()]
  node = (0, 0, capacities_[2])
  solutions_ = sorted(bfs(node))
  for i in range(len(solutions_) - 1):
    fout.write(str(solutions_[i]) + " ")
  fout.write(str(solutions_[-1]) + "\n")