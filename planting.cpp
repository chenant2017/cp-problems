#include <bits/stdc++.h>
#define MAXN 100010

using namespace std;

typedef long long ll;

vector<ll> adj[MAXN];
bool visited[MAXN];
ll N;

void dfs(ll start, ll& ans) {
    if (visited[start]) return;
    visited[start] = true;

    ans = max(ans, (ll) (1 + adj[start].size()));
    for (auto i: adj[start]) {
        if (!visited[i]) dfs(i, ans);
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "planting";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N - 1; i++) {
        ll a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ll ans = 1;

    dfs(1, ans);

    cout << ans << "\n";
	
	return 0;
}