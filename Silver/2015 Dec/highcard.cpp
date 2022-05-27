#include <bits/stdc++.h>
#define ll long long
#define MAX_N 50010

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s = "highcard";
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
	
	ll N;
	cin >> N;
	
	ll elsie[MAX_N];
	
	for (ll i = 0; i < N; i++) {
		cin >> elsie[i];
	}
	
	sort(elsie, elsie + N);
	
	ll high_cards = 0;
	ll points = 0;
	
	for (ll i = N - 1; i > -1; i--) {
		if (i == N - 1) {
			high_cards += 2 * N - elsie[i];
		}
		else {
			high_cards += elsie[i + 1] - elsie[i] - 1;
		}
		if (high_cards > 0) {
			high_cards--;
			points++;
		}
	}
	
	cout << points << "\n";
	
	return 0;
}