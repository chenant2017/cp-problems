#include <bits/stdc++.h>
#include <cmath>

#define ll long long

using namespace std;

int solve(int* combo1, int* combo2, int N) {
	if (N < 5) {
		return pow(N, 3);
	}
	
	int abs_diff;
	int ans = 1;
	
	for (int i = 0; i < 3; i++) {
		abs_diff = abs(combo1[i] - combo2[i]);
		if (abs_diff > 5 && abs_diff < N - 5) {
			ans = 0;
			break;
		}
		if (abs_diff >= N - 5) {
			abs_diff = N - abs_diff;
		}
		ans *= (5 - abs_diff);
	}
	return 250 - ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s = "combo";
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
	
	int N;
	cin >> N;
	
	int combo[2][3];
	
	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < 3; i++) {
			cin >> combo[j][i];
		}
	}
	
	int ans = solve(combo[0], combo[1], N);
	
	cout << ans << "\n";
	
	return 0;
}