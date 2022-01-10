"""
ID: chenant1
LANG: PYTHON3
TASK: skidesign
"""

def get_money(hills):
  if hills[-1] - hills[0] <= 17:
    return 0
  cases = set()
  for j in range(hills[0], hills[-1] - 17):
    sum = 0
    desired_min = j
    desired_max = j + 17
    print(desired_min, desired_max)
    for k in hills:
      if k < desired_min:
        sum += (desired_min - k)**2
      if k > desired_max:
        sum += (k - desired_max)**2
    print("sum", sum)
    cases.add(sum)
  return min(cases)

with open('skidesign.in', 'r') as fin, open('skidesign.out', 'w') as fout:
  fin.readline()
  hills = sorted([int(i.strip()) for i in fin.readlines()])
  fout.write(str(get_money(hills)) + "\n")
