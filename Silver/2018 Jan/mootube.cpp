#include <bits/stdc++.h>
#include <cmath>

#define ll long long
#define MAXN 5010

using namespace std;
ll N, Q;
vector<pair<ll, ll>> adj[MAXN];

ll solve(ll K, ll V, bool visited[MAXN]) {
	//cout << V <<"\n";
	ll ans = 0;
	if (visited[V]) {
		return ans;
	}
	visited[V] = true;
	ans++;
	for (auto& i: adj[V]) {
		if (!visited[i.first] && i.second >= K) {
			ans += solve(K, i.first, visited);
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
		bool visited[MAXN] = {false};
		cout << solve(K, V, visited) - 1 << "\n";
	}

	return 0;
}