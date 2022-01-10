def reverse(cows, L, R):
  for i in range(L, (R + L)//2 + 1):
    swap(cows, i, R + L - i)

def swap(cows, a, b):
  temp = cows[a]
  cows[a] = cows[b]
  cows[b] = temp

def do(op, cows):
  result = [None] * len(cows)
  for i in range(len(cows)):
    result[i] = cows[op[i]]
  return result

def twice(op, cows):
  for i in range(2):
    cows = do(op, cows)
  return cows

def Run(input, output):
  with open(input) as fin, open(output, "w") as fout:
    N, M, K = (int(i) for i in fin.readline().strip().split())

    swap_steps = []
    for line in fin.readlines():
      swap_steps.append(tuple(int(i) for i in line.strip().split()))
    
    op = list(range(N + 1))
    for i in range(len(swap_steps)):
      reverse(op, swap_steps[i][0], swap_steps[i][1])
    
    cows = list(range(N + 1))

    while K > 0:
      if K % 2 == 1:
        cows = do(op, cows)
      K = K // 2
      op = do(op, op)
        
    for i in range(1, len(cows)):
      fout.write("{}\n".format(cows[i]))

Run("swap.in", "swap.out")