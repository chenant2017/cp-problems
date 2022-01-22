def Run(input, output):
  with open(input, 'r') as fin, open(output, "w") as fout:
    N = int(fin.readline())
    cum_sums = [int(fin.readline()) % 7]
    for i in range(1, N):
      cum_sums.append((cum_sums[i - 1] + int(fin.readline())) % 7)

    best = 0

    for diff in range(N - 1, 0, -1):
      for i in range(N - diff):
        if cum_sums[i + diff] == cum_sums[i]:
          best = diff
          fout.write("{}\n".format(best))
          return
    fout.write("{}\n".format(best))
     
Run("div7.in", "div7.out")
    