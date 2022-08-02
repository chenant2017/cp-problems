#include <bits/stdc++.h>

#define ll long long
#define MAXN 110

using namespace std;

ll N;
ll values[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	//string fname = "OJ108";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

	for (ll i = 1; i <= N; i++) {
		for (ll j = 1; j <= N; j++) {
			cin >> values[i][j];
		}
	}

	for (ll i = 1; i <= N; i++) {
		for (ll j = 1; j <= N; j++) {
			values[i][j] += values[i][j - 1];
		}
	}

	for (ll j = 1; j <= N; j++) {
		for (ll i = 1; i <= N; i++) {
			values[i][j] += values[i - 1][j];
		}
	}


	ll ans = -127 * 10000;
	for (ll i1 = 1; i1 <= N; i1++) {
		for (ll j1 = 1; j1 <= N; j1++) {

			for (ll i2 = i1; i2 <= N; i2++) {
				for (ll j2 = j1; j2 <= N; j2++) {
					ll sum = values[i2][j2] + values[i1 - 1][j1 - 1] 
					         - values[i2][j1 - 1] - values[i1 - 1][j2];
					if (sum > ans) {
						ans = sum;
					}
				}
			}
		}
	}

	cout << ans << "\n";


	return 0;
}