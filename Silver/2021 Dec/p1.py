import sys
import io
import os

def Run(input, output):
  
  readline = io.BytesIO(
      os.read(
        input, 
        os.fstat(input).st_size
      )
    ).readline
  
  K, M, N = (int(i) for i in readline().split()) #grass, nhoj, john

  grass = []
  nhoj = []

  for k in range(K):
    (p, t) = (int(i) for i in readline().split())
    grass.append((p, t))
  grass = sorted(grass)
  
  for m in range(M):
    nhoj.append(int(readline()))
  nhoj = sorted(nhoj)

  G = 0
  tasties = [] #will sort
  tasty = 0

  while grass[G][0] < nhoj[0]:
    tasty += grass[G][1]
    G += 1

  tasties.append(tasty)
#--------------
  for n in range(M - 1):
    #print("n", n)
    sub_grass = []
    total = 0

    while grass[G][0] < nhoj[n + 1]:
      sub_grass.append(grass[G])
      total += grass[G][1]
      G += 1

    if len(sub_grass) == 0:
      continue
    
    space = (nhoj[n + 1] - nhoj[n] - 1) // 2
    start = 0
    end = 0
    max_sliding = 0
    sliding = 0

    while True:
      #print(start, end)
      while sub_grass[end][0] - sub_grass[start][0] <= space:
        sliding += sub_grass[end][1]
        end += 1
        if end >= len(sub_grass):
          break
      #print("sliding", sliding)
      if sliding > max_sliding:
        max_sliding = sliding
      if end >= len(sub_grass):
        break
      #sliding += sub_grass[end][1]
      while sub_grass[end][0] - sub_grass[start][0] > space:
        sliding -= sub_grass[start][1]
        start += 1
        if start >= len(sub_grass):
          break
      if start >= len(sub_grass):
        break
    
    tasties.append(max_sliding)
    tasties.append(total - max_sliding)
    #print("appended", max_sliding, total - max_sliding)
  
  tasty = 0
  for g in range(G, K):
    tasty += grass[g][1]
  
  tasties.append(tasty)
  tasties = sorted(tasties, reverse=True)

  ans = 0
  for i in range(N):
    if i > len(tasties) - 1:
      break
    ans += tasties[i]
  
  output.write("{}\n".format(ans))
  #print("ans", ans)

Run(0, sys.stdout)


