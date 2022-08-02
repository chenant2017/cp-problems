#include <bits/stdc++.h>
#include <cmath>

#define ll long long
#define MAX_B 100000

using namespace std;

ll N, K, B;
ll broken[MAX_B + 5] = {-1};

bool works(ll fix) {
	if (fix < 0) {
		return false;
	}
	ll max_cont = 0;
	for (ll i = 0; i <= B - fix; i++) {
		ll cont = broken[i + fix + 1] - broken[i] - 1;
		if (cont > max_cont) {
			max_cont = cont;
		}
	}
	return (max_cont >= K);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s = "maxcross";
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
	
	
	cin >> N >> K >> B;
	
	broken[0] = 0;
	
	for (ll i = 1; i <= B; i++) {
		cin >> broken[i];
	}
	
	broken[B + 1] = N + 1;
	sort(broken, broken + B + 1);

	ll jump = B / 2 + 1;
	ll fix = B;
	
	while (jump > 0) {
		if (works(fix - jump)) {
			fix -= jump;
		}
		else {
			jump /= 2;
		}
	}
	
	cout << fix << "\n";
	
	return 0;
}

