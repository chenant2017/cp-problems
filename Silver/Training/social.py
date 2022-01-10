def is_good(jump, last, nums, N):
  count = 0
  i = nums[0][0]
  k = 0
  while count < N:
    if i > last:
      return False
    while i > nums[k][1] and k < len(nums):
      k += 1
    if k == len(nums):
      return False
    if i < nums[k][0]:
      i = nums[k][0]
    n = (nums[k][1] - i)//jump + 1
    count += n
    i += jump * n
    k += 1
  return True

with open("socdist.in", "r") as fin, open("socdist.out", "w") as fout:
  N, M = (int(i) for i in fin.readline().split())
  nums = []
  for l in range(M):
    line = fin.readline()
    values = line.split()
    r = (int(values[0]), int(values[1]))
    nums.append(r)
  nums = sorted(nums, key=lambda x: x[0])
  last = nums[-1][1]
  k = 0
  n = last//(N - 1)
  i = n//2
  while i > 0:
    while k + i <= n and is_good(k + i, last, nums, N):
      k += i
    i //= 2
  fout.write(str(k) + "\n")
  