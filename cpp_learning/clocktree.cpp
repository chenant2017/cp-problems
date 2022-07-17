#include <bits/stdc++.h>

#define ll long long
#define MAXN 2510

using namespace std;

ll N;
vector<ll> adj[MAXN];
int clocks[MAXN];
bool visited[MAXN];
ll changes[MAXN] = {0};

ll get_change(ll start, ll prev) { //change that affects prev. clock
	//cout << start << "\n";
	if (visited[start]) {
		return 0;
	}
	visited[start] = true;

	ll change = 0;

	if (prev != -1 && adj[start].size() > 1) {
		change++;
	}

	for (auto i: adj[start]) {
		if (!visited[i]) {
			ll changei = get_change(i, start);
			change = (change + changei) % 12;

			if (adj[i].size() > 1) {
				change++;
			}
		}
	}

	if (prev != -1 && adj[start].size() == 1) {
		//cout << 12 - clocks[start] << " a " << start << "\n";
		return 12 - clocks[start];
	}
	else {
		//cout << change << " is change\n";
		//cout << 12 - (clocks[start] + change) % 12 << " b " << start << "\n";
		return 12 - (clocks[start] + change) % 12;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "clocktree";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);

	cin >> N;
	
	for (ll i = 1; i <= N; i++) {
		cin >> clocks[i];
		//cout << clocks[i] << " ";
	}
	//cout << "\n";

	for (ll i = 0; i < N - 1; i++) {
		ll a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	ll ans = 0;

	//cout << "hi\n";

	for (ll i = 1; i <= N; i++) {
		for (ll j = 1; j <= N; j++) {
			visited[j] = false;
		}
		//cout << "\n";
		ll change = get_change(i, -1);
		if (change % 12 == 0 || change % 12 == 11) {
			ans++;
		}
	}
	cout << ans << "\n";



	return 0;
}