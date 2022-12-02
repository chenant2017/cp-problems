#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;

typedef long long ll;

vector<ll> adj[MAXN];

ll N, M, Q;
ll comps[MAXN] = {0};

void dfs(ll i, ll comp) {
    if (comps[i] != 0) return;
    comps[i] = comp;

    for (auto j: adj[i]) {
        if (comps[j] == 0) dfs(j, comp);
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GA0902";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M >> Q;

    ll a, b;
    for (ll i = 0; i < M; i++) {
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
    
    for (ll i = 0; i < Q; i++) {
        cin >> a >> b;
        cout << ((comps[a] == comps[b]) ? "Y" : "N") << "\n";
    }
	
	return 0;
}