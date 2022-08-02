#include <bits/stdc++.h>

#define ll long long
#define MAXN 100010
#define f first
#define s second

using namespace std;

ll N;
map<ll, ll> dslope; 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "teleport";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

	ll value = 0;

	for (ll i = 0; i < N; i++) {
		ll a, b;
		cin >> a >> b;

		value += abs(b - a);
		if (abs(a) < abs(b - a)) {
			if ((a <= 0 && b >= 0) ||
				(a >= 0 && b <= 0)) {
				dslope[0]--;
				dslope[b] += 2;
				dslope[2*b]--;
			}
			else {
				dslope[2*a]--;
				dslope[b] += 2;
				dslope[2*b - 2*a]--;
			}
		}
	}

	ll ans = value;
	ll slope = 0;

	auto it = dslope.begin();
	slope += it->s;
	it++;

	for (; it != dslope.end(); it++) {
		auto prev = it;
		prev--;
		value += slope * (it->f - prev->f);
		slope += it->s;
		if (value < ans) {
			ans = value;
		}
	}

	cout << ans << "\n";

	return 0;
}