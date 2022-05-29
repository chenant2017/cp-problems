#include <bits/stdc++.h>

#define ll long long
#define MAX_N 100000

using namespace std;

struct Stop {
	ll x, c;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s = "reststops";
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
	
	ll L, N, rF, rB;
	
	cin >> L >> N >> rF >> rB;
	
	Stop stops[MAX_N];

	for (ll i = 0; i < N; i++) {
		cin >> stops[i].x >> stops[i].c;
	}
	
	sort(stops, stops + N, [](auto &a, auto&b) {
			return a.c > b.c;
		});
	
	ll tastiness = 0;
	ll pos = 0;
	ll time, dist;
	
	for (ll i = 0; i < N; i++) {
		dist = stops[i].x - pos;
		if (dist > 0) {
			pos += dist;
			tastiness += (rF - rB) * dist * stops[i].c;
		} 
	}
	
	cout << tastiness << "\n";
	
	return 0;
}