def bfs(required, start, C):
  good = []
  queue = [start]
  moves = 0
  visited = set()
  while len(queue) != 0 and moves <= C:
    #print(queue)
    to_add = []
    for i in range(len(queue)):
      x = queue.pop(0)
      if is_good(required, x) and moves == C:
        good.append(x)
      for c in [btn1(x.copy()), btn2(x.copy()), btn3(x.copy()), btn4(x.copy())]:
        if tuple(c) not in visited:
          to_add.append(c)
          visited.add(tuple(c))
    visited = set()
    queue = to_add
    moves += 1
  #print(queue)
  return good

"""
ID: chenant1
LANG: PYTHON3
TASK: lamps
"""
def btn1(state):
  result = state
  for i in range(len(result)):
    result[i] = change(result[i])
  return result

def btn2(state):
  result = state
  result[0] = change(result[0])
  result[3] = change(result[3])
  return result

def btn3(state):
  result = state
  result[1] = change(result[1])
  result[2] = change(result[2])
  return result

def btn4(state):
  result = state
  result[0] = change(result[0])
  result[1] = change(result[1])
  return result

def change(n):
  if n == 1:
    return 0
  else:
    return 1

def get_condition(i, n):
  if n == 0:
    return int(i) % 6 == 1
  elif n == 1:
    return int(i) % 6 == 4
  elif n == 2:
    return int(i) % 6 == 0 or int(i) % 6 == 2
  else:
    return int(i) % 6 == 3 or int(i) % 6 == 5
  
def is_good(required, state):
  for i in range(len(required)):
    if not (required[i] == state[i] or required[i] == None):
      return False
  return True

def string(solution, N):
  string = ""
  for i in range(1, N + 1):
    if i % 6 == 1:
      string += str(solution[0])
    elif i % 6 == 4:
      string += str(solution[1])
    elif i % 6 == 0 or i % 6 == 2:
      string += str(solution[2])
    elif i % 6 == 3 or i % 6 == 5:
      string += str(solution[3]) 
  return string
  

with open("lamps.in", "r") as fin, open("lamps.out", "w") as fout:
  #groups mod 6: 1, 4, 0 and 2, 3 and 5
  N = int(fin.readline())
  C = int(fin.readline())
  on = fin.readline().split()[:-1]
  off = fin.readline().split()[:-1]
  possible = True
  required = [None for i in range(4)]

  for i in off:
    for n in range(4):
      if get_condition(i, n):
        required[n] = 0 
  for i in on: 
    for n in range(4):
      if get_condition(i, n):
        if required[n] == 0:
          possible = False
          break
        required[n] = 1
  print(required)

  if possible:
    solutions = bfs(required, [1, 1, 1, 1], C)
    print("solutions", solutions)
    if len(solutions) == 0:
      fout.write("IMPOSSIBLE\n")
    else:
      str_solutions = [string(i, N) for i in solutions]
      for s in sorted(str_solutions):
        fout.write(s + "\n")
  else:
    fout.write("IMPOSSIBLE\n")