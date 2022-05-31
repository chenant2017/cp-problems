#include <bits/stdc++.h>
#include <cmath>

#define MAX_N 100050
#define ll long long

using namespace std;

struct Bcounts {
	ll h1 = 0, g2 = 0, j3 = 0;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s = "bcount";
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
	
	ll N, Q;
	cin >> N >> Q;
	
	Bcounts counts[MAX_N];
	
	for (ll i = 1; i <= N; i++) {
		int breed;
		cin >> breed;
		counts[i] = counts[i - 1];
		switch (breed) {
			case 1: counts[i].h1++; break;
			case 2: counts[i].g2++; break;
			case 3: counts[i].j3++; break;
		}
	}
	
	for (ll i = 0; i < Q; i++) {
		ll start, end;
		cin >> start >> end;
		cout << counts[end].h1 - counts[start-1].h1 << " ";
		cout << counts[end].g2 - counts[start-1].g2 << " ";
		cout << counts[end].j3 - counts[start-1].j3 << "\n";
	}
	
	return 0;
}