"""
ID: chenant1
LANG: PYTHON3
TASK: transform
"""
def read(fin, n):
  input = [['']* n for i in range(n)]
  for i in range(n):
    s = fin.readline()
    for j in range(n):
      input[i][j] = str(s[j])
  return input

def fn1(i, j):
  return j, n - 1 - i

def fn2():
  return n - 1 - i, n - 1 - j

def fn3():
  return n - 1 - j, i

def fn4():
  return i, n - 1 - j

def fn5_1(i, j):
  x = fn4(i, j)
  return rotate90(x[0], x[1])

def fn5_2(i, j):
  x = fn4(i, j)
  return rotate180(x[0], x[1])

def fn5_3(i, j):
  x = fn4(i, j)
  return rotate270(x[0], x[1])

fns = [fn1, fn2, fn3, fn4, fn5_1, fn5_2, fn5_3]

def search():
  if input == output:
    return 6
  for fn in range(len(fns)):
    b = True
    for i in range(n):
      for j in range(n):
        x, y = fns[fn](i, j)
        if output[x][y] != input[i][j]:
          b = False
    if b:
      return fn + 1
  return 7

with open('transform.in', 'r') as fin, open('trnasform.out', 'w') as fout:
  n = int (fin.readline())
  input = read(fin, n)
  output = read(fin, n)
  fout.write(str(search()) + "\n")
  
