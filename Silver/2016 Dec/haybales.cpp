#include <bits/stdc++.h>

#define ll long long
#define f first
#define s second

using namespace std;

ll N, Q;
map<ll, ll> haybales;

ll get_value(const map<ll, ll>& m, ll i) {
	auto it = m.upper_bound(i);
	it--;
	return it->s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "haybales";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);

	cin >> N >> Q;

	for (ll i = 0; i < N; i++) {
		ll a;
		cin >> a;
		haybales[a]++;
	}

	haybales[-1] = 0;

	auto it = haybales.begin();
	it++;

	for (; it != haybales.end(); it++) {
		auto prev = it;
		prev--;
		it->s += prev->s;
	}

	for (ll i = 0; i < Q; i++) {
		ll a, b;
		cin >> a >> b;
		cout << get_value(haybales, b) - get_value(haybales, a - 1) << "\n";
	}

	return 0;
}