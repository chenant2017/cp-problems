#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll T, N, H, M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "1714A";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);

	cin >> T;
	
	for (ll t = 0; t < T; t++) {
		cin >> N >> H >> M;
		ll time = H * 60 + M;
		ll ans = 24 * 60;
		for (ll i = 0; i < N; i++) {
			ll h, m;
			cin >> h >> m;
			ll alarm = h * 60 + m;
			ll result;
			if (alarm < time) {
				result = 24 * 60 - (time - alarm);
			}
			else {
				result = alarm - time;
			}

			if (result < ans) {
				ans = result;
			}
		}

		ll ansh = ans / 60;
		ll ansm = ans % 60;

		cout << ansh << " " << ansm << "\n";
	}
	
	return 0;
}