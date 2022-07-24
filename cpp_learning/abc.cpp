#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll T;
	ll N;
	
	cin >> T;

	for (ll i = 0; i < T; i++) {
		ll numbers[10];
		cin >> N;
		set<ll> diffs;

		for (ll j = 0; j < N; j++) {
			cin >> numbers[j];
		}
		numbers[N] = 0;
	
		for (ll j = 0; j < N; j++) {
			for (ll k = j + 1; k < N + 1; k++) {
				if (numbers[j] != numbers[k]) {
					diffs.insert(abs(numbers[j] - numbers[k]));
				}
			}
		}

		ll ans = 0;

		for (auto a: diffs) {
			for (auto b: diffs) {
				for (auto c: diffs) {
					if (a <= b && b <= c) {
						set<ll> all_numbers({a, b, c, a + b, b + c, a + c, a + b + c});
						bool works = true;
						
						for (ll k = 0; k < N; k++) {
							if (all_numbers.find(numbers[k]) == all_numbers.end()) {
								works = false;
							}
						}


						if (works)  {
							ans++;
						}
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}