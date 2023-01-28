#include <bits/stdc++.h>
#define MAXN 100010
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N, M;
ll dists[MAXN];
bool visited[MAXN];
vector<ll> pars[MAXN];
vector<pll> adj[MAXN];
set<ll> ans;

void dijkstra(ll i) {
    for (ll i = 1; i <= N; i++) {
        dists[i] = 1e18;
    }

    dists[i] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, i});

    while (!pq.empty()) {
        auto c = pq.top().s;
        pq.pop();

        if (visited[c]) continue;
        visited[c] = true;

        for (auto j: adj[c]) {
            if (dists[c] + j.f < dists[j.s]) {
                dists[j.s] = dists[c] + j.f;
                pars[j.s].clear();
            }
            if (dists[c] + j.f == dists[j.s]) {
                pars[j.s].push_back(c);
                pq.push({dists[j.s], j.s});
            }
        }
    }
}

void dfs(ll i) {
    if (ans.find(i) != ans.end()) return;
    ans.insert(i);

    for (auto j: pars[i]) {
        dfs(j);
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAA1103";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;

    for (ll i = 0; i < M; i++) {
        ll a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({w, b});
        adj[b].push_back({w, a});
    }

    dijkstra(1);
    dfs(N);

    auto it = ans.begin();
    while (*it != *ans.rbegin()) {
        cout << *it << " ";
        it++;
    }
    cout << *ans.rbegin() << "\n";
	
	return 0;
}