#include <bits/stdc++.h>
#define MAXN 100010
#define MAXK 25
using namespace std;

typedef long long ll;

ll N, K;
ll moves[MAXN];
ll dp[MAXN][MAXK][3]; //moves, switches, last

void solve_dp() {
    for (ll i = 0; i <= K; i++) {
        for (ll j = 0; j < 3; j++) {
            dp[0][i][j] = 0;
        }
    }

    ll hcount = 0, pcount = 0, scount = 0;

    for (ll i = 1; i <= N; i++) {
        if (moves[i] == 0) hcount++;
        else if (moves[i] == 1) pcount++;
        else scount++;
        dp[i][0][0] = hcount;
        dp[i][0][1] = pcount;
        dp[i][0][2] = scount;
    }

    for (ll i = 1; i <= N; i++) {
        for (ll j = 1; j <= K; j++) {
            for (ll k = 0; k < 3; k++) {
                dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + 1);
                dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k]);
                for (ll l = 0; l < 3; l++) {
                    if (l == k) continue;
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][l]);
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][l] + 1);
                }
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "hps";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> K;

    for (ll i = 1; i <= N; i++) {
        char c;
        cin >> c;
        if (c == 'H') {
            moves[i] = 0;
        }
        else if (c == 'P') {
            moves[i] = 1;
        }
        else {
            moves[i] = 2;
        }
    }

    solve_dp();

    for (ll k = 0; k < 3; k++) {
        for (ll i = 0; i <= N; i++) {
            for (ll j = 0; j <= K; j++) {
                cout << dp[i][j][k] << " ";
            }
            cout << "\n";
        }
        cout << "\n\n";
    }
    
	return 0;
}