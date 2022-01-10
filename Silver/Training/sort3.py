"""
ID: chenant1
LANG: PYTHON3
TASK: sort3
"""

def get_next_turn():
  positions = None
  wrong = [get_wrong(i + 1) for i in range(3)] #[num_section - 1][num - 1]
  for i in [0, 1]:
    for j in range(i + 1, 3):
      if wrong[i][j] is not None:
        if wrong[j][i] is not None:
          return (wrong[i][j], wrong[j][i])
        if not positions:
          if wrong[j - 1][i] is not None:
            positions = (wrong[i][j], wrong[j - 1][i])
          elif wrong[j - 2][i] is not None:
            positions = (wrong[i][j], wrong[j - 2][i])
  return positions
  
def is_right(value, num):
  return final[num] == value

def get_ranges():
  nums = [0, 0, 0, 0]
  for i in final:
    nums[i] += 1
  for i in range(1, len(nums)):
    nums[i] += nums[i-1]
  return nums

def get_wrong(n):
  result = [None, None, None]
  c = 0
  for i in range(ranges[n - 1], ranges[n]):
    num = sequence[i]
    num_i = num - 1
    if num != n and result[num_i] is None:
      result[num_i] = i
      c += 1
      if c == 2:
        return result
  return result

with open("sort3.in", "r") as fin, open("sort3.out", "w") as fout:
  fin.readline()
  sequence = [int(i) for i in fin.readlines()]
  final = sorted(sequence)
  ranges = get_ranges()   
  swaps = 0
  while True:
    next = get_next_turn()
    if next is None:
      break
    i, j = next
    sequence[i], sequence[j] = sequence[j], sequence[i]
    swaps += 1
  fout.write("{}\n".format(swaps))
