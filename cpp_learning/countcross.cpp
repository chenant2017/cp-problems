#include <bits/stdc++.h>
#include <cmath>

#define ll long long
#define MAXN 110
#define f first
#define s second

using namespace std;

ll N, K, R;

set<pair<ll, ll>> roads[MAXN][MAXN];
bool visited[MAXN][MAXN] = {false};
set<pair<ll, ll>> cows;
int d1[4] = {0, 0, 1, -1};
int d2[4] = {1, -1, 0, 0};

ll floodfill(pair<ll, ll> start) {
	ll cowcount = 0;
	if (visited[start.f][start.s]) {
		return cowcount;
	}
	visited[start.f][start.s] = true;
	if (cows.find(start) != cows.end()) {
		cowcount++;
	}
	for (int d = 0; d < 4; d++) {
		ll newr = start.f + d1[d];
		ll newc = start.s + d2[d];

		if (1 <= newr && newr <= N &&
			1 <= newc && newc <= N &&
			roads[start.f][start.s].find({newr, newc}) 
			== roads[start.f][start.s].end() &&
			!visited[newr][newc]) {

			cowcount += floodfill({newr, newc});
		}
	}
	return cowcount;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "countcross";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> K >> R;

	for (ll i = 0; i < R; i++) {
		ll r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;

		roads[r1][c1].insert({r2, c2});
		roads[r2][c2].insert({r1, c1});
	}

	for (ll i = 0; i < K; i++) {
		pair<ll, ll> cow;
		cin >> cow.f >> cow.s;
		cows.insert(cow);
	}

	ll ans = K * (K - 1) / 2;

	for (auto& i: cows) {
		if (!visited[i.f][i.s]) {
			ll cowcount = floodfill(i);
			ans -= cowcount * (cowcount - 1) / 2;
		}
	}

	cout << ans << "\n";

	return 0;
}