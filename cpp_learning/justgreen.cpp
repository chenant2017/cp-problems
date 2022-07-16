//Silver 2021 Feb #3

#include <bits/stdc++.h>

#define ll long long
#define MAXN 510

using namespace std;

ll N;
int ge100[MAXN][MAXN] = {0};
int ge101[MAXN][MAXN] = {0};

ll get_rects(int ge[MAXN][MAXN]) {
	ll rects = 0;

	for (ll i = 0; i < N; i++) {

		int all_ones[MAXN] = {0}; // all_ones in column, starting from row i
		for (ll j = 0; j < N; j++) {
			all_ones[j] = 1;
		}

		for (ll j = i; j < N; j++) {
			for (ll k = 0; k < N; k++) {
				if (ge[j][k] == 0) {
					all_ones[k] = 0;
				}
			}

			ll consec = 0;
			for (ll k = 0; k <= N; k++) {
				if (all_ones[k] == 1) {
					consec++;
				}
				else {
					rects += (consec) * (consec + 1) / 2;
					consec = 0;
				}
			}
		}
	}
	return rects;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	//string fname = "justgreen";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < N; j++) {
			ll g;
			cin >> g;
			if (g >= 100) {
				ge100[i][j] = 1;
			}
			if (g >= 101) {
				ge101[i][j] = 1;
			}
		}
	}

	cout << get_rects(ge100) - get_rects(ge101) << "\n";

	return 0;
}