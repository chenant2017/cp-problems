"""
ID: chenant1
LANG: PYTHON3
TASK: barn1
"""

with open('barn1.in', 'r') as fin, open('barn1.out', 'w') as fout:
  required = fin.readline().strip().split()
  boards = int(required[0])
  stalls = int(required[1])
  cows = int(required[2])
  occupied = set()

  while True:
    line = fin.readline()
    if not line:
      break
    occupied.add(int(line.strip()))

  start = 0
  end = 0
  prev = False

  intervals = []

  for i in range(1, stalls + 1):
    if i in occupied and prev == False:
      prev = True
      start = i
      end = i
    elif i in occupied and prev == True:
      end = i
    elif i not in occupied and prev == True:
      intervals.append([start, end])
      prev = False
  
  if prev == True:
      intervals.append([start, end])

  if len(intervals) <= boards:
    total = 0
    for i in intervals:
      total += i[1] - i[0] + 1
    print(total)

  while len(intervals) > boards:
    differences = []
    for j in range(len(intervals) - 1):
      differences.append(intervals[j + 1][0] - intervals[j][1])
    min_index = differences.index(min(differences))
    intervals[min_index:(min_index+2)] = ([[intervals[min_index][0], intervals[min_index + 1][1]]])

  result = 0
  for i in intervals:
    result += i[1]-i[0]+1
  print("RESULT", result)
  fout.write(str(result) + "\n")