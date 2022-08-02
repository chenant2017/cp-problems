#include <bits/stdc++.h>
#include <cmath>

#define ll long long
#define MAXN 100010

using namespace std;

ll N;
vector<ll> adj[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "planting";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

	for (ll i = 0; i < N - 1; i++) {
		ll a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	ll ans = 0;

	for (ll i = 1; i <= N; i++) {
		ll adj_size = adj[i].size();
		if (adj_size > ans) {
			ans = adj_size;
		}
	}

	cout << ans + 1 << "\n";

	return 0;
}