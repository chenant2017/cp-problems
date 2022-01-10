def get_cows(i, prefs, queues, initial):
  first, second = prefs[i]
  assert queues[first][0] == i
  queues[first].pop(0)
  assert (len(queues[second]) == 0 or queues[second][0] != i)
  return initial - clean(first, prefs, queues)

def clean(first, prefs, queues): 
  if len(queues[first]) == 0: 
      return 1
  while True:
    i = queues[first][0]
    first, second = prefs[i]
    if queues[first][0] == i:
      if len(queues[second]) == 0 or queues[second][0] != i: 
        return 0
      queues[second].pop(0)
      if len(queues[second]) == 0:
        return 1
      i = queues[second][0]
      first, second = prefs[i]
    else:
      return 0

with open("cereal.in", "r") as fin, open("cereal.out", "w") as fout:
  N, M = (int(i) for i in fin.readline().split()) 
  queues = [[] for i in range(M)]
  prefs = []
  for i in range(N):
    prefs.append([int(j) - 1 for j in fin.readline().split()])
  initial = 0
  taken = [False for i in range(M)]
  for i in range(len(prefs)):
    first_q = prefs[i][0]
    second_q = prefs[i][1]
    queues[first_q].append(i)
    if not taken[first_q]:
      initial += 1
      taken[first_q] = True
    else:
      queues[second_q].append(i)
      if not taken[second_q]:
        initial += 1
        taken[second_q] = True
  fout.write(str(initial) + "\n")
  for i in range(N - 1):
    initial = get_cows(i, prefs, queues, initial)
    fout.write(str(initial) + "\n")
  