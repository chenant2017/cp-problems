#include <bits/stdc++.h>
#define MAXN 50000
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N, M;
vector<pll> adj[MAXN];
ll dists[MAXN];
bool visited[MAXN] = {false};

ll dijkstra(ll start, ll end) {
    for (ll i = 0; i < N; i++) {
        dists[i] = 1000 * N;
    }
    priority_queue<pll, vector<pll>, greater<pll>> q;
    dists[start] = 0;
    q.push(pll({0, start}));

    while (!q.empty()) {
        auto curr = q.top();
        q.pop();

        if (visited[curr.s]) continue;
        visited[curr.s] = true;

        for (auto j: adj[curr.s]) {
            ll newdist = dists[curr.s] + j.f;
            dists[j.s] = min(dists[j.s], newdist);
            q.push(pll({dists[j.s], j.s}));
        }
    }

    return dists[end];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "amazon";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
    cin >> N >> M;

    ll A, B, C;
    for (ll i = 0; i < M; i++) {
        cin >> A >> B >> C;
        A--;
        B--;
        adj[A].push_back(pll({C, B}));
        adj[B].push_back(pll({C, A}));
    }

    cout << dijkstra(0, N - 1) << "\n";
	
	return 0;
}