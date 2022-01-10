import sys

def get_abc(nums): #a <= b <= c
  a_b_c = nums[-1]
  a = nums[0]
  b_c = find_sums(nums, a_b_c - a)
  for b, c in b_c:
    #print(b, c)
    if a + nums[b] in nums and a + nums[c] in nums:
      return a, nums[b], nums[c]

def find_sums(nums, rsum): #rsum is required sum
  possible = []
  for i in range(1, len(nums) - 1):
    for j in range(i + 1, len(nums) - 1):
      #print(nums[i], nums[j])
      if nums[i] + nums[j] == rsum:
        possible.append([i, j])
  return possible

with sys.stdin as fin, sys.stdout as fout:
  nums = sorted([int(i) for i in fin.readline().split()])
  a, b, c = get_abc(nums)
  fout.write(str(a) + " " + str(b) + " " + str(c) + "\n")
