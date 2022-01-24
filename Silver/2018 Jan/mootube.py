def dfs(start, parent, adj, k):
  ans = 1
  for i in adj[start]:
    node, r = i
    if r < k or node == parent:
      continue
    ans += dfs(node, start, adj, k)
  return ans

def Run(input, output):
  with open(input, 'r') as fin, open(output, "w") as fout:
    N, Q = (int(i) for i in fin.readline().split())
    adj = {}
    for i in range(N - 1):
      p, q, r = (int(i) for i in fin.readline().split())

      if p in adj.keys():
        adj[p].add((q, r))
      else:
        adj[p] = {(q, r)}

      if q in adj.keys():
        adj[q].add((p, r))
      else:
        adj[q] = {(p, r)}

    for i in range(Q):
      k, v = (int(i) for i in fin.readline().split())
      ans = dfs(v, -1, adj, k) - 1
      fout.write("{}\n".format(ans))

Run("mootube.in", "mootube.out")