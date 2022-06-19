#include <bits/stdc++.h>
#include <cmath>

#define ll long long

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "moobuzz";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	ll N; 
	cin >> N;

	ll result[8] = {1, 2, 4, 7, 8, 11, 13, 14};

	cout << result[(N - 1) % 8] + 15 * ((N - 1) / 8) << "\n";

	return 0;
}