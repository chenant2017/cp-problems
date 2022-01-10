"""
ID: chenant1
LANG: PYTHON3
TASK: zerosum
"""

def dfs(node, N):
  if len(node) == N:
    return
  if len(node) == N - 1:
    c = calculate(node)
    if c[0] == 0:
      solutions.append(c[1])
  for i in ([" ", "+", "-"]):
    dfs(node + [i], N)

# space < + < -

def calculate(node):
  string = "1"
  sum = 0
  n = 1
  for i in range(len(node)):
    string += node[i] + str(i + 2)
    if node[i] == " ":
      if n > 0:
        n = 10 * n + i + 2
      else:
        n = 10 * n - i - 2
    elif node[i] == "+":
      sum += n
      n = i + 2
    else:
      sum += n
      n = -i - 2
    #print("sum =", sum)
    #print("n =", n)
  sum += n
  return sum, string

with open("zerosum.in", "r") as fin, open("zerosum.out", "w") as fout:
  N = int(fin.readline())
  solutions = []
  dfs([], N)
  for s in solutions:
    fout.write(s + "\n")