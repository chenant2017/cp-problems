from collections import defaultdict, deque
import sys

def Run(fin_, fout_):
  with fin_ as fin, fout_ as fout:
    T = int(fin.readline())
    for t in range(T):
      M, N, K = (int(i) for i in fin.readline().split())
      line = fin.readline().split()
      last_occur = [None] * (M + 1)
      emails = [None] * (N)
      for i in range(N):
        j = int(line[i])
        emails[i] = j
        last_occur[j] = i
      ans = check(emails, last_occur, M, K)
      if ans:
        fout.write("YES\n")
      else:
        fout.write("NO\n")
    

def check(emails, last_occur, M, K):
  window = deque([])
  skipped = deque([]) 
  pos = 0

  for f_start in range(1, M - K + 2):
    while pos <= last_occur[f_start]:
      if f_start <= emails[pos] <= f_start + K - 1:
        pos += 1
        continue
      if len(window) < K:
        window.append(emails[pos])
      else:
        skipped.appendleft(window.popleft())
        window.append(emails[pos])
      pos += 1
  
  f_start = M - K + 1
  
  window2 = deque([])
  window.reverse()
  for i in window + skipped:
    if f_start <= i <= f_start + K - 1:
      continue
    if len(window) < K:
      window2.append(i)
    else:
      return False
  return True

Run(sys.stdin, sys.stdout)