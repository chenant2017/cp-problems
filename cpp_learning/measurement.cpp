#include <bits/stdc++.h>
#include <cmath>

#define ll long long
#define MAXN 100010

using namespace std;

ll N, G;
map<ll, ll> cow_out;
map<ll, unordered_set<ll>> out_cows;
vector<ll> measures[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "measurement";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> G;

	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < 3; j++) {
			ll a;
			cin >> a;
			measures[i].push_back(a);
		}
	}

	/*for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < 3; j++) {
			cout << measures[i][j] << " ";
		}
		cout << "\n";
	}*/

	sort(measures, measures + N, [](auto& a, auto& b){return a[0] < b[0];});

	ll max_out = G;
	ll ans = 0;

	for (ll i = 0; i < N; i++) {
		auto m = measures[i];
		ll cow = m[1];
		ll change = m[2];

		if (cow_out.find(cow) == cow_out.end()) {
			cow_out[cow] = G;
			out_cows[G].insert(cow);
		}

		out_cows[cow_out[cow]].erase(cow);
		if (out_cows[cow_out[cow]].empty()) {
			out_cows.erase(cow_out[cow]);
		}
		cow_out[cow] += change;
		out_cows[cow_out[cow]].insert(cow);

		if (cow_out[cow] > max_out) {
			max_out = cow_out[cow];
			ans++;
		}
		else if (cow_out[cow] == max_out) {
			ans++;
		}
		else if (out_cows.find(max_out) == out_cows.end()) {
			max_out = out_cows.rbegin()->first;
			ans++;
		}
	}

	cout << ans << "\n";

	return 0;
}