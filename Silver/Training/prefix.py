"""
ID: chenant1
LANG: PYTHON3
TASK: prefix
"""

def find_longest(P, S):
  solutions = [None for i in range(len(S))]
  solutions[0] = S[0] in P
  for i in range(1, len(S)):
    solutions[i] = False
    if S[:i + 1] in P:
      #print("a", S[:i])
      solutions[i] = True
      continue
    for j in range(i - 1, -1, -1):
      #print(j, solutions[j + 1], S[j + 1:i])
      if solutions[j] and S[j + 1:i + 1] in P:
        solutions[i] = True
        break
      if j == i - 10:
        break
  return solutions
    
with open("prefix.in", "r") as fin, open("prefix.out", "w") as fout:
  P = fin.readline().split()
  l = fin.readline()
  while l != ".\n":
    P += l.split()
    l = fin.readline()
  P = set(P)
  S = fin.readline().strip()
  for l in fin.readlines():
    S += l.strip()
  solutions = find_longest(P, S)
  has_sol = False
  for s in range(len(solutions) - 1, -1, -1):
    if solutions[s]:
      fout.write(str(s + 1) + "\n")
      has_sol = True
      break
  if not has_sol:
    fout.write("0\n") 