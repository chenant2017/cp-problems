#include <bits/stdc++.h>

#define ll long long
#define f first
#define s second
#define MAX 110

using namespace std;

ll x, y, k, m;
bool visited[MAX][MAX];

ll bfs(pair<ll, ll> start) {
	queue<pair<ll, ll>> q;
	q.push(start);
	ll ans = 3 * MAX;
	ll level = 0;

	queue<pair<ll, ll>> nextq;

	while (level <= k && !q.empty()) {
		pair<ll, ll> curr = q.front();
		q.pop();

		if (visited[curr.f][curr.s]) continue;

		visited[curr.f][curr.s] = true;

		ll m_prime = abs(m - (curr.f + curr.s));
		if (m_prime < ans) {
			ans = m_prime;
		}

		pair<ll, ll> next = curr;

		next.f = x;
		if (!visited[next.f][next.s]) nextq.push(next);
		next.f = curr.f;

		next.s = y;
		if (!visited[next.f][next.s]) nextq.push(next);
		next.s = curr.s;

		next.f = 0;
		if (!visited[next.f][next.s]) nextq.push(next);
		next.f = curr.f;

		next.s = 0;
		if (!visited[next.f][next.s]) nextq.push(next);
		next.s = curr.s;

		ll transfer = min(curr.f, y - curr.s);
		next.f -= transfer;
		next.s += transfer;
		if (!visited[next.f][next.s]) nextq.push(next);
		next = curr;

		transfer = min(x - curr.f, curr.s);
		next.f += transfer;
		next.s -= transfer;
		if (!visited[next.f][next.s]) nextq.push(next);
		next = curr;

		if (q.empty()) {
			swap(nextq, q);
			level++;
		}
	}

	return ans;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "pails";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> x >> y >> k >> m;

	ll ans = bfs(pair<ll, ll>({0, 0}));

	cout << ans << "\n";

	return 0;
}