#include <bits/stdc++.h>
#include <cmath>

#define ll long long

using namespace std;


ll poss_starts(string s) {
	ll ans = 0;
	
	ll longer = s.size() / 2 + 1;
	
	string s1l = s.substr(0, longer);
	string s1t1 = s1l.substr(1);
	string s1t2 = s1l.substr(0, s1l.size() - 1);
	string s1s = s.substr(longer);
	
	string s2l = s.substr(longer - 1);
	string s2t1 = s2l.substr(1);
	string s2t2 = s2l.substr(0, s2l.size() - 1);
	string s2s = s.substr(0, longer - 1);
	
	if (longer % 2 == 0) {
		if (s1t1 == s1s) {
			ans++;
		}
		if (s1t2 == s1s) {
			ans++;
		}
		
		if (s2t1 == s2s) {
			ans++;
		}
		if (s2t2 == s2s) {
			ans++;
		}
	}
	
	else {
		if (s1t1 == s1s) {
			ans += poss_starts(s1l);
		} 
		if (s1t2 == s1s) {
			ans += poss_starts(s1l);
		}
		if (s2t1 == s2s) {
			ans += poss_starts(s2l);
		}
		if (s2t2 == s2s) {
			ans += poss_starts(s2l);
		}
	}
	return ans + 1;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string name = "scode";
	freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
	
	string message;
	cin >> message;
	
	cout << poss_starts(message) - 1 << "\n";
	
	return 0;
}