#include <bits/stdc++.h>
#include <cmath>

#define ll long long

using namespace std;

struct Output {
	ll value, freq;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s = "pairup";
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
	
	ll N;
	ll M = 0;
	cin >> N;
	
	vector<Output> cows;
	cows.reserve(N);
	
	for (ll i = 0; i < N; i++) {
		Output op;
		cin >> op.freq >> op.value;
		cows.push_back(op);
		M += cows[i].freq;
	}
	
	sort(cows.begin(), cows.end(), [](auto &a, auto &b){return a.value < b.value;});
	
	ll ans = 0;
	ll ptr1 = 0;
	ll ptr2 = N - 1;
	
	while (ptr1 != ptr2) {
		if (cows[ptr1].freq == 0) {
			ptr1++;
		}
		if (cows[ptr2].freq == 0) {
			ptr2--;
		}
		ll sum = cows[ptr1].value + cows[ptr2].value;
		if (sum > ans) {
			ans = sum;
		}
		ll subtract = min(cows[ptr1].freq, cows[ptr2].freq);
		cows[ptr1].freq -= subtract;
		cows[ptr2].freq -= subtract;
	}
	
	cout << ans << "\n";
	
	return 0;
}