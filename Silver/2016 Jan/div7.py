def Run(input, output):
  with open(input, 'r') as fin, open(output, "w") as fout:
    N = int(fin.readline())
    cum_sums = [int(fin.readline()) % 7]
    for i in range(1, N):
      cum_sums.append((cum_sums[i - 1] + int(fin.readline())) % 7)

    best = 0

    for rem in range(7):
      first = -1
      last = -1
      for i in range(len(cum_sums)):
        if cum_sums[i] == rem:
          if first < 0:
            first = i
          else:
            last = i
        if last - first > best:
          best = last - first
    fout.write("{}\n".format(best))
     
Run("div7.in", "div7.out")
    