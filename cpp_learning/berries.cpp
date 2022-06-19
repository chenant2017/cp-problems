#include <bits/stdc++.h>
#include <cmath>

#define ll long long
#define MAX 1010

using namespace std;

ll N, K;
vector<ll> trees;

ll get_bmax(ll emin, const vector<ll>& trees) {

	vector<ll> t (trees.begin(), trees.end());

	if (emin == 0) {
		if (trees[K / 2 - 1] == 0) {
			return 0;
		}
		return -1;
	}

	ll at_emin = 0;
	ll stopped = N;

	for (ll i = 0; i < N; i++) {
		if (t[i] < emin) {
			stopped = i;
			break;
		}
		at_emin += t[i] / emin;
		t.push_back(t[i] % emin);
	}


	if (at_emin < K / 2) {
		return -1;
	}
	else if (at_emin >= K / 2 && at_emin <= K) {
		ll result = (at_emin - K / 2) * emin;
		sort(t.begin() + stopped, t.end(), greater<>());
		for (ll i = 0; i < K - at_emin; i++) {
			result += t[i + stopped];
		}
		return result;
	}
	else {
		return (K / 2) * emin;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "berries";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> K;

	for (ll i = 0; i < N; i++) {
		ll a;
		cin >> a;
		trees.push_back(a);
	}

	sort(trees.begin(), trees.end(), greater<>());

	ll ans = 0;

	for (ll emin = 0; emin <= 1000; emin++) {
		ll bmax = get_bmax(emin, trees);
		if (bmax > ans) {
			ans = bmax;
		}
	}

	cout << ans << "\n";

	return 0;
}