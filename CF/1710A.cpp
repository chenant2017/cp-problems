#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll T, N, M, K;
vector<ll> pigments;

bool solve() {
	bool gt3_1 = false;
	bool gt3_2 = false;
	ll total1 = 0;
	ll total2 = 0;

	for (auto i: pigments) {
		if (i >= 2 * M) {
			total1 += i / M;
			if (i / M >= 3) {
				gt3_1 = true;
			}
		}

		if (i >= 2 * N) {
			total2 += i / N;
			if (i / N >= 3) {
				gt3_2 = true;
			}
		}
	}

	if (N % 2 == 1) {
		if (gt3_1 && total1 >= N) return true;
	}
	else {
		if (total1 >= N) return true;
	}

	if (M % 2 == 1) {
		if (gt3_2 && total2 >= M) return true;
	}
	else {
		if (total2 >= M) return true;
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> T;

	for (ll t = 0; t < T; t++) {
		cin >> N >> M >> K;
		pigments.resize(K);
		for (ll i = 0; i < K; i++) {
			cin >> pigments[i];
		}
		bool ans = solve();
		if (ans) cout << "Yes\n";
		else cout << "No\n";
	}

	return 0;
}