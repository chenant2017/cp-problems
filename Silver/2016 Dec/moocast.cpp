#include <bits/stdc++.h>
#include <cmath>

#define ll long long
#define MAXN 210

using namespace std;

struct Cow {
	ll x, y, p;
};

ll N;
Cow cows[MAXN];
vector<ll> adj[MAXN];

ll floodfill(ll start, bool visited[MAXN]) {
	ll ans = 0;
	if (visited[start]) {
		return ans;
	}

	visited[start] = true;
	ans++;

	for (auto i: adj[start]) {
		if (!visited[i]) {
			ans += floodfill(i, visited);
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "moocast";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

	for (ll i = 0; i < N; i++) {
		ll x, y, p;
		cin >> x >> y >> p;

		Cow cow; 
		cow.x = x;
		cow.y = y;
		cow.p = p;

		cows[i] = cow;
	}

	for (ll i = 0; i < N - 1; i++) {
		for (ll j = i + 1; j < N; j++) {
			double dist = sqrt(pow(cows[i].x - cows[j].x, 2) + 
							pow(cows[i].y - cows[j].y, 2));
			//cout << "dist between " << i << " " << j << " is " << dist << "\n";
			if (dist <= cows[i].p) {
				adj[i].push_back(j);
			}	
			if (dist <= cows[j].p) {
				adj[j].push_back(i);
			}
		}
	}

	/*for (ll i = 0; i < N; i++) {
		for (auto j: adj[i]) {
			cout << i << " can reach " << j << " ";
		}
		cout << "\n";
	}*/

	ll ans = 1;

	for (ll i = 0; i < N; i++) {
		bool visited[MAXN] = {false};
		ll ff = floodfill(i, visited);
		if (ff > ans) {
			ans = ff;
		}
	}

	cout << ans << "\n";

	return 0;
}