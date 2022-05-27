#include <bits/stdc++.h>
#define MAX_N 100000
#define ll long long

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s = "lemonade";
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
	
	ll N;
	
	cin >> N;

	ll w[MAX_N];
	
	for (ll i = 0; i < N; i++) {
		cin >> w[i];
	}
	
	sort(w, w + N, [](auto& x, auto& y){return x > y;});
	
	ll line_length = 0;
	
	for (ll i = 0; i < N; i++) {
		if (line_length <= w[i]) {
			line_length++;
		}
	}
	cout << line_length << "\n";
	
	return 0;
}