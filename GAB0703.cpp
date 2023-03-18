#include <bits/stdc++.h>
#define MAXT 1010
#define MAXA 100010
using namespace std;

typedef long long ll;

ll T, A, S, B;
ll N[MAXT];
ll dp[MAXT][MAXA];
ll prefix[MAXT][MAXA];

ll get_prefix(ll i, ll j1, ll j2) {
    if (j1 <= 0) {
        return prefix[i][j2];
    }
    else {
        return prefix[i][j2] - prefix[i][j1 - 1];
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAB0703";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> T >> A >> S >> B;

    for (ll i = 0; i < A; i++) {
        ll t;
        cin >> t;
        N[t]++;
    }

    dp[0][0] = 1;

    for (ll j = 0; j <= A; j++) {
        prefix[0][j] = 1;
    }

    for (ll i = 1; i <= T; i++) {
        dp[i][0] = 1;
        prefix[i][0] = 1;

        for (ll j = 1; j <= A; j++) {
            dp[i][j] = get_prefix(i - 1, j - N[i], j);
            prefix[i][j] = dp[i][j] + prefix[i][j - 1];
        }
    }

    /*for (ll i = 0; i <= T; i++) {
        for (ll j = 0; j <= A; j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }*/

    ll ans = 0;

    for (ll j = S; j <= B; j++) {
        ans += dp[T][j];
    }

    cout << ans << "\n";
    
	
	return 0;
}