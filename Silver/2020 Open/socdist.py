def test_D(D, grass, N):
  pos = grass[0][0]
  length = grass[-1][-1]
  cows_placed = 0
  interval = 0

  while pos <= length:
    distance = grass[interval][1] - pos
    new_cows = distance // D + 1
    cows_placed += new_cows
    if cows_placed >= N:
      return True
    pos += D * new_cows

    interval = bin_search_interval(interval, grass, pos)

    if interval == len(grass):
      break

    if pos < grass[interval][0]:
      pos = grass[interval][0]
    
  if cows_placed < N:
    return False
  return True

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