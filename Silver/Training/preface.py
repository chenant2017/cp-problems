"""
ID: chenant1
LANG: PYTHON3
TASK: preface
"""

def get_roman(n):
  Is = Vs = Xs = Ls = Cs = Ds = Ms = 0 
  roman = ""
  while n >= 1000:
    n -= 1000
    Ms += 1
  if n >= 900:
    n -= 900
    Cs += 1
    Ms += 1
  if n >= 500:
    n -= 500
    Ds += 1
  if n >= 400:
    n -= 400
    Cs += 1
    Ds += 1

  while n >= 100:
    n -= 100
    Cs += 1
  if n >= 90:
    n -= 90
    Xs += 1
    Cs += 1
  if n >= 50:
    n -= 50
    Ls += 1
  if n >= 40:
    n -= 40
    Xs += 1
    Ls += 1
  
  while n >= 10:
    n -= 10
    Xs += 1
  if n >= 9:
    n -= 9
    Is += 1
    Xs += 1
  if n >= 5:
    n -= 5
    Vs += 1
  if n >= 4:
    n -= 4
    Is += 1
    Vs += 1

  while n >= 1:
    n -= 1
    Is += 1

  l = (Is, Vs, Xs, Ls, Cs, Ds, Ms)
  to_append = [None for i in range(7)]
  for i in range(7):
    to_append[i] = num_letters[-1][i] + l[i]
  return to_append

with open("preface.in", "r") as fin, open("preface.out", "w") as fout:
  roman_letters = ["I", "V", "X", "L", "C", "D", "M"]
  num_letters = [[0 for i in range(7)]]
  N = int(fin.readline())
  for i in range(N):
    num_letters.append(get_roman(i + 1))
  for i in range(7):
    num = num_letters[-1][i]
    if num != 0:
      fout.write("{} {}\n".format(roman_letters[i], num))
  
