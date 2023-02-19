#include <bits/stdc++.h>
#define MAXN 5010
using namespace std;

typedef long long ll;

ll N, M;
vector<ll> pars[MAXN];
vector<ll> chs[MAXN];
bool readyp[MAXN];
bool readyc[MAXN];
ll dpp[MAXN];
ll dpc[MAXN];

ll get_dp(ll i, bool* ready, vector<ll>* adj, ll* dp) {
    if (ready[i]) return dp[i];
    ready[i] = true;

    if (adj[i].empty()) {
        dp[i] = 1;
        return 1;
    }

    for (auto j: adj[i]) {
        dp[i] += get_dp(j, ready, adj, dp);
    }

    return dp[i];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAB0304";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;

    for (ll i = 0; i < M; i++) {
        ll a, b;
        cin >> a >> b;
        pars[b].push_back(a);
        chs[a].push_back(b);
    }

    get_dp(N, readyp, pars, dpp);
    
    for (ll i = 1; i <= N; i++) {
        if (pars[i].empty()) {
            get_dp(i, readyc, chs, dpc);
        }
    }

    ll ans = 0;

    for (ll i = 1; i <= N; i++) {
        for (auto j: chs[i]) {
            ans = max(ans, dpp[i] * dpc[j]);
        }
    }

    cout << ans << "\n";
	
	return 0;
}