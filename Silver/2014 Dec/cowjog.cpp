#include <bits/stdc++.h>
#include <cmath>

using namespace std;

#define MAX_N 100000
#define MAX_T 1000000000
#define ll long long

struct cow {
	ll pos;
	ll speed;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s = "cowjog";
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
	
	ll n, t;
	cin >> n >> t;
	
	cow cows[MAX_N];
	
	for (ll i = 0; i < n; i++) {
		cin >> cows[i].pos >> cows[i].speed; 
	}
	
	sort(cows, cows + n, [](auto& a, auto& b) {return a.pos > b.pos;});
	
	ll groups = 0;
	ll min = LONG_LONG_MAX; 
	
	for (ll i = 0; i < n; i++) {
		ll final_pos = cows[i].pos + cows[i].speed * t;
		if (final_pos < min) {
			groups++;
			min = final_pos;
		}
	}
	
	cout << groups << "\n";
	
	return 0;
}
