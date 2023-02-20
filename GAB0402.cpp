#include <bits/stdc++.h>
#define MAX 1010
using namespace std;

typedef long long ll;

ll N, L;
ll grass[MAX];
ll dp[MAX][MAX][2];

void reset_dp() {
    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            dp[i][j][0] = 1e18;
            dp[i][j][1] = 1e18;
        }
    }
}

void get_dp() {
    for (ll i = N - 1; i >= 0; i--) {
        for (ll j = i + 1; j < N; j++) {
            ll to_eat = N + i - j;
            dp[i][j][0] = min(dp[i + 1][j][0] + to_eat * (grass[i + 1] - grass[i]),
                                dp[i + 1][j][1] + to_eat * (grass[j] - grass[i]));
            dp[i][j][1] = min(dp[i][j - 1][0] + to_eat * (grass[j] - grass[i]),
                                dp[i][j - 1][1] + to_eat * (grass[j] - grass[j - 1]));
        }
    }
}   

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

    ll ans = 1e18;

    if (L <= grass[N - 1]) {
        reset_dp();
        
        ll start;
        for (start = 0; start < N; start++) {
            if (grass[start] >= L) break;
        }

        dp[start][start][0] = N * (grass[start] - L);
        dp[start][start][1] = N * (grass[start] - L);

        get_dp();

        ans = min(ans, min(dp[0][N - 1][0], dp[0][N - 1][1]));
    }
    if (L >= grass[0]) {
        reset_dp();
        
        ll start;
        for (start = N - 1; start >= 0; start--) {
            if (grass[start] <= L) break;
        }

        dp[start][start][0] = N * (L - grass[start]);
        dp[start][start][1] = N * (L - grass[start]);

        get_dp();

        ans = min(ans, min(dp[0][N - 1][0], dp[0][N - 1][1]));
    }

    cout << ans << "\n";
	
	return 0;
}