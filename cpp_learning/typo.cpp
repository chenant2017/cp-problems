#include <bits/stdc++.h>
#include <cmath>

#define ll long long
#define MAX_N 100010

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s = "typo";
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
	
	string pattern;
	cin >> pattern;
	
	int prefix[MAX_N] = {0};
	ll N = pattern.length();
	
	ll first_neg = -1;
	
	for (ll i = 1; i <= N; i++) {
		prefix[i] = prefix[i - 1];
		if (pattern[i - 1] == '(') {
			prefix[i]++;
		}
		else {
			prefix[i]--;
		}
		if (prefix[i] < 0 && first_neg == -1) {
			first_neg = i;
		}
	}
	
	if (prefix[N] != 2 && prefix[N] != -2) {
		cout << "0\n";
		return 0;
	}
	
	if (prefix[N] == -2) {
		cout << (first_neg + 1) / 2 << "\n";
		return 0;
	}
		
	if (first_neg != -1) {
		cout << "0\n";
		return 0;
	}

	ll last_lt_2; //last less than 2
	
	for (ll i = N; i >= 1; i--) {
		if (prefix[i] < 2) {
			last_lt_2 = i;
			break;
		}
	}
	
	cout << (N + 1 - last_lt_2) / 2 << "\n";
	
	return 0;
}