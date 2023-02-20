#include <bits/stdc++.h>
#define MAXN 2510
using namespace std;

typedef long long ll;

ll N, L;
ll dp[MAXN][5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAB0501";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
    cin >> N;

    if (N % 2 == 0) {
        L = N / 2 - 1;
    }
    else {
        L = N / 2;
    }

    for (ll i = 1; i <= L; i++) {
        dp[i][1] = 1;
    }

    for (ll i = 2; i <= N; i++) {
        for (ll j = 2; j <= 4; j++) {
            
            for (ll k = 1; k <= L; k++) {
                if (i - k == 0) break;
                dp[i][j] += dp[i - k][j - 1];
            }
        }
    }

    cout << dp[N][4] << "\n";

	return 0;
}