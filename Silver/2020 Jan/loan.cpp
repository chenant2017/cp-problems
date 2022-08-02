#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll N, K, M;

bool works(ll x) {
	ll days = 0;
	ll G = 0;
	ll y = N / x;

	while (y >= M) {
		ll add_days = (N - G - y * x) / y + 1;
		if (days + add_days > K) {
			add_days = K - days;
		}
		days += add_days;
		G += add_days * y;

		if (days == K) {
			return G >= N;
		}
		if (G >= N) {
			return true;
		}

		y = (N - G) / x;
	}
	G += (K - days) * M;
	return G >= N;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "loan";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> K >> M;

	ll minx = 1;
	ll maxx = N + 1;

	while (maxx - minx > 1) {
		ll mid = (minx + maxx) / 2;
		if (works(mid)) {
			minx = mid;
		}
		else {
			maxx = mid;
		}
	}

	cout << minx << "\n";

	return 0;
}