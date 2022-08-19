#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll T, N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "1714B";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);

	cin >> T;
	
	for (ll t = 0; t < T; t++) {
		cin >> N;
		vector<bool> seen (N + 1, false);
		vector<ll> a (N + 1);
		for (ll i = 1; i <= N; i++) {
			cin >> a[i];
		}

		ll ans = 0;

		for (ll i = N; i > 0; i--) {
			if (seen[a[i]]) {
				ans = i;
				break;
			}
			else {
				seen[a[i]] = true;
			}
		}

		cout << ans << "\n";
	}
	
	return 0;
}