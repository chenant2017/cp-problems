def bin_search_R(min, max, K, hays):
  while max - min > 1:
    mid = (min + max) // 2 
    if check(K, mid, hays):
      max = mid
    else:
      min = mid
  return max

def check(K, R, hays):
  pointer = 0
  cows_left = K

  while hays[pointer] <= hays[-1]:
    next_pos = hays[pointer] + 2 * R + 1
    cows_left -= 1
    while pointer < len(hays) and hays[pointer] < next_pos:
      pointer += 1
    if pointer == len(hays):
      break
    
  if cows_left < 0:
    return False
  return True

def Run(input, output):
  with open(input, 'r') as fin, open(output, "w") as fout:
    N, K = (int(i) for i in fin.readline().split())
    hays = []
    for i in range(N):
      hay = int(fin.readline())
      hays.append(hay)
    hays = sorted(hays)
    min_R = bin_search_R(0, hays[-1]//2 + 1, K, hays)
    fout.write("{}\n".format(min_R))
    #print(min_R)
      
Run("angry.in", "angry.out")