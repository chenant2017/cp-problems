#include <bits/stdc++.h>
#include <cmath>

#define ll long long
#define N_MAX 1100

using namespace std;

ll N;
ll cows[N_MAX] = {0};

ll get_ystart(ll i, ll j) {
	ll yptr = i;
	ll jump = (j - i) / 2;
	
	while (jump > 0) {
		ll a = cows[yptr + jump] - cows[i];
		ll b = cows[j] - cows[yptr + jump];
		if (b > 2 * a && yptr + jump < j) {
			yptr += jump;
		}
		else {
			jump /= 2;
		}
	}
	return yptr;
}

ll get_yend(ll i, ll j) {
	ll yptr = i;
	ll jump = (j - i) / 2;
	
	while (jump > 0) {
		ll a = cows[yptr + jump] - cows[i];
		ll b = cows[j] - cows[yptr + jump];
		if (b >= a && yptr + jump < j) {
			yptr += jump;
		}
		else {
			jump /= 2;
		}
	}
	return yptr;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s = "baseball";
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
	 
	cin >> N;
	
	for (ll i = 0; i < N; i++) {
		cin >> cows[i]; 
	}
	
	sort(cows, cows + N);
	
	ll ans = 0;
	
	for (ll i = 0; i <= N - 3; i++) {
		for (ll j = i + 2; j < N; j++) {
			ll ystart = get_ystart(i, j);
			ll yend = get_yend(i, j);
			ans += yend - ystart;
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}