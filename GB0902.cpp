#include <bits/stdc++.h>
#define MAXK 15
#define MAXD 30
using namespace std;

typedef long long ll;

ll N, K;
ll dp[MAXK][MAXD]; 

void solve_dp() {
    for (ll i = 0; i <= K; i++) {
        dp[i][0] = 0;
    }
    for (ll i = 0; i < MAXD; i++) {
        dp[0][i] = 0;
    }
    dp[0][0] = 1;

    for (ll i = 1; i <= K; i++) {
        for (ll j = 1; j < MAXD; j++) {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
        }   
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GB0902";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> K;

    solve_dp();

    ll sum = 0;
    for (ll i = 0; i < MAXD; i++) {
        sum += dp[K][i];
        if (sum >= N) {
            cout << i << "\n";
            break;
        }
    }
	
	return 0;
}