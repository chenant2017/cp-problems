def test_space(space, grass, N):
  cows_placed = 1
  pos = grass[0][0]
  interval = 0
  while pos <= grass[-1][-1] and cows_placed < N: 
    if in_interval(pos + space, grass[interval]):
      cows_placed += 1
      pos += space
    else:
      for i in range(interval + 1, len(grass)):
        if pos + space < grass[i][0]:
          pos = grass[i][0]
          cows_placed += 1
          interval = i
          break
        elif in_interval(pos + space, grass[i]):
          pos += space
          cows_placed += 1
          interval = i
          break
        elif pos + space > grass[-1][-1]:
          return False
  return False if cows_placed < N else True

def in_interval(pos, interval):
  return True if (pos >= interval[0] and pos <= interval[1]) else False


def bin_search(min_space, max_space, grass, N):
  best = min_space
  jump = (min_space + max_space) // 2
  while jump > 0:
    if test_space(min_space + jump, grass, N):
      min_space += jump
      best = min_space
    else:
      jump //= 2 
  return best
  


def Run(input, output):
  with open(input, 'r') as fin, open(output, "w") as fout:
    N, M = (int(i) for i in fin.readline().split()) #of cows
    grass = []
    for line in fin.readlines():
      start, end = (int(i) for i in line.split())
      grass.append((start, end))
    grass = sorted(grass)
    length = grass[-1][-1]
    max_space = length // (N - 1)
    best = bin_search(1, max_space, grass, N)
    fout.write("{}\n".format(best))

    
    

Run("socdist.in", "socdist.out")