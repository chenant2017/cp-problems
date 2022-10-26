#include <bits/stdc++.h>
#define MAXV 2510
#define f first  
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N, M, S;
ll dists[MAXV];
bool visited[MAXV] = {false};
vector<pll> adj[MAXV];

void solve() {
	dists[S] = 0;
	priority_queue<pll, vector<pll>, greater<pll>> q;
	q.push(pll({0, S})); 

	while (!q.empty()) {
		auto c = q.top().s;
		q.pop();

		if (visited[c]) continue;
		visited[c] = true;

		for (auto i: adj[c]) {
			dists[i.s] = min(dists[c] + i.f, dists[i.s]);
			q.push(pll({dists[i.s], i.s}));
		} 
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "dijkstra";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M >> S;

	for (ll i = 0; i < M; i++) {
		ll A, B, C;
		cin >> A >> B >> C;
		adj[A].push_back(pll({C, B}));
		adj[B].push_back(pll({C, A}));
	}

	for (ll i = 1; i <= N; i++) {
		dists[i] = 10010;
	}

	solve();

	for (ll i = 1; i <= N; i++) {
		if (dists[i] == 10010) cout << "-1\n";
		else cout << dists[i] << "\n";
	}

	return 0;
}