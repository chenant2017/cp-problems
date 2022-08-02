#include <bits/stdc++.h>

#define ll long long
#define MAXN 1010
#define f first
#define s second

using namespace std;

ll N;
pair<ll, ll> cows[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "balancing";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

	for (ll i = 0; i < N; i++) {
		cin >> cows[i].f >> cows[i].s;
	}

	sort(cows, cows + N);

	vector<ll> possa;
	if (N % 2 == 0) {
		possa.insert(possa.end(), {cows[N/2 - 1].f + 1, cows[N/2 - 1].f + 3,
							       cows[N/2].f - 1, cows[N/2].f - 3}); 
	}
	else {
		possa.insert(possa.end(), {cows[N/2].f + 1, cows[N/2].f + 3, 
							       cows[N/2].f - 1, cows[N/2].f - 3}); 
	}

	/*for (ll i: possa) {
		cout << i << "\n";
	}
	cout << "\n";*/

	sort(cows, cows + N, [](auto& a, auto& b) {
		return a.s < b.s || (a.s == b.s && a.f < b.f);
	});
	
	vector<ll> possb;
	if (N % 2 == 0) {
		possb.insert(possb.end(), {cows[N/2 - 1].s + 1, cows[N/2 - 1].s + 3, 
								   cows[N/2].s - 1, cows[N/2].s - 3}); 
	}
	else {
		possb.insert(possb.end(), {cows[N/2].s + 1, cows[N/2].s + 3,
								   cows[N/2].s - 1, cows[N/2].s - 3});
	}
	/*for (ll i: possb) {
		cout << i << "\n";
	}
	cout << "\n";*/

	ll ans = 1010;

	for (auto aa: possa) {
		for (auto bb: possb) {

			//cout << aa << " " << bb << " aa bb\n";
			ll quads[4] = {0};

			for (ll i = 0; i < N; i++) {
				ll x = cows[i].f;
				ll y = cows[i].s;

				if (x > aa && y > bb) {
					quads[0]++;
				}
				else if (x < aa && y > bb) {
					quads[1]++;
				}
				else if (x < aa && y < bb) {
					quads[2]++;
				}
				else if (x > aa && y < bb) {
					quads[3]++;
				}
			}

			ll M = 0;
			for (ll i = 0; i < 4; i++) {
				cout << quads[i] << " ";
				if (quads[i] > M) {
					M = quads[i];
				}
			}
			cout << "\n";
			if (M < ans) {
				ans = M;
			}
		}
	}

	cout << ans << "\n";

	return 0;
}