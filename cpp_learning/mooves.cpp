#include <bits/stdc++.h>
#define MAX 100010
using namespace std;

typedef long long ll;

ll N, K;
set<ll> reaches[MAX];
ll cows[MAX];
ll ind[MAX];
vector<bool> visited (MAX);
ll ans[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "mooves";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> K;

	for (ll i = 1; i <= N; i++) {
		cows[i] = i;
		reaches[i].insert(i);
	} 

	for (ll i = 1; i <= K; i++) {
		ll a, b;
		cin >> a >> b;
		swap(cows[a], cows[b]);
		reaches[cows[a]].insert(a);
		reaches[cows[b]].insert(b);
	}

	for (ll i = 1; i <= N; i++) {
		ind[cows[i]] = i;
	}

	for (ll i = 1; i <= N; i++) {
		if (visited[i]) continue;

		vector<ll> comp;
		set<ll> total_reaches;
		ll curr = i;
		while (!visited[curr]) {
			visited[curr] = true;
			comp.push_back(curr);
			for (auto j: reaches[curr]) {
				if (total_reaches.find(j) == total_reaches.end()) {
					total_reaches.insert(j);
				}
			}
			curr = ind[curr];
		}
		for (auto j: comp) {
			ans[j] = total_reaches.size();
		}
	}

	for (ll i = 1; i <= N; i++) {
		cout << ans[i] << "\n";
	}
	
	return 0;
}