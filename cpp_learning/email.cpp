//Silver 2022 Feb #3

#include <bits/stdc++.h>

#define ll long long
#define MAXN 100010
#define MAXM 10010

using namespace std;

ll T;
ll M, N, K;
ll emails[MAXN];
ll last[MAXM];
ll e1, e2, f1, f2;
bool rv; 
ll size_;


void fill(bool filed[MAXN]) {
	while (e1 < N - 1) {
		if (filed[e1] || f1 <= emails[e1] && emails[e1] <= f2) {
			filed[e1] = true;
			e1++;
		}
		else {
			break;
		}
	}

	e2 = e1;
	size_ = 1;

	while (e2 < N - 1 && size_ < K) {
		e2++;
		if (filed[e2] || (f1 <= emails[e2] && emails[e2] <= f2)) {
			filed[e2] = true;
		}
		else {
			size_++;
		}
	}
}

void rfill(bool filed[MAXN]) {
	while (e2 > 0) {
		if (filed[e2] || (f1 <= emails[e2] && emails[e2] <= f2)) {
			filed[e2] = true;
			e2--;
		}
		else {
			break;
		}
	}

	e1 = e2;
	size_ = 1;

	while (e1 > 0 && size_ < K) {
		e1--;
		if (filed[e1] || (f1 <= emails[e1] && emails[e1] <= f2)) {
			filed[e1] = true;
		}
		else {
			size_++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> T;

	for (ll t = 0; t < T; t++) {
		bool filed[MAXN] = {false};

		cin >> M >> N >> K;

		for (ll i = 1; i <= M; i++) {
			last[i] = -1;
		}

		rv = false;

		for (ll i = 0; i < N; i++) {
			cin >> emails[i];
			last[emails[i]] = i;
		}

		e1 = 0;
		f1 = 1;
		f2 = K;

		for (ll i = 1; i <= N - K + 2; i++) {
			for (ll e = e1; e <= e2; e++) {
				if (emails[e] == f2) {
					filed[e] = true;
				}
			}
			
			if (rv) {
				rfill(filed);
				
			}
			else {
				fill(filed);
				
				while (last[f1] > e2) {
					e1++;
					fill(filed);
					
					if (e2 == N - 1) {
						break;
					}
				}
				if (e2 == N - 1) {
					rv = true;
					rfill(filed);
					
				}
				
			}
			if (f1 < N - K + 1) {
				f1++;
				f2++;
			}
		}

		bool ans = true;
		for (ll i = 0; i < N; i++) {
			if (!filed[i]) {
				ans = false;
			}
		}

		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}