#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N, C;
vector<ll> carrots;

ll solve(ll i, ll max_sum) {
	if (i == N - 1) {
		if (carrots[i] <= max_sum) return carrots[i];
		else return 0;
	}
	ll total = 0;
	if (carrots[i] > max_sum) {
		total = solve(i + 1, max_sum);
	}
	else if (carrots[i] + carrots[i + 1] <= max_sum) {
		total = max(carrots[i] + solve(i + 1, max_sum - carrots[i]),
					solve(i + 1, max_sum));
	}
	else {
		total += carrots[i];
		total += solve(i + 1, max_sum - carrots[i]);
	}
    //cout << i << " " << max_sum << " " << total << "\n";
	return total;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "bountiful";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> C;

	for (ll i = 0; i < N; i++) {
		ll c;
		cin >> c;
		carrots.push_back(c);
	}
	
	sort(carrots.begin(), carrots.end(), greater<ll>());

	cout << solve(0, C) << "\n";

	return 0;
}