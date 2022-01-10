def reverse(cows, L, R):
  for i in range(L, (R + L)//2 + 1):
    swap(cows, i, R + L - i)

def swap(cows, a, b):
  temp = cows[a]
  cows[a] = cows[b]
  cows[b] = temp

def Run(input, output):
  with open(input) as fin, open(output, "w") as fout:
    N, M, K = (int(i) for i in fin.readline().strip().split())
    swap_steps = []
    for line in fin.readlines():
      swap_steps.append(tuple(int(i) for i in line.strip().split()))
    cows = list(range(N + 1))
    #print(cows)
    for i in range(len(swap_steps)):
      reverse(cows, swap_steps[i][0], swap_steps[i][1])
    indices = [None] * len(cows)
    #print("after one cycle", cows)
    for i in range(len(cows)):
      indices[cows[i]] = i
    #print("indices", indices)

    result = [None] * len(cows)
    for i in range(len(cows)):
      if result[i] is None:
        cycle = [i]
        j = i
        while True:
          assert result[j] is None
          j = indices[j]
          if j == i:
            break
          else:
            cycle.append(j)
        #print(cycle)
        for k in range(len(cycle)):
          result[cycle[k]] = cycle[(k - K) % len(cycle)]
    #print(result)
    for i in range(1, len(cows)):
      fout.write("{}\n".format(result[i]))

Run("swap.in", "swap.out")