#include <bits/stdc++.h>
#define MAXN 10010
#define f first
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N, M;
ll D[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GB1102";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
    cin >> N >> M;

    vector<pll> prev_dp(M + 1);
    vector<pll> curr_dp(M + 1);

    for (ll i = 0; i < N; i++) {
        cin >> D[i];
        fill(curr_dp.begin(), curr_dp.end(), pll({0, 0}));

        if (i != 0) {
            ll c = max(prev_dp[1].s, prev_dp[0].s);
            curr_dp[0] = pll({c, c});

            for (ll e = 1; e <= M; e++) {
                curr_dp[e] = pll({prev_dp[e - 1].f + D[i - 1], prev_dp[e - 1].f + D[i - 1]});

                if (e + 1 <= M) {
                    curr_dp[e].s = max(curr_dp[e].s, prev_dp[e + 1].s);
                }
            }
        }
        
        prev_dp = curr_dp;
    }
	
    cout << max(curr_dp[0].s, curr_dp[1].s) << "\n";

	
	return 0;
}