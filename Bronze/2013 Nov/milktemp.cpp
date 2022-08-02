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
	ll too_cold = N;
	ll just_right = 0;
	ll too_hot = 0;
	
	ll ans = 0;

	for (auto& i: startend) {
		ll temp = i.f;
		vector<ll> to_process = i.s;
		vector<ll> to_remove;

		for (auto j: to_process) {
			if (overlap.find(j) == overlap.end()) {
				overlap.insert(j);
				too_cold--;
				just_right++;
			}
			else {
				to_remove.push_back(j);
			}
		}

		ll milk = X * too_cold + Y * just_right + Z * too_hot;
		if (milk > ans) {
			ans = milk;
		}

		for (auto j: to_remove) {
			overlap.erase(j);
			too_hot++;
			just_right--;
		}
	}

	cout << ans << "\n";

	return 0;
}