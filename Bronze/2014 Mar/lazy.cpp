#include <bits/stdc++.h>
#include <cmath>

#define ll long long
#define MAX_N 100100

using namespace std;

struct Patch {
	ll g = 0, x = -1;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s = "lazy";
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
	
	ll N, K;
	cin >> N >> K;
	
	Patch patches[MAX_N];
	
	for (ll i = 1; i <= N; i++) {
		cin >> patches[i].g >> patches[i].x;
	}
	
	sort(patches + 1, patches + N + 1, [](auto& a, auto& b) {return a.x < b.x;});
	
	for (ll i = 1; i <= N; i++) {
		patches[i].g += patches[i - 1].g;
	}
	
	ll max_g = 0;
	ll ptr2 = 1;
	for (ll ptr1 = 1; ptr1 <= N; ptr1++) {
		while (patches[ptr2].x - patches[ptr1].x <= 2 * K && ptr2 < N) {
			ptr2++;
		}
		if (patches[ptr2].x - patches[ptr1].x > 2 * K) {
			ptr2--;
		}
		ll total = patches[ptr2].g - patches[ptr1 - 1].g;
		if (total > max_g) {
			max_g = total;
		}
	}
	
	cout << max_g << "\n";
	
	return 0;
}