#include <bits/stdc++.h>
#define MAXN 410
using namespace std;

typedef long long ll;

ll N, K;
ll snakes[MAXN];
ll last_max[MAXN][MAXN][MAXN];
ll dp[MAXN][MAXN][MAXN]; //index, nets, size of last group of groups

void solve_dp() {
    for (ll i = 0; i <= N; i++) {
        for (ll nets = 0; nets <= N; nets++) {
            for (ll last = 0; last <= N; last++)  {
                dp[i][nets][last] = 1e10;
            }
        }
    }

    dp[0][1][1] = 0;
    last_max[0][1][1] = snakes[0];

    for (ll i = 1; i < N; i++) {
        dp[i][1][i + 1] = dp[i - 1][1][i];
        if (last_max[i - 1][1][1] >= snakes[i]) {
            last_max[i][1][i + 1] = last_max[i - 1][1][i];
            dp[i][1][i + 1] += last_max[i - 1][1][i] - snakes[i];
        }
        else {
            last_max[i][1][i + 1] = snakes[i];
            dp[i][1][i + 1] += i * (snakes[i] - last_max[i - 1][1][i]);
        }
        

        for (ll nets = 2; nets <= K; nets++) {
            //last = 1

            dp[i][nets][1] = 1e10;
            for (ll j = 1; j <= i - 1; j++) {
                dp[i][nets][1] = min(dp[i][nets][1], dp[i - 1][nets - 1][j]);
            }
            cout << i << " " << nets << " " << dp[i][nets][1] << " a\n";

            for (ll last = 2; last <= N; last++) {
                dp[i][nets][last] = dp[i][nets][last - 1];
                if (last_max[i][nets][last - 1] >= snakes[i]) {
                    last_max[i][nets][last] = last_max[i][nets][last - 1];
                    dp[i][nets][last] += last_max[i][nets][last] - snakes[i];
                }
                else {
                    last_max[i][nets][last] = snakes[i];
                    dp[i][nets][last] += (last - 1) * (snakes[i] - last_max[i][nets][last - 1]);
                }
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GB1003";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> K;

    for (ll i = 0; i < N; i++) {
        cin >> snakes[i];
    }

    solve_dp();

    for (ll i = 0; i <= N; i++) {
        for (ll j = 0; j <= K; j++) {
            for (ll k = 0; k <= N; k++) {
                cout << dp[i][j][k] << " ";
            }
            cout << "\n";
        }
        cout << "\n\n";
    }
	
	return 0;
}