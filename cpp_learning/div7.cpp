#include <bits/stdc++.h>
#include <cmath>

#define ll long long
#define MAX_N 50050

using namespace std;

struct Occur {
	ll first = -1;
	ll last = -1;
	ll len() {
		return last - first;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s = "div7";
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
	
	ll N;
	cin >> N;
	
	ll prefix_mod[MAX_N] = {0};
	
	for (ll i = 1; i <= N; i++) {
		prefix_mod[i] = prefix_mod[i - 1];
		ll value;
		cin >> value;
		prefix_mod[i] = (prefix_mod[i] + value) % 7;
	}
	
	Occur occurs[7];
	
	for (ll i = 1; i <= N; i++) {
		if (occurs[prefix_mod[i]].first == -1) {
			occurs[prefix_mod[i]].first = i;
		}
		else {
			occurs[prefix_mod[i]].last = i; 
		}
	}
	
	ll ans = 0;
	for (ll i = 0; i < 7; i++) {
		if (occurs[i].len() > ans) {
			ans = occurs[i].len();
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}