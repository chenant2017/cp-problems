#include <bits/stdc++.h>
#define MAXV 50010
#define MAXK 15
#define f first
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll V, E, K;
vector<pll> adj[MAXV];
vector<ll> tsorted;
bool visited[MAXV];
ll dp[MAXV][MAXK];

void solve_dp() {
    for (ll i = 0; i <= K; i++) {
        dp[tsorted[0]][i] = 0;
    }

    for (ll i = 1; i < V; i++) {
        for (ll j = 0; j <= K; j++) {

            ll success = 0;
            ll fail = -1;
            for (auto& a: adj[tsorted[i]]) {
                ll s = a.s + dp[a.f][j];
                success = max(success, s);
                if (j > 0) {
                    ll f = a.s + dp[a.f][j - 1];
                    if (fail == -1 || f < fail) fail = f;
                }
            }

            if (j == 0) {
                dp[tsorted[i]][j] = success;
            }
            else {
                dp[tsorted[i]][j] = min(success, fail);
            }
        }
    }
}

void tsort(ll start) {
    if (visited[start]) return;
    visited[start] = true;

    for (auto i: adj[start]) {
        if (!visited[i.f]) tsort(i.f);
    }

    tsorted.push_back(start);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "slide";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> V >> E >> K;

    for (ll i = 0; i < E; i++) {
        ll p, q, f;
        cin >> p >> q >> f;
        adj[p].push_back(pll({q, f}));
    }

    tsort(1); 
    
    solve_dp();

    cout << dp[1][K] << "\n";
	
	return 0;
}