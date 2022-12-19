#include <bits/stdc++.h>
#define MAXH 5010
#define MAXC 50010
using namespace std;

typedef long long ll;

ll C, H;
ll volumes[MAXH];
ll dp[MAXH][MAXC] = {{0}};

void solve_dp() {
    for (ll i = 0; i <= C; i++) {
        dp[0][i] = 0;
    }
    for (ll i = 1; i <= H; i++) {
        for (ll j = 0; j <= C; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - volumes[i] >= 0) {
                dp[i][j] = max(dp[i][j], volumes[i] + dp[i - 1][j - volumes[i]]);
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GB0302";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> C >> H;

    for (ll i = 1; i <= H; i++) {
        cin >> volumes[i];
    }

    solve_dp();

    cout << dp[H][C] << "\n";
	
	return 0;
}