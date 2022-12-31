#include <bits/stdc++.h>
#define MAXN 410

using namespace std;

typedef long long ll;

ll snakes[MAXN];
ll N, K;
ll dp[MAXN][MAXN];
ll groups[MAXN][MAXN];
ll sizes[MAXN][MAXN];

void solve_dp() {
    for (ll i = 0; i <= N; i++) {
        dp[i][0] = 1e10;
        groups[i][0] = 1e10;
        sizes[i][0] = -1;

        dp[1][i] = 1e10;
        groups[1][i] = 1e10;
        sizes[1][i] = -1;
    }
    dp[1][1] = 0;
    groups[1][1] = 1;
    sizes[1][1] = snakes[1];

    for (ll i = 2; i <= N; i++) {
        for (ll nets = 1; nets <= K + 1; nets++) {
            ll dp1 = dp[i - 1][nets - 1];
            ll groups1 = 1;
            ll sizes1 = snakes[i];


            ll dp2 = dp[i - 1][nets];
            ll groups2 = groups[i - 1][nets] + 1;
            ll sizes2;

            if (snakes[i] > sizes[i - 1][nets]) {
                sizes2 = snakes[i];
                dp2 += groups[i - 1][nets] * (snakes[i] - sizes[i - 1][nets]);
            }
            else {
                sizes2 = sizes[i - 1][nets];
                dp2 += sizes[i - 1][nets] - snakes[i];
            }

            if (dp1 >= dp2) {
                dp[i][nets] = dp2;
                groups[i][nets] = groups2;
                sizes[i][nets] = sizes2;
            }
            else {
                dp[i][nets] = dp1;
                groups[i][nets] = groups1;
                sizes[i][nets] = sizes1;
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

    for (ll i = 1; i <= N; i++) {
        cin >> snakes[i];        
    }

    solve_dp();

    cout << dp[N][K + 1] << "\n";
	
	return 0;
}