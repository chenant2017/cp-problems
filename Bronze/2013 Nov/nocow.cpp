#include <bits/stdc++.h>

#define ll long long
#define MAXADJ 35
#define MAXN 110

using namespace std;

ll N, K;
ll num_adj;
set<string> adjs[MAXADJ];
vector<string> missing[MAXN];
ll sizes[MAXADJ];
unordered_map<string, ll> adjloc;

ll adjsll(vector<string>& adjs1) {
	ll result = 0;

	for (ll i = 0; i < num_adj; i++) {
		result += sizes[i] * adjloc[adjs1[i]]; 
	}

	return result;
}

vector<string> lladjs(ll value) {
	vector<string> adjs1;
	for (ll i = 0; i < num_adj; i++) {
		ll a = value / sizes[i];

		auto it = adjs[i].begin();
		advance(it, a);
		adjs1.push_back(*it);
		value %= sizes[i];
	}
	return adjs1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "nocow";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> K;
	K--;

	for (ll i = 0; i < N; i++) {
		string curr;
		for (ll j = 0; j < 4; j++) {
			cin >> curr;
		}

		num_adj = 0;
		for (ll j = 0; j < 35; j++) {
			cin >> curr;
			if (curr == "cow.") {
				break;
			}
			num_adj++;
			adjs[j].insert(curr);
			missing[i].push_back(curr);
		}
	}

	sizes[num_adj - 1] = 1;
	for (ll i = num_adj - 2; i >= 0; i--) {
		sizes[i] = sizes[i + 1] * adjs[i + 1].size();
	}

	for (ll i = 0; i < num_adj; i++) {
		ll loc = 0;
		for (auto j: adjs[i]) {
			adjloc[j] = loc;
			loc++;
		}
	}

	ll values[MAXN];

	for (ll i = 0; i < N; i++) {
		ll value = adjsll(missing[i]);
		values[i] = value;
	}
	
	sort(values, values + N);

	for (ll i = 0; i < N; i++) {
		if (values[i] <=K) {
			K++;
		}
	}

	vector<string> result = lladjs(K);

	for (ll i = 0; i < num_adj - 1; i++) {
		cout << result[i] << " ";
	}
	cout << result[num_adj - 1] << "\n";

	return 0;
}