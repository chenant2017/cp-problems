#include <bits/stdc++.h>
#define MAXP 100010
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll C, P, B, A1, A2;
vector<pll> adj[MAXP];

ll distsB[MAXP];
ll distsA1[MAXP];
ll distsA2[MAXP];
bool visited[MAXP] = {false};

void dijkstra(ll i, ll* dists) {
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    for (ll i = 1; i <= P; i++) visited[i] = false;

    dists[i] = 0;
    pq.push({0, i});

    while (!pq.empty()) {
        auto c = pq.top().s;
        pq.pop();

        if (visited[c]) continue;
        visited[c] = true;

        for (auto j: adj[c]) {
            if (dists[j.s] > dists[c] + j.f) {
                dists[j.s] = dists[c] + j.f;
                pq.push({dists[j.s], j.s});
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAA0603";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> C >> P >> B >> A1 >> A2;

    for (ll i = 1; i <= P; i++) {
        distsB[i] = 2e9;
        distsA1[i] = 2e9;
        distsA2[i] = 2e9;
    }

    for (ll i = 0; i < C; i++) {
        ll p1, p2, d;
        cin >> p1 >> p2 >> d;

        adj[p1].push_back({d, p2});
        adj[p2].push_back({d, p1});
    }

    dijkstra(B, distsB);
    dijkstra(A1, distsA1);
    dijkstra(A2, distsA2);

    cout << min(distsB[A1] + distsA1[A2], distsB[A2] + distsA2[A1]) << "\n";
	
	return 0;
}