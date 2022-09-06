#include <bits/stdc++.h>
#define MAXN 50010
#define f first  
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N, M;
ll dists[MAXN];
bool visited[MAXN] = {false};
vector<pll> adj[MAXN];

void solve() {
	dists[1] = 0;
	priority_queue<pll, vector<pll>, greater<pll>> q;
	q.push(pll({0, 1})); 

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
	
	string fname = "amazon";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;

	for (ll i = 0; i < M; i++) {
		ll A, B, C;
		cin >> A >> B >> C;
		adj[A].push_back(pll({C, B}));
		adj[B].push_back(pll({C, A}));
	}

	for (ll i = 1; i <= N; i++) {
		dists[i] = 1000 * 50000;
	}

	solve();

	cout << dists[N] << "\n";

	return 0;
}