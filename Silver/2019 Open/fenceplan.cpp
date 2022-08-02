#include <bits/stdc++.h>
#include <cmath>

#define ll long long
#define MAXN 100010

using namespace std;

struct Cow {
	ll x, y;
};

Cow cows[MAXN];
ll minx, miny, maxx, maxy;
ll N, M;
vector<ll> adj[MAXN];
bool visited[MAXN] = {false};

void floodfill(ll start) {
	if (visited[start]) {
		return;
	}
	visited[start] = true;
	
	ll sx = cows[start].x;
	ll sy = cows[start].y;

	if (sx < minx) {
		minx = sx;
	}
	if (sx > maxx) {
		maxx = sx;
	}
	if (sy < miny) {
		miny = sy;
	}
	if (sy > maxy) {
		maxy = sy;
	}

	for (auto i: adj[start]) {
		if (!visited[i]) {
			floodfill(i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "fenceplan";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;

	for (ll i = 1; i <= N; i++) {
		cin >> cows[i].x >> cows[i].y;
	}

	for (ll i = 0; i < M; i++) {
		ll a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	ll ans = 4.1 * pow(10, 8);

	for (ll i = 1; i <= N; i++) {
		if (!visited[i]) {
			minx = pow(10, 8);
			miny = pow(10, 8);
			maxx = 0;
			maxy = 0;
			floodfill(i);
			ll perim = 2 * (maxx - minx + maxy - miny);
			if (perim < ans) {
				ans = perim;
			}
		}
	}

	cout << ans << "\n";

	return 0;
}