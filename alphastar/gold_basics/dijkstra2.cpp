#include <bits/stdc++.h>
#define MAXV 50010
#define f first  
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll V, E, S;
vector<pll> adj[MAXV];
bool visited[MAXV] = {false};
ll dists[MAXV];

void dijkstra(ll S) {
    priority_queue<pll, vector<pll>, greater<pll>> q;
    q.push(pll({0, S}));

    while (!q.empty()) {
        auto curr = q.top();
        q.pop();

        if (visited[curr.s]) continue;
        visited[curr.s] = true;
        dists[curr.s] = curr.f;

        for (auto i: adj[curr.s]) {
            ll newdist = dists[curr.s] + i.f;
            if (!visited[i.s]) {
                q.push(pll({newdist, i.s}));
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "dijkstra2";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> V >> E >> S;

    for (ll i = 1; i <= V; i++) {
        dists[i] = 10000 * 50010;
    }

    for (ll i = 0; i < E; i++) {
        ll A, B, C;
        cin >> A >> B >> C;
        adj[A].push_back(pll({C, B}));
        adj[B].push_back(pll({C, A}));
    }

    dijkstra(S);

    for (ll i = 1; i <= V; i++) {
        if (dists[i] < 10000 * 50010)
            cout << dists[i] << "\n";
        else cout << "-1\n";
    }
	
	return 0;
}