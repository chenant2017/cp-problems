"""
ID: chenant1
LANG: PYTHON3
TASK: wormhole
"""

def get_pairings(points, pairings, good):
  unfilled = []
  for i in range(len(pairings)):
    if pairings[i] == -1:
      unfilled.append(i)
  if len(unfilled) == 0:
    walk = walking(organize(points))
    if has_cycle(walk, pairings):
      good += 1
  else:
    for j in range(1, len(unfilled)):
      pairings[unfilled[0]] = unfilled[j]
      pairings[unfilled[j]] = unfilled[0]
      good = get_pairings(points, pairings, good) 
      pairings[unfilled[0]] = -1
      pairings[unfilled[j]] = -1
  return good

def has_cycle(walk, pairing):
  result = None
  loc = -1
  for i in range(len(pairing)):
    loc = i
    for j in range(len(pairing)):
      loc = walk[pairing[loc]]
      if loc == None:
        break
    if loc != None:
      return True
  return False

    
def organize(points):
  points = sorted(points)
  result = {}
  for i, p in enumerate(points):
    if p[1] in result:
      result[p[1]].append(i)
    else:
      result[p[1]] = [i]
  return result

def walking(organized):
  result = {}
  xs = organized.values()
  for x in xs:
    for i in range(len(x) - 1):
      result[x[i]] = x[i + 1]
    result[x[-1]] = None
  return result
  
with open('wormhole.in', 'r') as fin, open('wormhole.out', 'w') as fout:
  fin.readline()
  points = []
  for l in fin.readlines():
    point = [int(i) for i in l.strip().split()]
    points.append(point)
  pairings = {}
  for i in range(len(points)):
    pairings[i] = -1
  good = get_pairings(points, pairings, 0)
  fout.write(str(good) + "\n")
  
  