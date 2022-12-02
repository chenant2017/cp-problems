#include <bits/stdc++.h>

#define ll long long
#define MAXN 40010

using namespace std;

vector<ll> adj[MAXN];
ll B, M, P, N, M;

vector<ll> bfs(ll start) {
	queue<ll> q;
	q.push(start);
	queue<ll> nextq;
	ll dist = 0;
	vector<ll> dists (MAXN, MAXN);

	while (!q.empty()) {
		ll curr = q.front();
		q.pop();
		if (dists[curr] != MAXN) {
			if (q.empty()) {
				swap(q, nextq);
				dist++;
			}
			continue;
		} 

		dists[curr] = dist;

		for (auto i: adj[curr]) {
			if (dists[i] == MAXN) nextq.push(i);
		}

		if (q.empty()) {
			swap(q, nextq);
			dist++;
		}
	}

	return dists;
}	

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "piggyback";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);

	cin >> B >> M >> P >> N >> M;
	
	for (ll i = 0; i < M; i++) {
		ll a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<ll> dists1 = bfs(1);
	vector<ll> dists2 = bfs(2);
	vector<ll> distsN = bfs(N);


	ll ans = N * M + N * B + 10;
	for (ll meet = 1; meet <= N; meet++) {
		ll energy =	dists1[meet] * B + dists2[meet] * M + distsN[meet] * P;
		if (energy < ans) {
			ans = energy;
		}
	}

	cout << ans << "\n";

	return 0;
}