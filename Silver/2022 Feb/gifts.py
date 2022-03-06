import sys
from collections import defaultdict

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
  for i in range(1, N + 1):
    result = dfs(i, choices, indices, defaultdict(int), defaultdict(int))
    fout.write("{}\n".format(result))

def dfs(start, choices, indices, took, taken_by):
  N = len(choices) - 1
  ind = indices[start] #optimize by storing indices later
  #print(taken_by, took)
  if took[start]:
    return took[start]
  for i in range(1, ind):
    j = choices[start][i]
    if not taken_by[j]:
      taken_by[j] = start
      took[start] = j
      if dfs(j, choices, indices, took, taken_by) != j:
        #print("returned", j, taken_by)
        return j
      else: #backtrack
        taken_by[j] = 0
        took[start] = 0
  #print("returned", start, taken_by)
  return start
  
Run(sys.stdin, sys.stdout)