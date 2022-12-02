#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;

typedef long long ll;

ll N, M, Q;
vector<ll> adj[MAXN];
ll visited[MAXN] = {0};

void dfs(ll start, ll fill) {
    if (visited[start] != 0) return;  
    visited[start] = fill;
    for (auto i: adj[start]) {
        dfs(i, fill);
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "birthday";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M >> Q;

    for (ll i = 0; i < M; i++) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (ll i = 1; i <= N; i++) {
        dfs(i, i);
    }

    for (ll i = 1; i <= N; i++) {
        // cout << visited[i] << "\n";
    }

    for (ll i = 0; i < Q; i++) {
        ll a, b;
        cin >> a >> b;
        if (visited[a] == visited[b]) {
            cout << "Y\n";
        }
        else {
            cout << "N\n";
        }
    }
	
	return 0;
}