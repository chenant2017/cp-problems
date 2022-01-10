"""
ID: chenant1
LANG: PYTHON3
TASK: subset
"""
def get_nsubsets(matrix):
  for i in range(1, len(matrix[1])):
    matrix[1][i] = 0
  matrix[1][1] = 1

  for i in range(2, len(matrix)):
    for j in range(1, len(matrix[i])):
      matrix[i][j] = get_value(matrix, i - 1, j) + get_value(matrix, i - 1, j - i)
  return matrix

def get_value(matrix, i, j):
  if i < 1 or j < 1:
    return 0
  else:
    return matrix[i][j]

with open("subset.in", "r") as fin, open("subset.out", "w") as fout:
  N = int(fin.readline())
  sum = N * (N + 1) // 2
  if sum % 2 == 0:
    matrix = [[None for i in range(sum//2 + 1)] for j in range(N + 1)]
    matrix = get_nsubsets(matrix)
    fout.write(str(matrix[-1][-1]) + "\n")
  else:
    fout.write("0\n")