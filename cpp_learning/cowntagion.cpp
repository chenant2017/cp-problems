#include <bits/stdc++.h>

#define ll long long
#define MAXN 100010

using namespace std;

ll N;
bool visited[MAXN] = {false};
vector<ll> adj[MAXN];

ll get_days(ll start) {
	queue<ll> q;
	q.push(start);

	ll days = 0;

	while (!q.empty()) {
		ll curr = q.front();
		q.pop();

		if (visited[curr]) {
			continue;
		}
		visited[curr] = true;

		ll neighbors = 0;
		for (auto i: adj[curr]) {
			if (!visited[i]) {
				q.push(i);
				neighbors++;
			}
		}

		days += ceil(log2(neighbors + 1)) + neighbors;
	}

	return days;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	//string fname = "cowntagion";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;
	for (ll i = 0; i < N - 1; i++) {
		ll a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	cout << get_days(1) << "\n";

	return 0;
}