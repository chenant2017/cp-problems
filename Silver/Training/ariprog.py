"""
ID: chenant1
LANG: PYTHON3
TASK: ariprog
"""

def get_bisquares(M):
  result = []
  for i in range(M + 1):
    for j in range(M + 1):
      result.append(i**2 + j**2)
  return set(result)

def get_sequences(bisquares, N):
  lbisquares = sorted(bisquares)
  sequences = []
  max = 0
  for i in range(len(lbisquares) - 1):
    for j in range(i + 1, len(lbisquares)):
      #print(lbisquares[i], lbisquares[j])
      good = True
      diff = lbisquares[j] - lbisquares[i]
      if lbisquares[i] + diff * (N - 1) > lbisquares[-1]:
        break
      for k in range(N - 1, 1, -1):
        if lbisquares[i] + diff * k not in bisquares:
          good = False
          break
      if not good:
        continue
      sequence = [lbisquares[i], diff]
      sequences.append(sequence)
  return sorted(sequences, key=lambda x: x[1])

with open("ariprog.in", "r") as fin, open("ariprog.out", "w") as fout:
  N = int(fin.readline().strip())
  M = int(fin.readline().strip())
  sequences = get_sequences(get_bisquares(M), N)
  for i in sequences:
    fout.write(str(i[0]) + " " + str(i[1]) + "\n")
  if len(sequences) == 0:
    fout.write("NONE" + "\n")
