#include <bits/stdc++.h>

#define ll long long
#define f first
#define s second
#define MAXN 20010

using namespace std;

ll N, X, Y, Z;
map<ll, vector<ll>> startend;
pair<ll, ll> ranges[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "milktemp";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> X >> Y >> Z;

	for (ll i = 0; i < N; i++) {
		ll a, b;
		cin >> a >> b;
		startend[a].push_back(i);
		startend[b].push_back(i);
		ranges[i].f = a;
		ranges[i].s = b;
	}

	unordered_set<ll> overlap;

	ll max_overlap = 0;
	ll lower = 1000000010;
	ll upper = -1;

	for (auto& i: startend) {
		ll temp = i.f;
		vector<ll> to_process = i.s;
		vector<ll> to_remove;

		for (auto j: to_process) {
			if (overlap.find(j) == overlap.end()) {
				overlap.insert(j);
			}
			else {
				to_remove.push_back(j);
			}
		}

		/*cout << temp << " is temp\n";
		for (auto k: overlap) {
			cout << k << " ";
		}
		cout << "\n";*/

		if (overlap.size() > max_overlap) {
			lower = temp;
			upper = temp;
			max_overlap = overlap.size();
		}
		else if (overlap.size() == max_overlap) {
			if (temp < lower) {
				lower = temp;
			}
			if (temp > upper) {
				upper = temp;
			}
		}

		for (auto j: to_remove) {
			overlap.erase(j);
		}
	}

	ll optimal;

	if (X > Z) {
		optimal = lower;
	}
	else {
		optimal = upper;
	}

	ll ans = 0;
	for (ll i = 0; i < N; i++) {
		if (optimal < ranges[i].f) {
			ans += X;
		}
		else if (optimal > ranges[i].s) {
			ans += Z;
		}
		else {
			ans += Y;
		}
	}

	cout << ans << "\n";


	return 0;
}