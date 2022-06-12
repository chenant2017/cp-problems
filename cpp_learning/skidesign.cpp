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
	
	ll ans = 10000000;
	
	for (ll lower = heights[0]; lower <= heights[N - 1] - 17; lower++) {
		ll upper = lower + 17;
		
		ll cost = 0;
		for (ll i = 0; i < N; i++) {
			if (heights[i] < lower) {
				cost += pow(heights[i] - lower, 2);
			}
			else if (heights[i] > upper) {
				cost += pow(heights[i] - upper, 2);
			}			
		}
		
		if (cost < ans) {
			ans = cost;
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}