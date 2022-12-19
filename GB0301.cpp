#include <bits/stdc++.h>
#define MAXN 1010
#define MAXC 5010

using namespace std;

typedef long long ll;

ll N, C;
ll sizes[MAXN];
ll values[MAXN];
ll dp[MAXN][MAXC] = {0};

void solve_dp() {
    for (ll j = 0; j <= C; j++) {
        dp[0][j] = 0;
    }
    for (ll i = 1; i <= N; i++) {
        for (ll j = 0; j <= C; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - sizes[i] >= 0) {
                dp[i][j] = max(dp[i][j], values[i] + dp[i - 1][j - sizes[i]]);
            }
        }
    }
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GB0301";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> C;

    for (ll i = 1; i <= N; i++) {
        cin >> sizes[i] >> values[i];
    }
	
    solve_dp();

    cout << dp[N][C] << "\n";

	return 0;
}