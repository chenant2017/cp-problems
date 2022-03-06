import sys

def Run(fin, fout):
  N = int(fin.readline())
  choices = [None] * (N + 1)
  indices = [None] * (N + 1)

  for i in range(1, N + 1):
    choice = [None] * (N + 1)
    line = fin.readline().split()
    for j in range(N):
      lj = int(line[j])
      if lj == i:
        indices[i] = j + 1
      choice[j + 1] = lj
    choices[i] = choice
  #print("indices", indices)
  for i in range(1, 5):
    result = dfs(i, choices, indices, {}, {})
    fout.write("{}\n".format(result))

def dfs(start, choices, indices, took, taken_by):
  N = len(choices) - 1
  ind = indices[start] #optimize by storing indices later
  #print(taken_by, took)
  if start in took:
    return took[start]
  for i in range(1, ind):
    j = choices[start][i]
    if j not in taken_by:
      taken_by[j] = start
      took[start] = j
      if dfs(j, choices, indices, took, taken_by) != j:
        #print("returned", j, taken_by)
        return j
      else:
        taken_by[j] = j
        took[j] = j
  #print("returned", start, taken_by)
  return start

Run(sys.stdin, sys.stdout)