#include <bits/stdc++.h>
#define MAXT 500
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll T, C, K;
ll adj[MAXT][MAXT] = {0};

ll dijkstra(ll Ts, ll Te) {
    vector<ll> dists (T, 1010 * MAXT);
    vector<bool> visited (T, false);
    dists[Ts] = 0;
    
    priority_queue<pll, vector<pll>, greater<pll>> q;

    q.push(pll({0, Ts}));

    while (!q.empty()) {
        auto curr = q.top();
        q.pop();

        if (visited[curr.s]) continue;
        visited[curr.s] = true;

        for (ll i = 0; i < T; i++) {
            if (adj[curr.s][i] != 0) {
                ll dist2 = dists[curr.s] + adj[curr.s][i];
                dists[i] = min(dists[i], dist2);
                q.push(pll({dists[i], i}));
            }
        }
    }

    return dists[Te];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "teleporters";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> T >> C >> K;

    ll R1, R2, E;
    for (ll i = 0; i < C; i++) {
        cin >> R1 >> R2 >> E;
        R1--; R2--;
        adj[R1][R2] = E;
        adj[R2][R1] = E;
    }

    ll Ts, Te;
    for (ll i = 0; i < K; i++) {
        cin >> Ts >> Te;
        Ts--; Te--;
        cout << dijkstra(Ts, Te) << "\n";
    }
	
	return 0;
}