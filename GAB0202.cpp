#include <bits/stdc++.h>
#define MAXN 25
#define MAXB 2005

using namespace std;

typedef long long ll;

ll S[MAXN];
bool dp[MAXN][MAXB][MAXB];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAB0202";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
    ll N;

    cin >> N;

    for (ll i = 0; i < N; i++) {
        cin >> S[i];
    }

    dp[0][S[0]][0] = true;
    dp[0][0][S[0]] = true;
    dp[0][0][0] = true;

    ll sum = S[0];

    for (ll i = 1; i < N; i++) {
        sum += S[i];

        for (ll a = 0; a < MAXB; a++) {
            for (ll b = 0; b < MAXB; b++) {
                if (a - S[i] >= 0) {
                    dp[i][a][b] = dp[i][a][b] || dp[i - 1][a - S[i]][b];
                }
                if (b - S[i] >= 0) {
                    dp[i][a][b] = dp[i][a][b] || dp[i - 1][a][b - S[i]];
                }
                if (sum - a - b - S[i] >= 0) {
                    dp[i][a][b] = dp[i][a][b] || dp[i - 1][a][b];
                }
            }
        }
    }

    ll a = ceil((double) sum / 3);

    for (; a < MAXB; a++) {
        for (ll b = 0; b < MAXB; b++) {
            if (dp[N - 1][a][b]) {
                cout << a << "\n";
                return 0;
            }
        }
    }
	
	return 0;
}