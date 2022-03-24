import sys
import io
import os
from collections import deque

def Run(input, output):
  
  readline = io.BytesIO(
      os.read(
        input, 
        os.fstat(input).st_size
      )
    ).readline
  ## input using readline()
  ## output using fout.write()

  N = int(readline())
  
  elsie1 = []
  elsie2 = []

  bessie = set(range(1, 2*N + 1))

  for i in range(N//2):
    card = int(readline())
    elsie1.append(card)
    bessie.remove(card)
  for i in range(N//2):
    card = int(readline())
    elsie2.append(card)
    bessie.remove(card)
  
  elsie1 = deque(sorted(elsie1))
  elsie2 = deque(sorted(elsie2))

  bessie = sorted(bessie)
  bessie2 = deque(bessie[:N//2])
  bessie1 = deque(bessie[N//2:])

  score = 0

  while bessie1:
    if bessie1[-1] < elsie1[-1]: 
      b = bessie1.pop()
      e = elsie1.popleft()
      if b > e: 
        score += 1
    else:
      score += 1
      bessie1.pop()
      elsie1.pop()
  
  while bessie2: 
    if bessie2[-1] > elsie2[-1]:
      b = bessie2.pop()
      e = elsie2.popleft()
      if b < e:
        score += 1
    else:
      score += 1
      bessie2.pop()
      elsie2.pop()
  
  output.write("{}\n".format(score))


def RunFileWrapper(input, output):
  fin = os.open(input, os.O_RDONLY)
  with open(output, 'w') as fout:
    stringio = io.StringIO()
    Run(fin, stringio)
    fout.write(stringio.getvalue())
  os.close(fin)

RunFileWrapper("cardgame.in", "cardgame.out")