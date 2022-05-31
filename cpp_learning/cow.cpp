#include <bits/stdc++.h>
#include <cmath>

#define ll long long
#define MAX_N 100050

using namespace std;

struct CW {
	ll c = 0, w = 0;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s = "cow";
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
	
	CW counts[MAX_N];
	
	ll N;
	cin >> N;
	
	ll ans = 0;
	
	string text;
	cin >> text;
	
	for (ll i = 0; i < N; i++) {
		counts[i + 1] = counts[i];
		switch (text[i]) {
			case 'C':
				counts[i + 1].c++;
				break;
			case 'W':
				counts[i + 1].w++;
				break;
		}
	}
	
	for (ll i = 0; i < N; i++) {
		if (text[i] == 'O') {
			ans += counts[i].c * (counts[N].w - counts[i].w);
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}