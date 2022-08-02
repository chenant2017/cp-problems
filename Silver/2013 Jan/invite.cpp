#include <bits/stdc++.h>

#define ll long long
#define MAXN 1000010
#define MAXG 250010

using namespace std;

ll N, G;
unordered_set<ll> cow_group[MAXN];
unordered_set<ll> group_cow[MAXG];
bool visited[MAXN] = {false};
bool included[MAXG] = {false};

ll get_cows(ll start) {
	queue<ll> cowq;
	cowq.push(start);
	ll result = 0;

	while (!cowq.empty()) {
		ll curr = cowq.front();
		cowq.pop();

		if (visited[curr]) {
			continue;
		}
		visited[curr] = true;
		result++;

		for (auto i: cow_group[curr]) {
			if (included[i]) {
				continue;
			}

			group_cow[i].erase(curr);

			if (group_cow[i].size() <= 1) {
				included[i] = true;
				if (group_cow[i].size() == 1) {
					cowq.push(*group_cow[i].begin());
				}
			}
		}
	}	
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "invite";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> G;

	for (ll i = 0; i < G; i++) {
		ll size;
		cin >> size;
		for (ll j = 0; j < size; j++) {
			ll a;
			cin >> a;
			cow_group[a].insert(i);
			group_cow[i].insert(a);
		}
	}

	cout << get_cows(1) << "\n";

	return 0;
}