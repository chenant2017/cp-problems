def method(base, fin, fout):
  def tobase10(n):
    base10 = 0
    n = str(n)
    for i in range(len(n)):
      a = int(n[i])* base **(len(n) - 1 - i)
      base10 += a
    return base10

  def tobase(n10):
    n = ""
    start = math.floor(math.log(n10, base))
    for i in range(start, -1, -1):
      p = 0
      while n10 >= 0:
        n10 -= base**i
        p += 1
      n10 += base**i
      n += str(p - 1)
    return int(n)

  def square(n):
    return tobase(tobase10(n)**2)
  
  def is_pal(n):
    n = str(n)
    for c in range(len(n)//2):
      if n[c] != n[len(n) - 1 - c]:
        return False
    return True
  
  for N in range(1, 300):
    if is_pal(square(N), fin, fout):
      fout.write(str(tobase(N)) + " " + str(square(N)) + "\n")
  fout.write("\n")

with open('palsquare.in', 'r') as fin, open('palsquare.out', 'w') as fout:
  method(int(fin.readline().strip()), fin, fout)