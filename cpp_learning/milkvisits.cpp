#include <bits/stdc++.h>
#include <cmath>

#define ll long long
#define MAXN 100010

using namespace std;

ll N, M;

vector<ll> adj[MAXN];
ll comps[MAXN] = {0};
string milks;

void floodfill(ll start, ll comp) {
	if (comps[start] != 0) {
		return;
	}

	comps[start] = comp;

	for (auto i: adj[start]) {
		if (comps[i] == 0 && milks[i] == milks[start]) {
			floodfill(i, comp);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "milkvisits";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;

	cin >> milks;
	milks.insert(0, " ");

	for (ll i = 0; i < N - 1; i++) {
		ll x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	ll comp = 1;

	for (ll i = 1; i <= N; i++) {
		if (comps[i] == 0) {
			floodfill(i, comp);
			comp++;
		}
	}

	for (ll i = 0; i < M; i++) {
		ll a, b;
		string milk;
		cin >> a >> b >> milk;

		if (comps[a] != comps[b]) {
			cout << "1";
		}
		else {
			if (milks[a] == milk[0]) {
				cout << "1";
			}
			else {
				cout << "0";
			}
		}
	}

	cout << "\n";

	return 0;
}