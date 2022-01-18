def test_D(D, grass, N):
  print("D", D)
  pos = grass[0][0]
  length = grass[-1][-1]
  cows_placed = 0
  interval = 0

  while pos <= length:
    print("pos", pos)
    distance = grass[interval][1] - pos
    cows_placed += distance // D + 1
    pos += D * cows_placed

    while interval < len(grass) and grass[interval][1] < pos:
      interval += 1
    print("interfva pos", interval, pos)
    if interval == len(grass):
      break
    if pos < grass[interval][0]:
      pos = grass[interval][0]
  print("cows placed", cows_placed)
  if cows_placed < N:
    return False
  return True
      




def bin_search(min_space, max_space, grass, N):
  best = min_space
  jump = (best + max_space) // 2
  while jump > 0:
    if test_D(best + jump, grass, N):
      best += jump
    else:
      jump //= 2 
  return best
  


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