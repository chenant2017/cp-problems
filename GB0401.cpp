#include <bits/stdc++.h>
#define MAXN 510
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N, K;
pll cp[MAXN];
ll dp[MAXN][MAXN] = {0};
bool ready[MAXN][MAXN] = {false};

ll add_dist(ll a, ll b) {
    return abs(cp[a].f - cp[b].f) + abs(cp[a].s - cp[b].s);
}

ll get_dp(ll c, ll m) {
    if (ready[c][m]) return dp[c][m];

    if (m == 0) {
        if (c == 0) dp[c][m] = 0;
        else dp[c][m] = -1;
    }
    else {
        if (m > c) dp[c][m] = -1;
        else {
            ll min = -1;
            for (ll i = 0; i < c; i++) {
                ll gdp = get_dp(i, m - 1);
                if (gdp != -1) {
                    ll dist = gdp + add_dist(i, c);
                    if (dist != -1 && (min == -1 || dist < min)) {
                        min = dist;
                    }
                }
            }
            dp[c][m] = min;
        }
    }
    ready[c][m] = true;
    return dp[c][m];
}

ll solve_dp() {
    ll result = -1;
    for (ll m = N - 1 - K; m < N; m++) {
        ll gdp = get_dp(N - 1, m);
        if (result == -1 || gdp < result) {
            result = gdp;
        }
    }   
    return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GB0401";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> K;

    for (ll i = 0; i < N; i++) {
        cin >> cp[i].f >> cp[i].s;
    }

    cout << solve_dp() <<"\n";
	
	return 0;
}