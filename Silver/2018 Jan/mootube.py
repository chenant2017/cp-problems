def iter_dfs(start, adj, k):
  ans = 0
  stack = [start]
  visited = set()
  while len(stack) > 0:
    curr = stack.pop(0)
    visited.add(curr)
    ans += 1
    for i in adj[curr]:
      next, r = i
      if r >= k and next not in visited:
        stack.append(next)
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
      ans = iter_dfs(v, adj, k) - 1
      fout.write("{}\n".format(ans))

Run("mootube.in", "mootube.out")