#include <bits/stdc++.h>
#include <cmath>

#define ll long long
#define MAX_N 100100

using namespace std;

ll N, M, C;
ll arrivals[MAX_N];

bool works(ll wait) {
	ll start = 0;
	ll buses = 1;
	
	for (ll end = 0; end < N; end++) {
		if (arrivals[end] - arrivals[start] > wait || end - start >= C) {
			buses++;
			if (buses > M) {
				return false;
			}
			start = end;
		}
	}
	
	if (buses > M) {
		return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s = "convention";
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
	
	
	cin >> N >> M >> C;
	
	for (ll i = 0; i < N; i++) {
		cin >> arrivals[i];
	}
	
	sort(arrivals, arrivals + N);
	
	ll ptr = 0;
	ll jump = (arrivals[N - 1] - arrivals[0]) / 2;
	
	while (jump > 0) {
		if (!works(ptr + jump)) {
			ptr += jump;
		}
		else {
			jump /= 2;
		}
	}
	
	cout << ptr + 1 << "\n";
	
	return 0;
}

