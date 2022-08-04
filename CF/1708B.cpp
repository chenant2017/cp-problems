#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N, L, R, T;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	//string fname = "1708B";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> T;

	for (ll t = 0; t < T; t++) {
		cin >> N >> L >> R;

		vector<ll> solution (N + 2);

		bool works = true;
		for (ll i = 1; i <= N; i++) {
			if (L % i == 0 || R % i - L % i < 0 || R - L + 1 >= i) {
				solution[i] = R - R % i;
			}
			else {
				works = false;
				break;
			}
		}

		if (works) {
			cout << "YES\n";
			for (ll i = 1; i <= N; i++) {
				cout << solution[i] << " ";
			}
			cout << "\n";
		}
		else {
			cout << "NO\n";
		}
	}
	
	return 0;
}