#include <bits/stdc++.h>
#define MAXN 100010
#define MAXK 25
using namespace std;

typedef long long ll;

ll N, K;
ll moves[MAXN];
vector<vector<ll>> prev_dp(MAXK, vector<ll>(3));
vector<vector<ll>> curr_dp(MAXK, vector<ll>(3));

ll solve_dp() {
    for (ll i = 0; i <= K; i++) {
        for (ll j = 0; j < 3; j++) {
            prev_dp[i][j] = 0;
            curr_dp[i][j] = 0;
        }
    }

    for (ll i = 1; i <= N; i++) {
        if (moves[i] == 0) curr_dp[0][0]++;
        else if (moves[i] == 1) curr_dp[0][1]++;
        else curr_dp[0][2]++;

        for (ll j = 1; j <= K; j++) {
            for (ll k = 0; k < 3; k++) {
                curr_dp[j][k] = prev_dp[j][k];
                for (ll l = 0; l < 3; l++) {
                    if (l == k) continue;
                    curr_dp[j][k] = max(curr_dp[j][k], prev_dp[j - 1][l]);
                }

                if (moves[i] == k) {
                    curr_dp[j][k]++;
                }
            }
        }
        prev_dp = curr_dp;
    }

    ll result = 0;
    for (ll i = 0; i < 3; i++) {
        result = max(result, curr_dp[K][i]);
    }

    return result;
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

    cout << solve_dp() << "\n";

    /*for (ll k = 0; k < 3; k++) {
        for (ll i = 0; i <= N; i++) {
            for (ll j = 0; j <= K; j++) {
                cout << dp[i][j][k] << " ";
            }
            cout << "\n";
        }
        cout << "\n\n";
    }*/

	return 0;
}