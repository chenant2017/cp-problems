#include <bits/stdc++.h>
#include <cmath>

#define ll long long

using namespace std;

int works(string longer, string shorter) {
	return (longer.substr(1) == shorter) + 
	(longer.substr(0, longer.size() - 1) == shorter);
}


ll poss_starts(string s) {
	ll ans = 0;
	
	ll longer = s.size() / 2 + 1;
	
	string s1 = s.substr(0, longer);
	string s11 = s.substr(longer);
	
	string s2 = s.substr(longer - 1);
	string s22 = s.substr(0, longer - 1);
	
	
	if (longer % 2 == 0) {
		ans += works(s1, s11) + works(s2, s22);
	}
	
	else {
		auto w = works(s1, s11);
		if (w > 0) {
			ans += w * poss_starts(s1);
		}
		
		w = works(s2, s22); 
		if (w > 0) {	
			ans += w * poss_starts(s2);
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