"""
ID: chenant1
LANG: PYTHON3
TASK: combo
"""

def get_combos(combo, n):
  combos = []
  for i in range(combo[0] - 2, combo[0] + 3):
    for j in range(combo[1] - 2, combo[1] + 3):
      for k in range(combo[2] - 2, combo[2] + 3):
        combos.append((i % n, j % n, k % n))
  return combos

def to_int_list(l):
  return [int(i) for i in l] 

with open('combo.in', 'r') as fin, open('combo.out', 'w') as fout:
  n = int(fin.readline().strip())
  john = to_int_list(fin.readline().strip().split())
  master = to_int_list(fin.readline().strip().split())
  fout.write(str(len(set(get_combos(john, n) + get_combos(master, n)))) + "\n")
  