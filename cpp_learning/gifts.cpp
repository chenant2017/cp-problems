#include <bits/stdc++.h>

#define ll long long
#define MAXN 510

using namespace std;

ll N;
ll prefs[MAXN][MAXN];
ll ans[MAXN];


bool works(ll start, ll taking, bool visited[MAXN]) {
	//cout << start << " " << taking << "\n";

	ll i;
	if (taking % N == start - 1) {
		i = 0;
		while (i < N && prefs[taking][i - 1] != taking) {
			if (!visited[prefs[taking][i]]) return true;
			i++;
		}
		return false;
	}

	i = 0;
	while (i < N && prefs[taking][i - 1] != taking) {

		if (visited[prefs[taking][i]]) {
			i++;
			continue;
		}

		visited[prefs[taking][i]] = true;

		if (works(start, taking % N + 1, visited)) {
			return true;
		}

		visited[prefs[taking][i]] = false;
		i++;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	//string fname = "gifts";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

	for (ll i = 1; i <= N; i++) {
		for (ll j = 0; j < N; j++) {
			cin >> prefs[i][j];
		}
	}

	for (ll i = 1; i <= N; i++) {
		ll j = 0;
		while (j < N && prefs[i][j - 1] != i) {
			bool visited[MAXN] = {false};
			visited[prefs[i][j]] = true;

			if (works(i, i % N + 1, visited)) {
				ans[i] = prefs[i][j];
				break;
			}
			j++;
		}
	}

	for (ll i = 1; i <= N; i++) {
		cout << ans[i] << "\n";
	}

	return 0;
}