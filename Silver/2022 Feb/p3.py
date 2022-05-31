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
  last_start = 1
  for f_start in range(1, M - K + 2):
    if last_occur[f_start] is not None:
      while pos <= last_occur[f_start]:
        last_start = f_start
        if f_start <= emails[pos] <= f_start + K - 1:
          pos += 1
          continue
        if len(window) < K: 
          window.append(emails[pos])
        else:
          skipped.appendleft(window.popleft())
          window.append(emails[pos])
        pos += 1
  
  window.reverse()
  emails = window + skipped
  last_occur = [None] * (M + 1)
  pos = 0

  for i in range(len(emails)):
    last_occur[emails[i]] = i
  
  window = deque([])
  for f_start in range(last_start, M - K + 2):
    if last_occur[f_start] is not None:
      while pos <= last_occur[f_start]:
        if f_start <= emails[pos] <= f_start + K - 1:
          pos += 1
          continue
        if len(window) < K: 
          window.append(emails[pos])
        else:
          return False
        pos += 1
  if len(window) > 0:
    return False
  return True
  
Run(sys.stdin, sys.stdout)