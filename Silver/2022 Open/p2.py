import sys
import os
import io

def Run(fin, fout):
  readline = io.BytesIO(
      os.read(
        fin, 
        os.fstat(fin).st_size
      )
    ).readline
  S = readline().strip()
  T = readline().strip()
  Q = int(readline())

  compat = [[False for _ in range(18)] for __ in range(18)]

  bad = set()

  for c1 in range(18):
    for c2 in range(c1, 18):
      works = True

      ch1 = ord('a') + c1
      ch2 = ord('a') + c2

      p1 = 0
      p2 = 0

      works = True

      while True:
        while p1 < len(S) and S[p1] != ch1 and S[p1] != ch2:
          p1 += 1
        while p2 < len(T) and T[p2] != ch1 and T[p2] != ch2:
          p2 += 1
        if p1 == len(S) or p2 == len(T):
          works = p1 == len(S) and p2 == len(T)
          break
        if S[p1] == T[p2]:
          p1 += 1
          p2 += 1
        else:
          works = False
          break
      
      if works:
        compat[c1][c2] = True
        compat[c2][c1] = True
  '''for c in compat:
    print(c)'''
  
  for q in range(Q):
    query = readline().strip()
    works = True
    for c1 in range(len(query)):
      q1 = query[c1]
      char1 = q1 - ord('a')
      for c2 in range(c1, len(query)):
        q2 = query[c2]
        char2 = q2 - ord('a')
        #print(q1, q2, char1, char2)
        if not compat[char1][char2]:
          works = False
          break
      if not works:
        break
    if works:
      fout.write("Y")
    else:
      fout.write("N")
  
  fout.write("\n")
            
      
Run(0, sys.stdout)
  