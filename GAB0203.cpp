#include <bits/stdc++.h>
#define MAXN 110
#define MAXK 10
using namespace std;

typedef long long ll;

ll N, K;
ll r[MAXN];
ll dp[MAXK][MAXN][MAXN];

ll dist(ll a, ll b) {
    return (N + b - a) % N;
}

ll go_back(ll a, ll b) {
    return dist(b, a);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAB0203";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> K;

    for (ll i = 0; i < N; i++) {
        cin >> r[i];
    }

    ll ans = 1e18;

    for (ll start = 0; start < N; start++) {

        for (ll d = 1; d <= K; d++) {
            for (ll i = 0; i < N; i++) {
                for (ll j = 0; j < N; j++) {
                    dp[d][i][j] = 1e18;
                }
            }
        }

        dp[1][start][start] = 0;

        for (ll i = start + 1; i < start + N; i++) {
            dp[1][i % N][start] = dp[1][go_back(i, 1)][start] + 
                                    r[i % N] * dist(start, i);
        }

        for (ll d = 2; d <= K; d++) {
            for (ll i = start; i < start + N; i++) {
                for (ll j = start; j < i; j++) {
                    ll ii = i % N;
                    ll jj = j % N;

                    ll p = go_back(i, 1);

                    dp[d][ii][jj] = 
                        min(dp[d][ii][jj], 
                            dp[d][p][jj] + dist(j, i) * r[ii]);

                    dp[d][ii][ii] = min(dp[d][ii][ii], dp[d - 1][p][jj]);
                }
            }
        }

        auto vals = dp[K][go_back(start, 1)];
        ans = min(ans, *min_element(vals, vals + N));
    }

    cout << ans << "\n";
	
	return 0;
}