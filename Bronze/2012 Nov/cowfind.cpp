#include <bits/stdc++.h>

#define ll long long
#define MAXN 50010

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "cowfind";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	string input;
	cin >> input;

	ll fronts[MAXN] = {0};
	vector<ll> backs;

	for (ll i = 0; i < input.size() - 1; i++) {
		string j = input.substr(i, 2);
		if (j == "))") {
			fronts[i]++;
		}
		else if (j == "((") {
			backs.push_back(i);
		}
	}

	for (ll i = input.size() - 2; i >= 0; i--) {
		fronts[i] += fronts[i + 1];
	}

	ll ans = 0;

	for (ll i = 0; i < backs.size(); i++) {
		ans += fronts[backs[i]];
	}

	cout << ans << "\n";

	return 0;
}