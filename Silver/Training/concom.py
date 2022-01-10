"""
ID: chenant1
LANG: PYTHON3
TASK: concom
"""

def dfs(matrix, i, result, node_set, max):
  if i in node_set:
    return result
  node_set.add(i)
  children = []
  for a in range(1, max + 1):
    result[a] += matrix[i][a]
    if result[a] > 50:
      children.append(a)
  #print(i, children)
  for a in children:
    result = dfs(matrix, a, result, node_set, max)
  return result

with open("concom.in", "r") as fin, open("concom.out", "w") as fout:
  N = int(fin.readline())
  max = 0
  matrix = [[0 for i in range(101)] for j in range(101)]
  solutions = set()

  for l in fin.readlines():
    i, j, k = (int(n) for n in l.split())
    if i > max:
      max = i
    if j > max:
      max = j
    matrix[i][j] = k

  for i in range(1, max + 1):
    dfs_ = dfs(matrix, i, [0 for i in range(101)], set(), max)
    for j in range(len(dfs_)):
      if dfs_[j] > 50 and i != j:
        fout.write("{} {}\n".format(str(i), str(j)))