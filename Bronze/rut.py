import sys
class Cow:
  def __init__(self, attributes):
    self.direction = attributes[0]
    self.x = int(attributes[1])
    self.y = int(attributes[2])
    self.stop = float("inf")

  def move(self):
    if direction == "E":
      self.x += 1
    elif direction == "N":
      self.y += 1

  def get_direction(self):
    return self.direction

  def get_x(self):
    return self.x
  
  def get_y(self):
    return self.y
  
  def get_stop(self):
    return self.stop
    
  def set_stop(self, stop):
    if stop < self.stop:
      self.stop = stop
  
  def set_stop2(self, stop):
    self.stop = stop
  
  def __str__(self):
    if self.stop == float("inf"):
      return "Infinity"
    else:
      return str(self.stop)

def get_stops(e_cows, n_cows):
  n_cows = sort_x(n_cows)
  e_cows = sort_y(e_cows)
  for e in e_cows:
    for n in n_cows:
      e_dist = n.get_x() - e.get_x() 
      n_dist = e.get_y() - n.get_y()
      if e_dist > 0 and n_dist > 0:
        if e_dist > n_dist and n.get_stop() > n_dist:
          e.set_stop(e_dist)
        elif n_dist > e_dist and e.get_stop() > e_dist:
          n.set_stop(n_dist)

def sort_x(cows):
  xs = []
  for c in cows:
    xs.append(c.get_x())
  xs = sorted(xs)
  result = []
  for x in xs:
    for c in cows:
      if c.get_x() == x:
        result.append(c)
  return result

def sort_y(cows):
  ys = []
  for c in cows:
    ys.append(c.get_y())
  ys = sorted(ys)
  result = []
  for y in ys:
    for c in cows:
      if c.get_y() == y:
        result.append(c)
  return result


with sys.stdin as fin, sys.stdout as fout:
  fin.readline()
  cows = []
  n_cows = []
  e_cows = []
  lines = fin.readlines()
  for l in lines:
    cow = Cow(l.split())
    if cow.get_direction() == "E":
      e_cows.append(cow)
    else:
      n_cows.append(cow)
    cows.append(cow)
  get_stops(e_cows, n_cows)
  for c in cows:
    fout.write(str(c) + "\n")
