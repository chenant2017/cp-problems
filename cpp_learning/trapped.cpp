#include <bits/stdc++.h>
#include <cmath>

#define ll long long
#define MAX_N 4000

using namespace std;

struct Haybale {
	ll pos, size;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s = "trapped";
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);\
	
	ll N;
	cin >> N;
	
	Haybale hbs[MAX_N];
	
	for (ll i = 0; i < N; i++) {
		cin >> hbs[i].size >> hbs[i].pos;
	}
	
	sort(hbs, hbs + N, [](auto &a, auto&b) {return a.pos < b.pos;});
	
	ll ans = 0;
	
	for (ll start = 0; start < N - 1; start++) {
		ll start_ = start;
		ll end = start + 1;
		
		while (true) {
			ll len = hbs[end].pos - hbs[start_].pos;
			if (len <= hbs[start_].size && len <= hbs[end].size) {
				ans += hbs[start + 1].pos - hbs[start].pos;
				break;
			}
			if (len > hbs[start_].size) {
				if (start_ == 0) {
					break;
				}
				start_--;
			}
			if (len > hbs[end].size) {
				if (end == N - 1) {
					break;
				}
				end++;
			}
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}