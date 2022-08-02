#include <bits/stdc++.h>
#include <cmath>

#define ll long long

using namespace std;

ll N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "cardgame";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

	set<ll> elsie1;
	set<ll> elsie2;

	set<ll> bessie1;
	set<ll> bessie2;

	for (ll i = 1; i <= 2 * N; i++) {
		bessie1.insert(i);
	}

	ll a;

	for (ll i = 0; i < N / 2; i++) {
		cin >> a;
		elsie1.insert(a);
		bessie1.erase(a);
	}

	for (ll i = 0; i < N / 2; i++) {
		cin >> a;
		elsie2.insert(a);
		bessie1.erase(a);
	}

	for (ll i = 0; i < N / 2; i++) {
		bessie2.insert(*bessie1.begin());
		bessie1.erase(*bessie1.begin());
	}

	ll high_cards = 0;
	ll points = 0;
	for (ll i = *bessie1.rbegin(); i >= 1; i--) {
		if (bessie1.find(i) != bessie1.end()) {
			high_cards++;
		}
		else if (elsie1.find(i) != elsie1.end()) {
			if (high_cards > 0) {
				points++;
				high_cards--;
			}
		}
	}

	ll low_cards = 0;
	for (ll i = *bessie2.begin(); i <= 2 * N; i++) {
		if (bessie2.find(i) != bessie2.end()) {
			low_cards++;
		}
		else if (elsie2.find(i) != elsie2.end()) {
			if (low_cards > 0) {
				points++;
				low_cards--;
			}
		}
	}

	cout << points << "\n";

	return 0;
}