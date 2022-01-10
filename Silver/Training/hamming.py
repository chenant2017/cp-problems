"""
ID: chenant1
LANG: PYTHON3
TASK: hamming
"""

def find_ones(b, B):
  ones = 0
  for i in range(B):
    if b % 2 == 1:
      ones += 1
    b >>= 1
  return ones

def get_hamming(b1, b2):
  if b1 == b2:
    return 0
  if (b1 % 2) == (b2 % 2): #last digit
    return get_hamming(b1 >> 1, b2 >> 1)
  else:
    return 1 + get_hamming(b1 >> 1, b2 >> 1)

with open("hamming.in", "r") as fin, open("hamming.out", "w") as fout:
  N, B, D = (int(i) for i in fin.readline().split())
  valid = [0]
  for i in range(1, 2 ** B):
    if len(valid) == N:
      break
    good = True
    for j in valid:
      if get_hamming(i, j) < D:
        good = False
    if good:
      valid.append(i)

  for i in range(len(valid)):
    fout.write(str(valid[i]))
    if i != N - 1:
      if i % 10 == 9:
        fout.write("\n")
      else:
        fout.write(" ")
  fout.write("\n")

    
  
    
  

    
  

    
  