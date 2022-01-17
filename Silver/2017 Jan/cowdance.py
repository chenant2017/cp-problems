def get_T(durs, K):
  curr_max = max(durs)
  for i in range(K, len(durs)):
    min_prev = min(durs[(i - K) : i])
    durs[i] += min_prev
    if durs[i] > curr_max:
      curr_max = durs[i]
  return curr_max

def bin_search_K(K_min, K_max, durs, T_max):
  while K_max - K_min > 1:
    mid = (K_min + K_max) // 2 
    T = get_T(durs.copy(), mid)
    if T <= T_max:
      K_max = mid
    else:
      K_min = mid
  return K_max

def Run(input, output):
  with open(input, 'r') as fin, open(output, "w") as fout:
    N, T_max = (int(i) for i in fin.readline().split())
    durs = [None] * N
    for i in range(N):
      durs[i] = int(fin.readline())
    ans = bin_search_K(1, N, durs, T_max)
    fout.write("{}\n".format(ans))

Run("cowdance.in", "cowdance.out")