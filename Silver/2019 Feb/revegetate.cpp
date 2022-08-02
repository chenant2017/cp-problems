#include <bits/stdc++.h>

#define ll long long
#define MAX 100010
#define f first
#define s second

using namespace std;

ll N, M;

vector<pair<ll, ll>> adj[MAX];
ll colors[MAX] = {0};

ll floodfill(ll start, ll color) {
	if (colors[start] != 0) {
		if (colors[start] == color) {
			return 1;
		}
		return 0;
	}

	colors[start] = color;

	for (auto& i: adj[start]) {
		ll ff = floodfill(i.f, color * i.s);
		if (ff == 0) {
			return 0;
		}
	}

	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "revegetate";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;

	for (ll i = 0; i < M; i++) {
		ll a, b;
		string sd;
		cin >> sd >> a >> b;

		if (sd[0] == 'S') {
			adj[a].push_back({b, 1});
			adj[b].push_back({a, 1});
		}
		else {
			adj[a].push_back({b, -1});
			adj[b].push_back({a, -1});
		}
	}

	ll comps = 0;	

	for (ll i = 1; i <= N; i++) {
		if (colors[i] != 0) {
			continue;
		}
		ll ff = floodfill(i, 1);
		if (ff == 0) {
			cout << "0\n";
			return 0;
		}
		comps++;
	}

	cout << "1";
	for (ll i = 0; i < comps; i++) {
		cout << "0";
	}

	cout << "\n";

	return 0;
}