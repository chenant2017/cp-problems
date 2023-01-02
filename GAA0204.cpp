#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

typedef long long ll;

ll comps[MAXN];
ll edges[MAXN]; //edges per comp
ll sizes[MAXN];
vector<ll> adj[MAXN];
ll N, M;

void dfs(ll i, ll comp) {
    if (comps[i] != 0) return;
    comps[i] = comp;
    sizes[comp]++;

    for (auto j: adj[i]) {
        dfs(j, comp);
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAA0204";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
    cin >> N >> M;

    for (ll i = 0; i < M; i++) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ll comp = 0;
    for (ll i = 1; i <= N; i++) {
        if (comps[i] == 0) {
            comp++;
            dfs(i, comp);
        }
    }

    for (ll i = 1; i <= N; i++) {
        edges[comps[i]] += adj[i].size();
    }

    ll ans = 1;
	
    for (ll i = 1; i <= comp; i++) {
        if (edges[i] / 2 == sizes[i] - 1) {
            ans = (ans * sizes[i]) % ((ll) 1e9 + 7);
        }
        else {
            ans = (ans * 2) % ((ll) 1e9 + 7);
        }
    }

    cout << ans % ((ll) 1e9 + 7) << "\n";
	
	return 0;
}