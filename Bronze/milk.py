"""
ID: chenant1
LANG: PYTHON3
TASK: milk
"""

with open('milk.in', 'r') as fin, open('milk.out', 'w') as fout:
  data = []
  runits = int(fin.readline().strip().split()[0])
  for line in fin.readlines():
    info = line.strip().split()
    infol = []
    infol.append(int(info[0]))
    infol.append(int(info[1]))
    data.append(infol)
  data.sort()
  buying = 0
  total = 0
  for d in data:
    if d[1] >= runits:
      buying = runits
    else:
      buying = d[1]
    total += buying * d[0]
    runits -= buying
  fout.write(str(total) + "\n")