#include <bits/stdc++.h>
#include <cmath>

#define ll long long

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "bgm";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	ll N;
	cin >> N;

	map<char, vector<ll>> freq;

	freq['B'] = {0, 0, 0, 0, 0, 0, 0};
	freq['E'] = {0, 0, 0, 0, 0, 0, 0};
	freq['S'] = {0, 0, 0, 0, 0, 0, 0};
	freq['I'] = {0, 0, 0, 0, 0, 0, 0};
	freq['G'] = {0, 0, 0, 0, 0, 0, 0};
	freq['O'] = {0, 0, 0, 0, 0, 0, 0};
	freq['M'] = {0, 0, 0, 0, 0, 0, 0};

	for (ll i = 0; i < N; i++) {
		string var;
		ll a;
		cin >> var >> a;
		freq[var[0]][a % 7]++;
	}

	/*for (auto i: freq) {
		cout << i.first << " ";
		for (auto j: i.second) {
			cout << j << " ";
		}
		cout << "\n";
	}*/

	ll ans = 0;

	for (ll b = 0; b < 7; b++) {
		for (ll e = 0; e < 7; e++) {
			for (ll s = 0; s < 7; s++) {
				for (ll i = 0; i < 7; i++) {
					for (ll g = 0; g < 7; g++) {
						for (ll o = 0; o < 7; o++) {
							for (ll m = 0; m < 7; m++) {

								ll result = (b % 7 + (2*e) % 7 + (2*s) % 7 + i % 7) *
											(g % 7 + o % 7 + e % 7 + s % 7) * (m % 7 + (2*o) % 7);

								if (result % 7 == 0) {
									ans += freq['B'][b] * freq['E'][e] * freq['S'][s] *
										   freq['I'][i] * freq['G'][g] * freq['O'][o] *
										   freq['M'][m];
								}
							}
						}
					}
				}
			}
		}
	}

	cout << ans << "\n";

	return 0;
}