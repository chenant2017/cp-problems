#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll T, S;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "1714C";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> T;

	for (ll t = 0; t < T; t++) {
		cin >> S;
		vector<ll> ans;

		ll rem = S;

		for (ll i = 9; i > 0; i--) {
			if (i > rem) {
				ans.push_back(rem);
				rem = 0;
			}
			else {
				ans.push_back(i);
				rem -= i;
			}
			if (rem == 0) break;
		}

		for (auto it = ans.rbegin(); it != ans.rend(); it++) {
			cout << *it;
		}
		cout << "\n";
	}
	
	return 0;
}