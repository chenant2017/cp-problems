#include <bits/stdc++.h>

#define ll long long
#define f first
#define s second
#define MAXN 15

using namespace std;

ll N;
pair<ll, ll> points[MAXN];
ll xadj[MAXN];

bool traverse(ll start, map<ll, ll>& pairing) {
	bool hole = false;
	ll curr = pairing[start];

	while (true) {
		if (hole) {
			curr = pairing[curr];
		}
		else {
			curr = xadj[curr];
		}

		if (curr == start && !hole) {
			return true;
		}
		if (curr == -1) {
			return false;
		}

		hole = !hole;
	}
}

vector<map<ll, ll>> get_pairings(set<ll>& to_pair) {
	vector<map<ll, ll>> pairings;

	if (to_pair.size() == 2) {
		map<ll, ll> pairing;
		pairing[*to_pair.begin()] = *to_pair.rbegin();
		pairing[*to_pair.rbegin()] = *to_pair.begin();
		pairings.push_back(pairing);
		return pairings;
	}

	auto it = to_pair.begin();
	it++;

	for (; it != to_pair.end(); it++) {
		map<ll, ll> pairing;

		pairing[*to_pair.begin()] = *it;
		pairing[*it] = *to_pair.begin();
		set<ll> to_pair2 = to_pair;
		to_pair2.erase(*to_pair.begin());
		to_pair2.erase(*it);

		vector<map<ll, ll>> pairings2 = get_pairings(to_pair2);

		for (auto& i: pairings2) {
			for (auto& j: i) {
				pairing[j.f] = j.s;
			}
			pairings.push_back(pairing);
		}
	}
	return pairings;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "wormhole";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

	for (ll i = 0; i < N; i++) {
		cin >> points[i].f >> points[i].s;
	}

	sort(points, points + N, [](auto& a, auto& b) {
		return a.s < b.s || (a.s == b.s && a.f < b.f);
	});

	for (ll i = 0; i < N - 1; i++) {
		if (points[i].s == points[i + 1].s) {
			xadj[i] = i + 1;
		}
		else {
			xadj[i] = -1;
		}
	}

	xadj[N - 1] = -1;
	
	set<ll> to_pair;
	for (ll i = 0; i < N; i++) {
		to_pair.insert(i);
	}

	vector<map<ll, ll>> pairings = get_pairings(to_pair);

	ll ans = 0;

	for (auto& i: pairings) {
		bool cycle = false;
		for (ll j = 0; j < N; j++) {
			if (traverse(j, i)) {
				cycle = true;
				break;
			}
		}

		if (cycle) {
			ans++;
		}
	}

	cout << ans << "\n";

	return 0;
}