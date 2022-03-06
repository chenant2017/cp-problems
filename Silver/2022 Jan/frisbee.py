from collections import deque
import sys

def Run(input, output):
  with input as fin, output as fout:
    N = int(fin.readline())
    cows = [int(i) for i in fin.readline().split()]

    sum = 0

    sum += get_sum(cows)
    sum += get_sum(cows[::-1]) 

    fout.write("{}\n".format(sum))


def get_sum(cows):
  N = len(cows)
  sum = 0
  mono_stack = deque([])
  for i in range(N):
    if len(mono_stack) == 0:
      mono_stack.append(i)
    else:
      while mono_stack and cows[i] > cows[mono_stack[-1]]:
        mono_stack.pop()
      if mono_stack:
        sum += i - mono_stack[-1] + 1
        #print(i - mono_stack[-1] + 1, i, mono_stack[-1])
      mono_stack.append(i)
  return sum

Run(sys.stdin, sys.stdout)




