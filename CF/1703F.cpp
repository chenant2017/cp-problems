#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll T, N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	//string fname = "1703F";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> T;

	for (ll t = 0; t < T; t++) {
		cin >> N;
		vector<ll> prefix (N + 1, 0);
		vector<ll> a (N + 1, 0);

		for (ll i = 1; i <= N; i++) {
			cin >> a[i];
			prefix[i] = prefix[i - 1];
			if (a[i] < i) {
				prefix[i]++;
			}
		}


		ll ans = 0;
		for (ll i = 1; i <= N; i++) {
			if (a[i] < i) {
				if (1 <= a[i] - 1 && a[i] - 1 <= N) {
					ans += prefix[a[i] - 1];
				}
			}
		}
		cout << ans << "\n";
	}
	
	
	return 0;
}