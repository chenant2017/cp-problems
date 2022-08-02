#include <bits/stdc++.h>

#define ll long long
#define MAXN 100010

using namespace std;

ll N;
ll shuffle1[MAXN];
bool visited[MAXN] = {false};

ll find_good(ll start) {
	ll curr = start;

	if (visited[curr]) {
		return 0;
	}

	vector<ll> path;

	while (!visited[curr]) {
		visited[curr] = true;
		path.push_back(curr);
		curr = shuffle1[curr];
	}

	path.push_back(curr);

	for (ll i = 0; i < path.size(); i++) {
		if (path[i] == curr) {
			//cout << path.size() - 1 - i << "\n";
			return path.size() - 1 - i;
		}
	}
	return 0;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "shuffle";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

	for (ll i = 1; i <= N; i++) {
		cin >> shuffle1[i];
	}

	ll ans = 0;

	for (ll i = 1; i <= N; i++) {
		ans += find_good(i);
	}

	cout << ans << "\n";

	return 0;
}