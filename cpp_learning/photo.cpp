#include <bits/stdc++.h>
#include <cmath>

#define ll long long
#define MAXK 1010
#define f first
#define s second

using namespace std;

pair<ll, ll> unfriendly[MAXK];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "photo";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	ll N, K;
	cin >> N >> K;

	for (ll i = 0; i < K; i++) {
		ll a, b;
		cin >> a >> b;
		if (a < b) {
			unfriendly[i] = {a, b};
		}
		else {
			unfriendly[i] = {b, a};
		}
	}

	sort(unfriendly, unfriendly + K, [](auto& a, auto& b) {
		return a.s < b.s || (a.s == b.s && a.f < b.f); 
	});

	ll start = 1;
	ll end = 1;
	ll ans = 1;

	for (auto& u: unfriendly) {
		if (u.f < start) {
			continue;
		}
		start = u.s;
		ans++;
	}

	cout << ans << "\n";

	return 0;
}