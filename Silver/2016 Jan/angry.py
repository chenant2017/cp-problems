def bin_search_R(min, max, K, hays):
  while max - min > 1:
    mid = (min + max) // 2 
    if check(K, mid, hays):
      max = mid
    else:
      min = mid
  return max

def check(K, R, hays):
  pos = min(hays)
  cows_left = K
  while pos <= max(hays):
    if pos in hays:
      pos += 2 * R + 1
      cows_left -= 1
    if pos not in hays:
      pos = find_next(pos, hays)
      if pos == -1:
        break
  if cows_left < 0:
    return False
  return True

def find_next(pos, hays):
  for i in sorted(hays):
    if i > pos:
      return i
  return -1

def Run(input, output):
  with open(input, 'r') as fin, open(output, "w") as fout:
    N, K = (int(i) for i in fin.readline().split())
    hays = set()
    for i in range(N):
      hay = int(fin.readline())
      hays.add(hay)
    min_R = bin_search_R(0, max(hays)//2 + 1, K, hays)
    fout.write("{}\n".format(min_R))
    #print(min_R)
      
Run("angry.in", "angry.out")