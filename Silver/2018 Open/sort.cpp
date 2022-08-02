#include <bits/stdc++.h>

#define ll long long
#define MAXN 100010

using namespace std;

ll N;
pair<ll, ll> values[MAXN];

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
		values[i] = pair<ll, ll>({a, i});
	}

	sort(values, values + N);

	ll ans = 0;

	for (ll i = 0; i < N; i++) {
		ll d = values[i].second - i;
		if (d > 0 && d > ans) {
			ans = d;
		}
	}

	cout << ans + 1 << "\n";


	return 0;
}