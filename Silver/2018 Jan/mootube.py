def dfs(start, adj, rels, min_rel, k):
  ans = 0
  rels[start] = min_rel
  if min_rel >= k:
    ans += 1
  for i in adj[start]:
    node, r = i
    if rels[node] is None:
      if r < min_rel:
        temp_min_rel = r
      else:
        temp_min_rel = min_rel
      ans += dfs(node, adj, rels, temp_min_rel, k)
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
      rels = [None] * (N + 1)
      k, v = (int(i) for i in fin.readline().split())
      ans = dfs(v, adj, rels, 10**9, k) - 1
      fout.write("{}\n".format(ans))
      #print(ans)

Run("mootube.in", "mootube.out")