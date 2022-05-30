import sys

def Run(fin, fout):
  readline = fin.readline
  s = [i for i in readline().strip()]
  Q = int(readline())

  prefix = make_prefix(s)

  for q in range(Q):
    a, b = map(int, readline().split())
    a -= 1
    b -= 1
    good = False
    if a == 0:
      if s[b] == "C":
        good = True
    else:
      if result(prefix[b], prefix[a - 1]):
        good = True
    if good:
      fout.write("Y")
    else:
      fout.write("N")

  fout.write("\n")



def make_prefix(s):
  prefix = [s[0] for _ in range(len(s))]
  for i in range(1, len(s)):
    prefix[i] = ch_sum(prefix[i - 1], s[i])
  return prefix
    

def ch_sum(c1, c2):
  if c1 == c2:
    return ""
  if c1 == "" or c2 == "":
    return c1 + c2
  if (c1, c2) == ("C", "W") or (c2, c1) == ("C", "W"):
    return "O"
  if (c1, c2) == ("O", "W") or (c2, c1) == ("O", "W"):
    return "C"
  if (c1, c2) == ("C", "O") or (c2, c1) == ("C", "O"):
    return "W"

def result(c1, c2):
  if (c1, c2) == ("C", "") or (c2, c1) == ("C", ""):
    return True
  if (c1, c2) == ("O", "W") or (c2, c1) == ("O", "W"):
    return True
  return False
  
Run(sys.stdin, sys.stdout)