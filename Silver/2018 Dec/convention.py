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
  bus_start = times[0]
  bus_cows = 0
  pos = 0
  while pos < len(times):
    if (bus_cows > 0 and times[pos] - bus_start > max_time) or bus_cows == C:
      #print(bus)
      bus_start = times[pos]
      bus_cows = 0
      buses_filled += 1 
    bus_cows += 1
    pos += 1
  buses_filled += 1
  if buses_filled > M:
    return False
  return True

Run("convention.in", "convention.out")