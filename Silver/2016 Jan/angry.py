def bin_search_R(min, max, K, hays):
  while max - min > 1:
    mid = (min + max) // 2 
    if check(K, mid, hays):
      max = mid
    else:
      min = mid
  return max

def check(K, R, hays):
  pos = hays[0]
  pointer = 0
  cows_left = K

  while pos <= hays[-1]:
    pos += 2 * R + 1
    cows_left -= 1
    found = False
    for h in range(pointer, len(hays)):
      if hays[h] >= pos:
        pointer = h
        found = True
        break
    if not found:
      break
    pos = hays[pointer]
    
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