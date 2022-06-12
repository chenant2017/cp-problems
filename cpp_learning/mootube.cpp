#include <bits/stdc++.h>
#include <cmath>

#define ll long long
#define MAXN 5010

using namespace std;
ll N, Q;
vector<pair<ll, ll>> adj[MAXN];
set<ll> visited;

ll solve(ll K, ll V) {
	//cout << V <<"\n";
	ll ans = 0;
	if (visited.find(V) != visited.end()) {
		return ans;
	}
	visited.insert(V);
	ans++;
	for (auto i: adj[V]) {
		if (visited.find(i.first) == visited.end() && i.second >= K) {
			ans += solve(K, i.first);
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "mootube";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> Q;

	for (ll i = 0; i < N - 1; i++) {
		ll p, q, r;
		cin >> p >> q >> r;

		pair<ll, ll> adjp = {q, r};
		pair<ll, ll> adjq = {p, r};

		adj[p].push_back(adjp);
		adj[q].push_back(adjq);
	}

	for (ll i = 0; i < Q; i++) {
		ll K, V;
		cin >> K >> V;
		visited.clear();
		cout << solve(K, V) - 1 << "\n";
	}

	return 0;
}