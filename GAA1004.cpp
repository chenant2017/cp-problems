#include <bits/stdc++.h>
#define MAXN 100010
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

vector<ll> adj[MAXN];
bool visited[MAXN];
ll leaves[MAXN];
ll dists[MAXN];
ll lengths[MAXN];
ll ans[MAXN];

ll N;

ll get_leaves(ll i) {
    if (visited[i]) return 0;
    visited[i] = true;

    if (adj[i].size() == 1) {
        leaves[i] = 1;
        return 1;
    }

    ll result = 0;

    for (auto j: adj[i]) {
        result += get_leaves(j.s);
    }
    leaves[i] = result;
    return result;
}

void dijkstra(ll i) {
    for (ll i = 1; i <= N; i++) {
        dists[i] = 1e18;
    }

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, 1});
    dists[1] = 0;

    while (!pq.empty()) {
        auto c = pq.top().s;
        pq.pop();

        if (visited[c]) continue;
        visited[c] = true;

        for (auto i: adj[c]) {
            if (dists[i.s] > dists[c] + i.f) {
                dists[i.s] = dists[c] + i.f;
                pq.push({dists[i.s], i.s});
            }
        }
    }
}

void dfs(ll i) {
    if (visited[i]) return;
    visited[i] = true;

    for (auto j: adj[i]) {
        ans[j.s] = ans[i] + j.f * leaves[i] - 3 * leaves[j.s];
        dfs(j.s);
    }
}   

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAA1004";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
    cin >> N;

    for (ll i = 1; i <= N; i++) {
        string name; cin >> name;

        cout << name << " " << name.size() << "\n";

        lengths[i] = name.size();

        ll n; cin >> n;
        for (ll j = 0; j < n; j++) {
            ll k; cin >> k;
            adj[i].push_back({k});
            adj[k].push_back({i});
        }
    }

    for (ll i = 1; i <= N; i++) {
        for (auto j: adj[i]) {
            cout << j.f << " " << j.s << "    ";
        }
        cout << "\n";
    }

    get_leaves(1);

    for (ll i = 1; i <= N; i++) {
        visited[i] = false;
    }

    dijkstra(1);

    for (ll i = 1; i <= N; i++) {
        cout << dists[i] << "\n";
    }

	
	return 0;
}