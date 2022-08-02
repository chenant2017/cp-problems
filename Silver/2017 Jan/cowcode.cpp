#include <bits/stdc++.h>
#include <cmath>

#define ll long long

using namespace std;

string ss;

char getchar(ll N, ll len) {
	while (N <= len) {
		len /= 2;
	}
	if (N <= ss.size()) {
		return ss[N - 1];
	}
	if (N == len + 1) {
		return getchar(N - 1, len);
	}
	return getchar(N - len - 1, len);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s = "cowcode";
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
	
	ll N;
	
	cin >> ss; 
	cin >> N;
	
	ll len = ss.size();
	
	while (len < N) {
		len *= 2;
	}
	
	cout << getchar(N, len) << "\n";
	
	return 0;
}
