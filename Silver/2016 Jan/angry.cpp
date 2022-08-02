#include <bits/stdc++.h>
#include <cmath>

#define ll long long
#define MAX_N 50000

using namespace std;

bool works(ll R, ll K, ll N, ll* bales) {
	ll used = 1;
	ll ptr1 = 0;
	ll ptr2 = 0;
	
	while (ptr2 < N) {
		if (bales[ptr2] > bales[ptr1] + 2 * R) {
			ptr1 = ptr2;
			used++;
			if (used > K) return false;
		}
		else {
			ptr2++;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s = "angry";
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
	
	ll N, K;
	cin >> N >> K;
	
	ll bales[MAX_N];
	
	for (ll i = 0; i < N; i++) {
		cin >> bales[i];
	}
	
	sort(bales, bales + N);
	
	ll ptr = bales[N - 1] / 2;
	ll jump = bales[N - 1] / 4;
	
	while (jump > 0) {
		if (works(ptr - jump, K, N, bales)) {
			ptr -= jump;
		}
		else {
			jump /= 2;
		}
	}
	
	cout << ptr << "\n";
	
	return 0;
}