
def isGood(n, digits_set):
  b = True
  for c in str(n):
    if int(c) not in digits_set:
      b = False
      break
  return b

with open('crypt1.in', 'r') as fin, open('crypt1.out', 'w') as fout:
  fin.readline()
  digits = [int(i) for i in fin.readline().strip().split()]
  digits_set = set(digits)
  good = 0
  for a_ in digits:
    for b_ in digits:
      for c_ in digits:
        for d_ in digits:
          for e_ in digits:
            abc = int(str(a_) + str(b_) + str(c_))
            de = int(str(d_) + str(e_))
            if abc * e_ < 1000 and abc * d_ < 1000:
              if isGood(abc * d_, digits_set) and isGood(abc * e_, digits_set) and isGood(abc * de, digits_set):
                print(abc, de, abc * de)
                good += 1
  fout.write(str(good))