#include <bits/stdc++.h>
#define MAXN 1005
using namespace std;

typedef long long ll;

ll N, L;
ll grass[MAXN];
ll dp[MAXN][MAXN][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAB0402";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> L;

    for (ll i = 0; i < N; i++) {
        cin >> grass[i];
    }

    sort(grass, grass + N);

    dp[0][N - 1][0] = grass[N - 1] - grass[0];
    dp[0][N - 1][1] = grass[N - 1] - grass[0];

    for (ll i = 0; i < N; i++) {
        for (ll j = N - 1; j > i; j--) { 
            if (i == 0 && j == N - 1) continue;

            ll to_eat = i + N - j;

            dp[i][j][0] = 1e18;
            dp[i][j][1] = 1e18;

            if (i > 0) {
                dp[i][j][0] = min(dp[i - 1][j][0] + to_eat * (grass[i] - grass[i - 1]), dp[i][j][0]);
                dp[i][j][1] = min(dp[i - 1][j][0] + to_eat * (grass[j] - grass[i]), dp[i][j][1]);
            }
            if (j < N - 1) {
                dp[i][j][0] = min(dp[i][j + 1][1] + to_eat * (grass[j] - grass[i]), dp[i][j][0]);
                dp[i][j][1] = min(dp[i][j + 1][1] + to_eat * (grass[j + 1] - grass[j]), dp[i][j][1]);
            }
        }
    }

    /*for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            cout << dp[i][j][0] << " ";
        }
        cout << "\n";
    }

    cout << "\n\n";

    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            cout << dp[i][j][1] << " ";
        }
        cout << "\n";
    }*/

    if (L < grass[0]) {
        cout << N * (grass[0] - L) + dp[0][1][0] << "\n";
        return 0;
    }
    if (L > grass[N - 1]) {
        cout << N * (grass[N - 1] - L) + dp[N - 2][N - 1][1] << "\n";
        return 0;
    }

    for (ll i = 0; i < N - 1; i++) {
        if (grass[i] <= L && L <= grass[i + 1]) {
            //cout << i << " i\n";
            ll dist1 = L - grass[i];
            ll dist2 = grass[i + 1] - L;

            ll ans = min(dist1 * N + dp[i][i + 1][0], 
                        dist2 * N + dp[i][i + 1][1]);

            if (i > 0) {
                ans = min(ans, dist1 * N + dp[i - 1][i][1]);
            }
            if (i + 2 < N) {
                ans = min(ans, dist2 * N + dp[i + 1][i + 2][0]);
            }

            cout << ans << "\n";
            break;
        }
    }
	
	return 0;
}