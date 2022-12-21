#include <bits/stdc++.h>
#define MAXN 10010
using namespace std;

typedef long long ll;

ll N, K;
ll s[MAXN];
ll dp[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GB0403";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> K;

    for (ll i = 0; i < N; i++) {
        cin >> s[i];
    }

    dp[0] = s[0];
    for (ll i = 1; i < N; i++) {
        dp[i] = 0;

        ll smax = 0;
        for (ll j = 1; j <= min(K, i + 1); j++) {//size of the group that i is in
            smax = max(smax, s[i - j + 1]);
            dp[i] = max(dp[i], smax * j + dp[i - j]);
        }
    }
    cout << dp[N - 1] << "\n";
	
	return 0;
}