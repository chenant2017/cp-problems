#include <bits/stdc++.h>
#include <cmath>

#define ll long long
#define MAX_N 1100

using namespace std;

ll N;
ll heights[MAX_N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "skidesign";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;
	
	if (N == 1) {
		cout << "0\n";
		return 0;
	}
	
	for (ll i = 0; i < N; i++) {
		cin >> heights[i];
	}
	
	sort(heights, heights + N);
	
	heights[N] = 200;
	
	ll ptr1 = 0;
	ll ptr2 = 1;
	
	ll ans = 10000000;
	
	while (ptr1 < N - 1) {
		while (heights[ptr2] <= heights[ptr1] + 17 && ptr2 <= N) {
			ptr2++;
		}
		
		ll cost = 0;
		
		for (ll i = 0; i < ptr1; i++) {
			cost += pow(heights[ptr1] - heights[i], 2);
		}
		
		for (ll i = ptr2; i < N; i++) {
			cost += pow(heights[i] - (heights[ptr1] + 17), 2); // heights[ptr1] + 17, not heights[ptr2]
		}	
		
		if (cost < ans) {
			ans = cost;
		}
		while (heights[ptr1 + 1] == heights[ptr1]) {
			ptr1++;
		}
		ptr1++;
	}
	
	cout << ans << "\n";
	
	return 0;
}