def Run(input, output):
  with open(input) as fin, open(output, "w") as fout:
    N = int(fin.readline())
    xs = {}
    ys = {}
    points = set()
    areas = 0
    for l in fin.readlines():
      x, y = (int(i) for i in l.strip().split())
      points.add((x, y))
      if x in xs.keys():
        xs[x].add(y)
      else:
        xs[x] = {y}
      if y in ys.keys():
        ys[y].add(x)
      else:
        ys[y] = {x}
    #print(xs)
    #print(ys)
    #print(points)
    for p in points:
      ydiff = 0
      for y in xs[p[0]]:
        ydiff += abs(p[1] - y)
      xdiff = 0
      for x in ys[p[1]]:
        xdiff += abs(p[0] - x)
      areas += (xdiff * ydiff)
    fout.write("{}\n".format(areas))
    
    #print(areas)

Run("triangles.in", "triangles.out")