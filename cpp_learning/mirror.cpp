#include <bits/stdc++.h>
#include <cmath>

#define ll long long
#define MAXN 1000
#define f first
#define s second

using namespace std;

ll N, M;
string mirrors[MAXN];

ll count(ll i, ll j, pair<ll, ll> dir) {
	ll result = 0;

	while (0 <= i && i < N &&
		   0 <= j && j < M) {
		//cout << i << " " << j << " " << dir.f << " " << dir.s << "\n";
		result += 1;
		if (mirrors[i][j] == '\\') {
			if (dir.f == 0) {
				dir.f = dir.s;
				dir.s = 0;
			}
			else {
				dir.s = dir.f;
				dir.f = 0;
			}
		} 
		else {
			if (dir.f == 0) {
				dir.f = -1 * dir.s;
				dir.s = 0;
			}	
			else {
				dir.s = -1 * dir.f;
				dir.f = 0;
			}
		}
		//cout << i << " " << j << " " << dir.f << " " << dir.s << "\n";
		i += dir.f;
		j += dir.s;
	}

	//cout << result << "\n";

	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "mirror";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;

	for (ll i = 0; i < N; i++) {
		cin >> mirrors[i];
	}

	ll ans = 1;

	for (ll i = 0; i < N; i++) {
		ll a = count(i, 0, {0, 1});
		ll b = count(i, M - 1, {0, -1});

		if (a > ans) {
			ans = a;
			//cout << i << " " << 0 << " " << a << "\n";
		}

		if (b > ans) {
			ans = b;
			//cout << i << " " << M - 1 << " " << b << "\n";
		}
	}

	for (ll j = 0; j < M; j++) {
		ll a = count(0, j, {1, 0});
		ll b = count(N - 1, j, {-1, 0});

		if (a > ans) {
			ans = a;
			//cout << i << " " << 0 << " " << a << "\n";
		}

		if (b > ans) {
			ans = b;
			//cout << i << " " << M - 1 << " " << b << "\n";
		}
	}

	cout << ans << "\n";

	return 0;
}