#include <bits/stdc++.h>
#define MAXN 100010

using namespace std;

typedef long long ll;

ll N, L;
ll lengths[MAXN];
vector<ll> adj[MAXN];
ll leaves[MAXN];
ll down[MAXN];
ll up[MAXN];
bool visited[MAXN];

ll get_leaves(ll i) {
    if (adj[i].empty() == 1) {
        leaves[i] = 1;
        return 1;
    }

    ll result = 0;

    for (auto j: adj[i]) {
        result += get_leaves(j);
    }

    leaves[i] = result;

    return result;
}

ll get_down(ll i) {
    ll result = 0;

    for (auto j: adj[i]) {
        result += get_down(j) + leaves[j] * lengths[j];
    }

    down[i] = result;
    return result;
}

ll get_up(ll i) {
    for (auto j: adj[i]) {
        up[j] = up[i] + 3 * (L - leaves[j]) + down[i] - down[j] - lengths[j] * leaves[j];
        get_up(j);
    }
    return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAA1004";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 1; i <= N; i++) {
        string name;
        cin >> name;
        lengths[i] = name.size() + 1;

        ll m; cin >> m;
        for (ll j = 0; j < m; j++) {
            ll a; cin >> a;
            adj[i].push_back(a);
        }
    }

    L = get_leaves(1);
    get_down(1);
    get_up(1);


    ll ans = 1e18;

    for (ll i = 1; i <= N; i++) {
        if (adj[i].empty()) continue;
        ans = min(ans, up[i] + down[i]);
    }

    cout << ans - L << "\n";

	
	return 0;
}