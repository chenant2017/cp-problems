#include <bits/stdc++.h>
#include <cmath>

#define ll long long
#define MAX_N 100010

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s = "clumsy";
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
	
	string pattern; 
	cin >> pattern;
	
	ll N = pattern.length();
	ll prefix[MAX_N] = {0};
	
	ll ans = 0;
	
	for (ll i = 1; i <= N; i++) {
		prefix[i] = prefix[i - 1];
		if (pattern[i - 1] == '(') {
			prefix[i]++;
		} 
		else {
			prefix[i]--;
		}
		if (prefix[i] == -1) {
			prefix[i] += 2;
			ans++;
		}
	}
	
	ans += prefix[N] / 2;
	
	cout << ans << "\n";
	
	return 0;
}