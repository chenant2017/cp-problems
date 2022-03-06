import sys 
import heapq

def Run(fin, fout):
  T = int(fin.readline())
  for t in range(T):
    #print()
    #print("t", t)
    M, N, K = (int(i) for i in fin.readline().split())
    f = [int(i) for i in fin.readline().split()]
    if check(f, M, K):
      fout.write("YES\n")
    else:
      fout.write("NO\n")

def check(f, M, K):
  mail = [0] * (M + 1)
  curr = 0
  a = 1
  b = K + 1
  #min_mail = {M}

  for i in range(len(f)):
    #print(f[i], "curr", curr, mail, range(a, b))
    if curr < K:
      if f[i] not in range(a, b):
        mail[f[i]] += 1
        curr += 1
        #min_mail.add(f[i])
    else:
      if K + b <= M:
        a = b
        b = K + b
      else:
        a = M + 1 - K
        b = M + 1
      for j in range(a, b):
        if mail[j] > 0:
          curr -= mail[j]
          mail[j] = 0
          #min_mail.remove(j)
      if f[i] not in range(a, b):
        mail[f[i]] += 1
        curr += 1 
        #min_mail.add(f[i])
  
  #min_mail_ = min(min_mail)
  for i in range(M - K, M + 1):
    if i > M:
      break
    curr -= mail[i]
  
  return True if curr == 0 else False

Run(sys.stdin, sys.stdout)