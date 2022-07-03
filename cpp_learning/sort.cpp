#include <bits/stdc++.h>

#define ll long long
#define MAXN 100010

using namespace std;

ll N;
unordered_map<ll, ll> orig;
ll sorted[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "sort";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);

	cin >> N;

	for (ll i = 0; i < N; i++) {
		ll a;
		cin >> a;
		orig[a] = i;
		sorted[i] = a;
	}

	sort(sorted, sorted + N);

	ll ans = 0;

	for (ll i = 0; i < N; i++) {
		ll d = i - orig[sorted[i]];
		if (d < 0 && -1*d > ans) {
			ans = -1*d;
		}
	}

	cout << ans + 1 << "\n";


	return 0;
}