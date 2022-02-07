import sys

def Run(input, output):
  with input as fin, output as fout:
    N = int(fin.readline())

    for i in range(N): ###asdf
      p1, p2 = (int(j) for j in fin.readline().split())
      ops = 0

      while p1 > p2:
        if p1 % 2 == 0:
          ops += 1
        else:
          ops += 2
        p1 = (p1 + 1) // 2

      if p1 == p2:
        fout.write("{}\n".format(ops))

      if p1 < p2:
        min_ops = p2
        pointer = 0
        p2_ = p2
        to_p2 = [p2_]

        while p2_ > 1:
          if p2_ % 2 == 0:
            p2_ //= 2
            to_p2.append(p2_)
          else:
            p2_ -= 1
            to_p2.append(p2_)
        #print(to_p2)
        
        p1_ = p1
        poss_ops = 0
        while p1_ > 1:
          #print("p1_", p1_)
  
          if p1_ <= to_p2[pointer]:
            while pointer < len(to_p2) and p1_ <= to_p2[pointer]:
              pointer += 1
            pointer -= 1

          poss_ops_test = poss_ops + to_p2[pointer] - p1_ + pointer

          if poss_ops_test < min_ops:
            #print(min_ops, p1_, pointer)
            min_ops = poss_ops_test
          
          if p1_ % 2 == 0:
            p1_ //= 2
          else:
            p1_ += 1
          poss_ops += 1

        fout.write("{}\n".format(ops + min_ops))
      
Run(sys.stdin, sys.stdout)