import sys

def solve(daisies):
  result = 0
  for i in range(len(daisies)):
    for j in range(i, len(daisies)):
      flowers = {}
      for k in range(i, j + 1):
        if daisies[k] not in flowers:
          flowers[daisies[k]] = 0
        flowers[daisies[k]] += 1
      #print(flowers)
      total = 0
      for k in flowers.keys():
        total += k * flowers[k]
      avg = total/(j + 1 - i)
      #print("avg", avg)
      if avg in flowers:
        #print("result adds", flowers[avg])
        result += 1
        #print("result is", result)
  return result

with sys.stdin as fin, sys.stdout as fout:
  fin.readline()
  daisies = [int(i) for i in fin.readline().split()]
  fout.write(str(solve(daisies)) + "\n")



      
