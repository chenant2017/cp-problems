#include <bits/stdc++.h>
#include <cmath>

#define ll long long
#define MAX_N 100010

using namespace std;

ll N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "herding";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;
	
	ll locs[MAX_N];
	
	for (ll i = 0; i < N; i++) {
		cin >> locs[i];
	}
	
	locs[N] = 10000000000;
	
	sort(locs, locs + N);
	
	ll ptr2 = 1;
	
	ll min_ans = N;
	
	for (ll ptr1 = 0; ptr1 < N; ptr1++) {
		while (locs[ptr2] - locs[ptr1] <= N - 1 && ptr2 < N) {
			ptr2++;
		}
		
		ll min_moves = N - (ptr2 - ptr1);
		
		if (min_moves == 1 && locs[ptr2 - 1] == locs[ptr1] + N - 2) {
			min_moves++;
		}
		
		if (min_moves < min_ans) {
			min_ans = min_moves;
		}
	}
	
	ll diff1 = locs[N - 1] - locs[1];
	ll diff2 = locs[N - 2] - locs[0];
	
	ll max_ans = max(diff1, diff2) - N + 2;
	
	cout << min_ans << "\n" << max_ans << "\n";
	
	return 0;
}