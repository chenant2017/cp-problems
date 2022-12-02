#include <bits/stdc++.h>
#define MAXT 2510
#define f first
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pdl;

ll T, C, Ts, Te;
ll dists[MAXT];
vector<pdl> adj[MAXT];
bool visited[MAXT] = {false};

void dijkstra() {
    priority_queue<pdl, vector<pdl>, greater<pdl>> q;
    dists[Ts] = 0;
    q.push(pll({0, Ts}));

    while (!q.empty()) {
        auto c = q.top().s;
        q.pop();

        if (visited[c]) continue;
        visited[c] = true;

        for (auto i: adj[c]) {
            dists[i.s] = min(dists[i.s], dists[c] + i.f);
            q.push(pll({dists[i.s], i.s}));
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "teleporters";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> T >> C >> Ts >> Te;

    for (ll i = 0; i < C; i++) {
        ll R1, R2, Ci;
        cin >> R1 >> R2 >> Ci;

        adj[R1].push_back(pll({Ci, R2}));
        adj[R2].push_back(pll({Ci, R1}));
    }

    for (ll i = 1; i <= T; i++) {
        dists[i] = 1010 * 2500;
    }

    dijkstra();

    cout << dists[Te] << "\n";
	
	return 0;
}