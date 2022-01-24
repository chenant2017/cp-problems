def dfs(start, adj, rels_1, min_rel):
  rels_1[start] = min_rel 
  for i in adj[start]:
    node, r = i
    if rels_1[node] is None:
      if r < min_rel:
        temp_min_rel = r
      else:
        temp_min_rel = min_rel
      dfs(node, adj, rels_1, temp_min_rel)

def Run(input, output):
  with open(input, 'r') as fin, open(output, "w") as fout:
    N, Q = (int(i) for i in fin.readline().split())
    rels_1 = [None] * (N + 1) #also functions as visited
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

    dfs(1, adj, rels_1, 10**9)

    for i in range(Q):
      k, v = (int(i) for i in fin.readline().split())
      ans = 0
      for i in range(1, N + 1):
        if i == v:
          continue
        if min(rels_1[v], rels_1[i]) >= k:
          ans += 1
      fout.write("{}\n".format(ans))

Run("mootube.in", "mootube.out")