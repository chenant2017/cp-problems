#include <bits/stdc++.h>
#define MAX 250
#define MOD (ll) (1e9 + 7)
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef unsigned char uc;
typedef unsigned short us;

map<us, ll> prefix[MAX][MAX];
ll total[MAX][MAX];
us colors[MAX][MAX];
ll dp[MAX][MAX];
us R, C, K;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAB0701";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> R >> C >> K;

    for (ll i = 0; i < R; i++) {
        for (ll j = 0; j < C; j++) {
            cin >> colors[i][j];
        }
    }

    dp[0][0] = 1;
    total[0][0] = 1;

    for (ll j = 0; j < C; j++) {
        prefix[0][j][colors[0][0]] = 1;
        total[0][j] = 1;
    }

    for (ll i = 1; i < R; i++) {
        for (ll j = 1; j < C; j++) {
            for (ll k = 0; k < i; k++) {
                dp[i][j] += total[k][j - 1] - prefix[k][j - 1][colors[i][j]];
                dp[i][j] = (dp[i][j] + MOD) % MOD;
            }
            prefix[i][j] = prefix[i][j - 1];
            prefix[i][j][colors[i][j]] += dp[i][j];
            prefix[i][j][colors[i][j]] = (prefix[i][j][colors[i][j]] + MOD) % MOD;
            total[i][j] = total[i][j - 1] + dp[i][j];
            total[i][j] = (total[i][j] + MOD) % MOD;

            assert(prefix[i][j].size() <= C);
        }
    }

    cout << dp[R - 1][C - 1] % MOD << "\n";
    

    /*for (ll i = 0; i < R; i++) {
        prefix[i][0][colors[i][0]] = dp[i][0];

        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

        for (ll j = 1; j < C; j++) {
            prefix[i][j] = prefix[i][j - 1];
            prefix[i][j][colors[i][j]] += dp[i][j];
        }
    }*/

	
	return 0;
}