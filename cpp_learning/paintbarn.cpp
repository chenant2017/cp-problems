#include <bits/stdc++.h>

#define ll long long

ll barn[1005][1005] = {0};
ll N, K;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "paintbarn";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> K;

	for (ll i = 0; i < N; i++) {
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		barn[x1][y1]++;
		barn[x2+1][y2+1]++;
		barn[x2+1][y1]--;
		barn[x1][y2+1]--;
	}

	for (ll i = 0; i <= 1000; i++) {
		for (ll j = 1; j <= 1000; j++) {
			barn[i][j] += barn[i][j - 1];
		}
	}

	for (ll j = 0; j <= 1000; j++) {
		for (ll i = 1; i <= 1000; i++) {
			barn[i][j] += barn[i - 1][j];
		}
	}

	ll ans = 0;

	for (ll i = 0; i <= 1000; i++) {
		for (ll j = 0; j <= 1000; j++) {
			if (barn[i][j] == K) {
				ans++;
			}
		}
	}

	for (ll i = 0; i <= 10; i++) {
		for (ll j = 0; j <= 10; j++) {
			cout << barn[i][j] << " ";
		}
		cout << "\n";
	}

	cout << ans << "\n";

	return 0;
}