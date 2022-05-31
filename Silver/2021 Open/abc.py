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
  
  T = int(readline())
  for t in range(T):
    N = int(readline())
    nums = [int(i) for i in readline().split()]
    if N == 7:
      a, b, c = nums[:3]
      if [a, b, a+b, c, a+c, b+c, a+b+c] == nums or [a, b, c, a+b, a+c, b+c, a+b+c] == nums:
        output.write("1\n")
      else:
        output.write("0\n")
    else:
      output.write("-1\n")

Run(0, sys.stdout)