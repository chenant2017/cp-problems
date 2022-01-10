"""
ID: chenant1
LANG: PYTHON3
TASK: nocows
"""

def find_trees(N, K): 
  #print("N K", N, K)
  if N < 2*(K - 1) + 1 or N > 2**K - 1 or N % 2 == 0:
    #print("returned 0")
    return 0
  if N == 2**K - 1:
    #print("returned 1")
    return 1
  sum = 0
  for i in range(1, N, 2):
    #print(i)
    if solutions[i][K - 1] is None:
      a = find_trees(i, K - 1)
      solutions[i][K - 1] = a
    else:
      a = solutions[i][K - 1]
    #print("a", a)
    #print("i", i)
    if a != 0:
      for j in range(1, K - 1):
        #print(i, N - 1 - i, j, N, K)
        if solutions[N - 1 - i][j] is None:
          b = find_trees(N - 1 - i, j)
          solutions[N - 1 - i][j] = b
        else:
          b = solutions[N - 1 - i][j]
        
        sum += 2 * a * b
        #print("added 2 *", a, "*", b, N, K)
      if solutions[N - 1 - i][K - 1] is None:
        b = find_trees(N - 1 - i, K - 1)
        solutions[N - 1 - i][K - 1] = b
      else:
        b = solutions[N - 1 - i][K - 1]
      sum += a * b
      #print("added ", a, "*", b, N, K)
      #print("sum =", sum, "|", N, K)
  #print(solutions)
  return sum
    
with open("nocows.in", "r") as fin, open("nocows.out", "w") as fout:
  N, K = (int(i) for i in fin.readline().split()) # number of nodes, height of tree(s)
  solutions = [[None for i in range(K + 1)] for j in range(N + 1)]
  fout.write(str(find_trees(N, K) % 9901) + "\n")
  