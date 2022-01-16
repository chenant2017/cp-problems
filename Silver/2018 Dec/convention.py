def Run(input, output):
  with open(input, 'r') as fin, open(output, "w") as fout:
    N, M, C = (int(i) for i in fin.readline().split()) #cows, buses, capacity
    times = sorted([int(i) for i in fin.readline().split()])
    fout.write("{}\n".format((bin_search(0, times[-1] - times[0], times, M, C))))

def bin_search(min, max, times, M, C):
  while min < max - 1:
    #print(min, max)
    mid = (min + max) // 2
    if possible(times, mid, M, C):
      max = mid
    else:
      min = mid
  return max
  
  

def possible(times, max_time, M, C):
  buses_filled = 0
  bus = []
  pos = -1
  while pos < len(times) - 1:
    pos += 1
    if (len(bus) > 0 and times[pos] - bus[0] > max_time) or len(bus) == C:
      #print(bus)
      bus = []
      buses_filled += 1 
    bus.append(times[pos])
  buses_filled += 1
  if buses_filled > M:
    return False
  return True

Run("convention.in", "convention.out")