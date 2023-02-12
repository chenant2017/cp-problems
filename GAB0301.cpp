#include <bits/stdc++.h>
#define MAXN 1010
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N, E;

vector<ll> adj [MAXN];
vector<pll> patches;
ll dists[MAXN][MAXN];
ll dp[MAXN];

void bfs(ll i) {
    vector<bool> visited (N + 1);

    queue<pll> q;
    q.push({0, i});

    while (!q.empty()) {
        auto c = q.front();
        q.pop();

        if (visited[c.s]) continue;
        visited[c.s] = true;
        dists[i][c.s] = c.f;

        for (auto a: adj[c.s]) {
            if (!visited[a]) q.push({c.f + 1, a});
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAB0301";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
    cin >> N >> E;

    for (ll i = 1; i <= N; i++) {
        ll Q, D;
        cin >> Q >> D;

        patches.push_back({Q, i});

        for (ll j = 0; j < D; j++) {
            ll a;
            cin >> a;
            adj[i].push_back(a);
        }
    }   

    sort(patches.begin(), patches.end());

    for (ll i = 1; i <= N; i++) {
        for (ll j = 1; j <= N; j++) {
            dists[i][j] = 1e18;
        }
        bfs(i);
    }

    for (ll i = 0; i < N; i++) {
        dp[i] = patches[i].f;
    }
    
    for (ll i = 1; i < N; i++) {
        for (ll j = 0; patches[j].f < patches[i].f; j++) {
            ll pis = patches[i].s;
            ll pjs = patches[j].s;
            ll poss = dp[j] - E * dists[pis][pjs] + patches[i].f;
            dp[i] = max(dp[i], poss);
        } 
    }
    
    cout << *max_element(dp, dp + N) <<"\n";
	
	return 0;
}