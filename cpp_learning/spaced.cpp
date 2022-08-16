#include <bits/stdc++.h>
#define MAX 1010
using namespace std;

typedef long long ll;
ll N;

ll beauty[MAX][MAX];

ll max_sum_row(ll r) {
	ll sum1 = 0;
	for (ll i = 0; i < N; i += 2) {
		sum1 += beauty[r][i];
	}

	ll sum2 = 0;
	for (ll i = 1; i < N; i += 2) {
		sum2 += beauty[r][i];
	}

	return max(sum1, sum2);
}

ll max_sum_col(ll c) {
	ll sum1 = 0;
	for (ll i = 0; i < N; i += 2) {
		sum1 += beauty[i][c];
	}

	ll sum2 = 0;
	for (ll i = 1; i < N; i += 2) {
		sum2 += beauty[i][c];
	}

	return max(sum1, sum2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "spaced";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < N; j++) {
			cin >> beauty[i][j];
		}
	}

	ll totalr = 0;
	for (ll r = 0; r < N; r++) {
		totalr += max_sum_row(r);
	}

	ll totalc = 0;
	for (ll c = 0; c < N; c++) {
		totalc += max_sum_col(c);
	}

	cout << max(totalr, totalc) << "\n";

	return 0;
}