#include <bits/stdc++.h>

#define ll long long

using namespace std;


ll N, K;
map<ll, ll> layers;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "paint";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> K;

	ll pos = 0;
	for (ll i = 0; i < N; i++) {
		ll a;
		string dir;
		cin >> a >> dir;
		ll start, end;

		if (dir[0] == 'R') {
			start = pos;
			end = pos + a;
			pos += a;
		}
		else {
			start = pos - a;
			end = pos;
			pos-= a;
		}

		if (layers.find(start) == layers.end()) {
			layers[start] = 1;
		}
		else {
			layers[start]++;
		}

		if (layers.find(end) == layers.end()) {
			layers[end] = -1;
		}
		else {
			layers[end]--;
		}
	}

	auto it = layers.begin();
	it++;
	for (; it != layers.end(); it++) {
		auto prev = it;
		prev--;
		it->second += prev->second;
	}

	ll ans = 0;

	it = layers.begin();
	auto endit = layers.end();
	endit--;

	for (; it != endit; it++) {
		auto next = it;
		next++;
		if (it->second >= K) {\
			ans += next->first - it->first;
		}
	}

	cout << ans << "\n";

	return 0;
}