def search(cows, perm, M, served, min_perm, min_hungry):
  print(perm, served)
  N = len(cows)
  if len(perm) == len(served):
    hungry = test(cows, perm, M, min_hungry) 
    if hungry < min_hungry:
      min_hungry = hungry
      min_perm = perm
  else:
    for i in range(N):
      perm.append(i + 1)
      hungry = test(cows, perm, M, min_hungry)
      if hungry < min_hungry:
        hungry, perm_ = search(cows, perm, M, served, min_perm, min_hungry)
        if hungry < min_hungry:
          min_hungry = hungry
          min_perm = perm_
      perm.pop(-1)
  return min_hungry, min_perm

def test(cows, perm, M, min_hungry):
  taken = [False] * (M + 1)
  hungry = 0
  for i in perm:
    first, second = cows[i - 1]
    if hungry > min_hungry:
      break
    if not taken[first]:
      taken[first] = True
    elif not taken[second]:
      taken[second] = True
    else:
      hungry += 1
  return hungry
  