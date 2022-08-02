#include <bits/stdc++.h>
#include <cmath>

#define ll long long
#define MAXN 100010

using namespace std;

ll N, M, K;
ll cows[MAXN];
ll new_pos[MAXN];
ll result[MAXN];
bool visited[MAXN] = {false};

void reverse(ll l, ll r) {
	for (ll i = l; i <= (l + r - 1) / 2; i++) {
		ll temp = cows[i];
		cows[i] = cows[l + r - i];
		cows[l + r - i] = temp;
	}
}

void get_cycle(ll start) {
	vector<ll> cycle;

	ll curr = start;
	while (!visited[curr]) {
		visited[curr] = true;
		cycle.push_back(curr);
		curr = new_pos[curr];
	}

	for (ll i = 0; i < cycle.size(); i++) {
		result[cycle[(i + K) % cycle.size()]] = cycle[i];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "swap";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M >> K;

	for (ll i = 1; i <= N; i++) {
		cows[i] = i;
	}

	for (ll i = 0; i < M; i++) {
		ll l, r;
		cin >> l >> r;
		reverse(l, r);
	}

	for (ll i = 1; i <= N; i++) {
		new_pos[cows[i]] = i;
	}

	for (ll i = 1; i <= N; i++) {
		get_cycle(i);
	}

	for (ll i = 1; i <= N; i++) {
		cout << result[i] << "\n";
	}

	return 0;
}