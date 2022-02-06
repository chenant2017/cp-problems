import sys 

def get_stopped(cows, cows_N, cows_E):
  stopped_by = [None] * len(cows)

  for n in cows_N:
    for e in cows_E:
      if stopped_by[n] is None and stopped_by[e] is None:
        x_n, y_n = cows[n]
        x_e, y_e = cows[e]
        dist_n = y_e - y_n
        dist_e = x_n - x_e

        if dist_n > 0 and dist_e > 0:
          if dist_n < dist_e :
            stopped_by[e] = n
          elif dist_e < dist_n:
            stopped_by[n] = e
  
  return stopped_by

def get_blame(stopped_by):
  blame = [0] * len(stopped_by)
  visited = set()
  for i in range(len(stopped_by)):
    cumu_blame = 0
    curr = i
    while curr is not None:
      blame[curr] += cumu_blame
      if curr not in visited:
        cumu_blame += 1
      visited.add(curr)
      curr = stopped_by[curr]
  return blame


def Run(input, output):
  with input as fin, output as fout:
    N = int(fin.readline())
    cows_N = []
    cows_E = []
    cows = []

    for i in range(N):
      dir, x, y, = (i for i in fin.readline().split())
      if dir == "N":
        cows_N.append(i)
      else: 
        cows_E.append(i)
      cows.append((int(x), int(y)))

    cows_N = sorted(cows_N, key=lambda x: cows[x][0])
    cows_E = sorted(cows_E, key=lambda x: cows[x][1])

    #print(cows_N)
    #print(cows_E)

    stopped_by = get_stopped(cows, cows_N, cows_E)
    #print("stopped_by", stopped_by)
    
    blame = get_blame(stopped_by)
    
    for i in blame:
      fout.write("{}\n".format(i))

Run(sys.stdin, sys.stdout)
    