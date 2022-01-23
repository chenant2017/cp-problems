def test_D(D, grass, N):
  pos = -1
  cows_placed = 0
  
  for interval in grass:
    if pos > interval[1]:
      continue
    if pos < interval[0]:
      pos = interval[0]
    cows_placed += 1
    if cows_placed >= N:
      return True
    while pos + D <= interval[1]:
      pos += D
      cows_placed += 1
      if cows_placed >= N:
        return True
    pos += D
  return False

def bin_search(min_space, max_space, grass, N):
  best = min_space
  jump = (max_space - best)
  while jump > 0:
    if test_D(best + jump, grass, N):
      best += jump
    else:
      jump //= 2 
  return best

def bin_search_interval(min_inter, grass, pos):
  max_inter = len(grass)
  while max_inter - min_inter > 1:
    mid_inter = (min_inter + max_inter) // 2
    if grass[mid_inter][1] < pos:
      min_inter = mid_inter
    else:
      max_inter = mid_inter
  return max_inter
   
def Run(input, output):
  with open(input, 'r') as fin, open(output, "w") as fout:
    N, M = (int(i) for i in fin.readline().split()) # N = cows, M = intervals
    grass = []
    for line in fin.readlines():
      start, end = (int(i) for i in line.split())
      grass.append((start, end))
    grass = sorted(grass)

    length = grass[-1][-1]
    max_space = length//N + 1
    best = bin_search(1, max_space, grass, N)
    print(best)
    fout.write("{}\n".format(best))

Run("socdist.in", "socdist.out")