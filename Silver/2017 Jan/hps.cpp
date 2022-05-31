#include <bits/stdc++.h>
#include <cmath>

#define ll long long
#define MAX_N 100100

using namespace std;

struct Count {
	ll h = 0, p = 0, s = 0;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s = "hps";
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
	
	ll N;
	cin >> N;
	
	Count counts[MAX_N];
	
	for (ll i = 1; i <= N; i++) {
		counts[i] = counts[i - 1];
		string gest;
		cin >> gest;
		switch (gest[0]) {
			case 'H': 
				counts[i].h++;
				break;
			case 'P': 
				counts[i].p++;
				break;
			case 'S': 
				counts[i].s++;
				break;
		}
	}
	
	ll ans = 0;
	
	for (ll split = 2; split <= N; split++) {
		ll max1 = max({counts[split - 1].h, counts[split - 1].p, counts[split - 1].s});
		ll max2 = max({counts[N].h - counts[split - 1].h, 
				   counts[N].p - counts[split - 1].p,
	counts[N].s - counts[split - 1].s});
		ll total = max1 + max2;
		if (total > ans) {
			ans = total;
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}