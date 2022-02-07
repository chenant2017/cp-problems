import sys




def Run(input, output):
  with input as fin, output as fout:
    N = int(fin.readline())
    cows = [int(i) for i in fin.readline().split()]
    ans = 2 * (N - 1)

    maxes = [None] * N
    max = 0
    for i in range(N - 1, -1, -1):
      if cows[i] > max:
        max = cows[i]
      maxes[i] = max

    for i in range(N - 1):
      max_val = cows[i + 1]
      for j in range(i + 2, N):
        if max_val > cows[i] or max_val > maxes[j]:
          break
        if max_val < cows[j]:
          ans += j - i + 1
          max_val = cows[j]
    fout.write("{}\n".format(ans))

Run(sys.stdin, sys.stdout)
    