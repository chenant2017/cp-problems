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
ll dp[MAXV][MAXK];
bool ready[MAXV][MAXK] = {false};

ll get_dp(ll i, ll j) {
    if (ready[i][j]) return dp[i][j];
    
    if (i == V) {
        dp[i][j] = 0;
        ready[i][j] = true;
        return dp[i][j];
    }

    ll success = 0;
    ll fail = -1;
    for (auto a: adj[i]) {
        ll s = a.s + get_dp(a.f, j);
        success = max(success, s);

        if (j > 0) {
            ll f = a.s + get_dp(a.f, j - 1);
            if (fail == -1 || f < fail) fail = f;
        }
    }

    if (j == 0) {
        dp[i][j] = success;
        ready[i][j] = true;
        return dp[i][j];
    }


    dp[i][j] = min(success, fail);
    ready[i][j] = true;
    return dp[i][j];
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

    cout << get_dp(1, K) << "\n";
	
	return 0;
}