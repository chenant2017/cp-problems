#include <bits/stdc++.h>
#define MAX 100010
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N, M;
pll edges[MAX];
vector<pll> adj[MAX];
bool visited[MAX];
bool dfs_visited[MAX];
bool e_visited[MAX];
bool fed[MAX];
vector<ll> ans;

ll edge_ignore;
ll start;

void get_start(ll i) {
    if (visited[i]) return;
    visited[i] = true;

    for (auto j: adj[i]) {
        if (e_visited[j.s]) continue;
        e_visited[j.s] = true;
        if (visited[j.f]) {
            
            edge_ignore = j.s;
            start = edges[j.s].f;
            return;
        }
        get_start(j.f);
    }
}

void dfs(ll i) {
    //cout << i << "i\n";
    if (dfs_visited[i]) return;
    dfs_visited[i] = true;

    for (auto j: adj[i]) {
        if (j.s == edge_ignore) {
            continue;
        }
        if (!dfs_visited[j.f]) {
            fed[j.s] = true;
            ans.push_back(j.s);
            dfs(j.f);
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "220103";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;

    for (ll i = 1; i <= N; i++) {
        ll a, b;
        cin >> a >> b;
        edges[i] = {a, b};
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
    }

    for (ll i = 1; i <= M; i++) {
        edge_ignore = -1;
        start = -1;

        get_start(i);

        if (start == -1) {
            start = i;
        }

        //cout << start << " " << edge_ignore << "\n";

        if (edge_ignore != -1) {
            fed[edge_ignore] = true;
            ans.push_back(edge_ignore);
        }

        dfs(start);
    }

    ll hungry = 0;

    for (ll i = 1; i <= N; i++) {
        if (!fed[i]) {
            ans.push_back(i);
            hungry++;
        }
    }

    cout << hungry << "\n";

    for (auto i: ans) {
        cout << i << "\n";
    }

	
	return 0;
}