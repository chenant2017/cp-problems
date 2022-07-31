//2022 Silver Feb #1

#include <bits/stdc++.h>
#define MAXN 510

typedef long long ll;

using namespace std;

ll N;
ll choices[MAXN][MAXN];
vector<ll> adj[MAXN];
unordered_set<ll> access[MAXN];


void dfs(ll start, ll curr) {
	if (access[start].find(curr) != access[start].end()) return;

	access[start].insert(curr);

	for (auto i: adj[curr]) {
		dfs(start, i);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N;

	for (ll i = 1; i <= N; i++) {
		for (ll j = 1; j <= N; j++) {
			cin >> choices[i][j];
		}
	}

	for (ll i = 1; i <= N; i++) {
		for (ll j = 1; j <= N; j++) {
			adj[i].push_back(choices[i][j]);
			if (choices[i][j] == i) break;
		}
	}

	for (ll i = 1; i <= N; i++) {
		bool visited[MAXN] = {false};
		dfs(i, i);
	}

	for (ll i = 1; i <= N; i++) {
		for (ll j = 1; j <= N; j++) {
			if (access[choices[i][j]].find(i) != access[choices[i][j]].end()) {
				cout << choices[i][j] << "\n";
				break;
			}
		}
	}

	return 0;
}