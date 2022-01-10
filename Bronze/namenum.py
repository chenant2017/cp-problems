"""
ID: chenant1
LANG: PYTHON3
TASK: namenum
"""

def find_names(f, serial, fout):
  serial = serial.strip()
  touchtone = {
    '2': ['A','B','C'],
    '3': ['D','E','F'],
    '4': ['G','H','I'],
    '5': ['J','K','L'],
    '6': ['M','N','O'],
    '7': ['P','R','S'],
    '8': ['T','U','V'],
    '9': ['W','X','Y']
  }
  names = []
  while True:
    line = f.readline().strip()
    if line[0] > max(touchtone[serial[0]]):
      break
    elif len(line) == len(serial):
      b2 = True
      for ch in range(len(line)):
        if line[ch] not in touchtone[serial[ch]]:
          b2 = False
          break
      if b2:
        names.append(line)
  if len(names) > 0:
    for name in names:
      fout.write(name + "\n")
  else:
    fout.write("NONE\n")

with open('namenum.in', 'r') as fin, open('namenum.out', 'w') as fout, open('dict.txt', 'r') as fdict:
  serial = fin.readline()
  find_names(fdict, serial, fout)
