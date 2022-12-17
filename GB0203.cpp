#include <bits/stdc++.h>
#define MAXS 400
#define MAXN 45

using namespace std;

typedef long long ll;

ll N;
ll dp[MAXN][MAXS] = {0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GB0203";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    ll sum = N * (N + 1) / 2;
    if (sum % 2 == 1) {
        cout << "0\n";
        return 0;
    } 

    ll half = sum / 2;
    dp[0][0] = 1;

    for (ll i = 1; i <= N; i++) {
        for (ll j = 0; j <= half; j++) {
            dp[i][j] += dp[i - 1][j];
            if (j - i >= 0) dp[i][j] += dp[i - 1][j - i];
        }
    }

    cout << dp[N][half] / 2 << "\n";
	
	return 0;
}