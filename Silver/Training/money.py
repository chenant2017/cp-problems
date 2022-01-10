"""
ID: chenant1
LANG: PYTHON3
TASK: money
"""

def find_solutions(coins, value): #DYNAMIC PROGRAMMING
  solutions = [0 for i in range(value + 1)]
  solutions[0] = 1
  if coins[0] == 1:
    solutions[1] = 1
  else:
    solutions[1] = 0
  for j in range(len(coins)):
    for i in range(2, value + 1):
      if coins[j] <= i:
        solutions[i] += solutions[i - coins[j]]
  print(solutions)
  return solutions[-1]

with open("money.in", "r") as fin, open("money.out", "w") as fout:
  N = int(fin.readline().split()[1])
  coins = []
  for i in fin.readlines():
    coins += [int(j) for j in i.split()]
  coins = sorted(coins)
  print(coins)
  fout.write(str(find_solutions(coins, N)) + "\n")