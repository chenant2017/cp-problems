#include <bits/stdc++.h>

#define ll long long
#define f first
#define s second

using namespace std;

ll N;

map<string, map<string, ll>> sc_counts;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "citystate";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

	for (ll i = 0; i < N; i++) {
		string city, state;
		cin >> city >> state;

		string city_pre = city.substr(0, 2);

		if (sc_counts[state].find(city_pre) == sc_counts[state].end()) {
			sc_counts[state][city_pre] = 1;
		} 
		else {
			sc_counts[state][city_pre]++;
		}
	}

	ll ans = 0;

	for (auto& i: sc_counts) {
		string state = i.f;
		map<string, ll> counts = i.s;

		for (auto &j: counts) {
			if (sc_counts.find(j.f) != sc_counts.end() &&
				sc_counts[j.f].find(state) != sc_counts[j.f].end() &&
				state != j.f) {
				ans += sc_counts[j.f][state] * j.s;
			}
		}
	}

	cout << ans / 2 << "\n";


	return 0;
}