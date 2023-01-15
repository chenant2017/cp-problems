#include <bits/stdc++.h>
#define MAX 200010
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N, M;
pll edges[MAX];
ll order[MAX];
ll ind[MAX];
vector<ll> adj[MAX];
ll parent[MAX];
ll sizes[MAX];
bool ans[MAX];

ll get_rep(ll i) {
    while (i != parent[i]) i = parent[i];
    return i;
}

void unite(ll i, ll j) {
    i = get_rep(i);
    j = get_rep(j);
    if (sizes[i] < sizes[j]) swap(i, j);
    sizes[i] += sizes[j];
    parent[j] = i;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAA0501";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;

    for (ll i = 0; i < M; i++) {
        ll a, b;
        cin >> a >> b;

        edges[i] = {a, b};
    }

    for (ll i = 0; i < N; i++) {
        cin >> order[i];
        ind[order[i]] = i;
    }

    for (ll i = 0; i < M; i++) {
        if (ind[edges[i].f] < ind[edges[i].s]) {
            adj[edges[i].f].push_back(edges[i].s);
        }
        else {
            adj[edges[i].s].push_back(edges[i].f);
        }
    }

    for (ll i = 1; i <= N; i++) {
        parent[i] = i;
        sizes[i] = 1;
    }

    ll comps = 0;

    for (ll i = N - 1; i >= 0; i--) {
        //cout << "adding " << order[i] << " " << i << "\n";

        ll joined = 0;

        for (auto j: adj[order[i]]) {
            if (get_rep(order[i]) != get_rep(j)) {
                unite(order[i], j);
                joined++;
            }
        }

        comps += 1 - joined;

        ans[i] = comps == 1;
    }
	
    for (ll i = 0; i < N; i++) {
        if (ans[i]) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

	return 0;
}