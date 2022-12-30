#include <bits/stdc++.h>
#define MAXD 5000
#define MAXK 15
using namespace std;

typedef long long ll;

ll N, K;
ll dp[MAXK][MAXD];
string ans = "";

void solve_dp() {
    for (ll d = 0; d < MAXD; d++) {
        dp[0][d] = 1;
    }

    for (ll i = 1; i <= K; i++) {
        dp[i][0] = 0;
    }

    for (ll i = 1; i <= K; i++) {
        for (ll d = 1; d < MAXD; d++) {
            dp[i][d] = dp[i - 1][d - 1] + dp[i][d - 1];
        }
    }
}

void get_string(ll n, ll i, ll d) {
    //cout << n << " " << i << " " << d << "\n";
    if (d == 0) return;
    if (n > dp[i][d - 1]) {
        ans += "1";
        get_string(n - dp[i][d - 1], i - 1, d - 1);
    }
    else {
        ans += "0";
        get_string(n, i, d - 1);
    }
}


int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	
	string fname = "GB0902";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> K;

    if (K == 1) {
        cout << 1;
        for (ll i = 0; i < N - 1; i++) {
            cout << 0;
        }
        cout << "\n";

        return 0;
    }

    solve_dp();

    for (ll d = K; d < MAXD; d++) {
        if (dp[K][d] >= N) {
            get_string(N, K, d);
            break;
        }
    }

    cout << ans << "\n";
	
	return 0;
}