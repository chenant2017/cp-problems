#include <bits/stdc++.h>
#define MAXN 10010
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N, M;

vector<vector<pll>> adj1;
vector<vector<pll>> adj2;
vector<vector<pll>> adj3;

pair<vector<ll>, vector<ll>> dijkstra(vector<vector<pll>>& adj) {
    vector<ll> dists (N + 1, 1e15);
    vector<ll> children (N + 1);
    vector<bool> visited (N + 1, false);

    dists[N] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;

    pq.push({0, N});

    while (!pq.empty()) {
        auto curr = pq.top().s;
        pq.pop();
        if (visited[curr]) continue;
        visited[curr] = true;

        for (auto i: adj[curr]) {
            if (dists[i.s] > dists[curr] + i.f) {
                dists[i.s] = dists[curr] + i.f;
                children[i.s] = curr;
                pq.push({dists[i.s], i.s});
            }
        }
    }

    return {dists, children};
}

int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	
	string fname = "GAA0303";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;

    adj1.resize(N + 1);
    adj2.resize(N + 1);
    adj3.resize(N + 1);

    for (ll i = 0; i < M; i++) {
        ll a, b, p, q;
        cin >> a >> b >> p >> q;
        adj1[b].push_back({p, a});
        adj2[b].push_back({q, a});
    }

    vector<ll> children1 = dijkstra(adj1).s;
    vector<ll> children2 = dijkstra(adj2).s;
    
    for (ll i = 1; i <= N; i++) {
        for (auto a: adj1[i]) {
            ll length = 0;
            if (i != children1[a.s]) {
                length++;
            }
            if (i != children2[a.s]) {
                length++;
            }
            adj3[i].push_back({length, a.s});
        }
    }

    vector<ll> dists = dijkstra(adj3).f;

    cout << dists[1] << "\n";

	return 0;
}