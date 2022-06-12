#include <bits/stdc++.h>
#include <cmath>

#define ll long long
#define MAX_N 3010

using namespace std;

ll N, M;
vector<ll> adj[MAX_N];
set<ll> open;

void dfs(ll start, bool visited[MAX_N]) {
	if (visited[start] || open.find(start) == open.end()) {
		return;
	}
	visited[start] = true;	
	for (auto i: adj[start]) {
		if (!visited[i] && open.find(i) != open.end()) {
			dfs(i, visited);
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "closing";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;
	
	for (ll i = 0; i < M; i++) {
		ll a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	for (ll i = 1; i <= N; i++) {
		open.insert(i);
	}
	
	for (ll i = 0; i < N; i++) {
		bool visited[MAX_N] = {false};
		dfs(*open.begin(), visited);
		ll visited_count = 0;
		for (ll j = 1; j <= N; j++) {
			if (visited[j]) {
				visited_count++;
			}
		}
		if (visited_count == open.size()) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
		
		ll closing;
		cin >> closing;
		open.erase(closing);
		
	}
	
	
	return 0;
}