"""
ID: chenant1
LANG: PYTHON3
TASK: holstein
"""

def bfs(required, feeders):
  queue = [None]
  while True:
    scoops = queue.pop(0)
    if is_good(scoops, required, feeders):
      return scoops
    for c in get_children(scoops, feeders):
      queue.append(c)
      

def is_good(scoops, required, feeders):
  if scoops is None:
    return False
  result = [0 for i in required]
  for i in scoops:
    for j in range(len(feeders[i])):
      result[j] += feeders[i][j]
  for i in range(len(result)):
    if result[i] < required[i]:
      return False
  return True


def get_children(scoops, feeders):
  if scoops is None:
    return ([i] for i in range(len(feeders)))
  else:
    return (scoops + [i] for i in range(scoops[-1] + 1, len(feeders)))

with open("holstein.in", "r") as fin, open("holstein.out", "w") as fout:
  vitamins = int(fin.readline())
  required = tuple(int(i) for i in fin.readline().split())
  n_feeders = int(fin.readline())
  feeders = tuple(tuple(int(i) for i in line.split()) for line in fin.readlines())
  result = bfs(required, feeders)
  fout.write(str(len(result)) + " ")
  for i in range(len(result) - 1):
    fout.write(str(result[i] + 1) + " ")
  fout.write(str(result[-1] + 1) + "\n")