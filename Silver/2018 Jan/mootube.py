def bfs(start, adj, k, N):
  ans = -1
  queue = [(-1, start)]
  while queue:
    parent, curr = queue.pop(0)
    ans += 1
    for next, r in adj[curr].items():
      if next != parent and r >= k:
        queue.append((curr, next))
  return ans


def Run(input, output):
  with open(input, 'r') as fin, open(output, "w") as fout:
    N, Q = (int(i) for i in fin.readline().split())
    adj = {}
    for i in range(N - 1):
      p, q, r = (int(i) for i in fin.readline().split())

      if p in adj:
        adj[p][q] = r
      else:
        adj[p] = {q: r}

      if q in adj:
        adj[q][p] = r
      else:
        adj[q] = {p: r}

    for i in range(Q):
      k, v = (int(i) for i in fin.readline().split())
      ans = bfs(v, adj, k, N)
      fout.write("{}\n".format(ans))
      
Run("mootube.in", "mootube.out")