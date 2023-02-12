#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

typedef long long ll;

ll MOD = 1e9 + 7;
ll N, K;
vector<ll> adj[MAXN];
ll color[MAXN];
ll dp[MAXN][4];

ll dfs(ll i, ll p, ll c) {
    if (dp[i][c] != -1) {
        return dp[i][c];
    }

    if (color[i] != 0 && color[i] != c) {
        dp[i][c] = 0;
        return 0;
    }

    ll result = 1;
    
    for (auto j: adj[i]) {
        if (j == p) continue;
        ll r = 0;
        for (ll d = 1; d <= 3; d++) {
            if (d == c) continue;
            r += dfs(j, i, d) % MOD;
        }
        result *= r;
        result %= MOD;
    }

    dp[i][c] = result;
    return dp[i][c];
}

int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	
	string fname = "GAB0302";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> K;

    for (ll i = 0; i < N - 1; i++) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (ll i = 0; i < K; i++) {
        ll a, b;
        cin >> a >> b;
        color[a] = b;
    }

    for (ll i = 1; i <= N; i++) {
        for (ll j = 1; j <= 3; j++) {
            dp[i][j] = -1;
        }
    }



    cout << (dfs(1, -1, 1) + dfs(1, -1, 2) + dfs(1, -1, 3)) % MOD << "\n";
	
	return 0;
}