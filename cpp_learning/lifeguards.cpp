#include <bits/stdc++.h>

#define ll long long
#define MAXN 100010

using namespace std;

ll N;
map<ll, ll> startend;
ll unique_time[MAXN] = {0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "lifeguards";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

	for (ll i = 0; i < N; i++) {
		ll a, b;
		cin >> a >> b;
		startend[a] = i;
		startend[b] = i;
	}

	unordered_set<ll> working;

	ll prevtime = 0;
	ll total = 0;

	for (auto& i: startend) {
		ll time = i.first;
		ll curr = i.second;
		bool end = false;

		if (!working.empty()) {
			total += time - prevtime;
		}
		if (working.size() == 1) {
			unique_time[*working.begin()] += time - prevtime;
		}

		if (working.find(curr) == working.end()) {
			working.insert(curr);
		}
		else {
			working.erase(curr);
		}

		prevtime = time;
	}


	ll min_unique_time = total + 10;
	for (ll i = 0; i < N; i++) {
		if (unique_time[i] < min_unique_time) {
			min_unique_time = unique_time[i];
		}
	}

	cout << total - min_unique_time << "\n";

	return 0;
}