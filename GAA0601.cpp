#include <bits/stdc++.h>
#define MAX 40010
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll B, E, P, N, M;
vector<ll> adj[MAX];
ll dists1[MAX];
ll dists2[MAX];
ll distsN[MAX];
bool visited[MAX];

void bfs(ll i, ll* dists) {
    for (ll i = 1; i <= N; i++) {
        visited[i] = false;
    }

    queue<pll> q;
    q.push({i, 0});

    while (!q.empty()) {
        auto c = q.front();
        q.pop();

        if (visited[c.f]) continue;
        visited[c.f] = true;
        dists[c.f] = c.s;

        for (auto j: adj[c.f]) {
            if (!visited[j]) q.push({j, c.s + 1});
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAA0601";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> B >> E >> P >> N >> M;

    for (ll i = 0; i < M; i++) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(1, dists1);
    bfs(2, dists2);
    bfs(N, distsN);

    ll ans = -1;

    for (ll i = 1; i <= N; i++) {
        ll a = dists1[i] * B + dists2[i] * E + distsN[i] * P;
        if (ans == -1 || a < ans) {
            ans = a;
        }
    }

    cout << ans << "\n";
	
	return 0;
}