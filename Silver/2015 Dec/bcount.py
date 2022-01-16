
def Run(input, output):
  with open(input, 'r') as fin, open(output, "w") as fout:
    cum = [[0, 0, 0]]
    N, Q = (int(i) for i in fin.readline().split())
    for i in range(1, N + 1):
      n = int(fin.readline())
      to_add = cum[i - 1].copy()
      to_add[n - 1] += 1
      cum.append(to_add)
  
    for q in range(Q):
      start, end = (int(i) for i in fin.readline().split())
      result = [None] * 3
      for i in range(3):
        result[i] = cum[end][i] - cum[start - 1][i]
      fout.write("{} {} {}\n".format(result[0], result[1], result[2]))

Run("bcount.in", "bcount.out")