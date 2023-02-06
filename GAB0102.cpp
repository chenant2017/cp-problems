#include <bits/stdc++.h>
#define MAX 35
using namespace std;

typedef long long ll;

ll A, B;
ll dp[MAX][MAX];

void solve_dp() {
    dp[1][0] = 1;

    for (ll i = 2; i < MAX; i++) {
        for (ll j = 0; j < MAX; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
}

ll get_prev(ll a) {
    ll result = 0;

    for (ll i = 1; i <= a; i++) {
        for (ll j = i - 1; j >= (i + 1) / 2; j--) {
            //cout << i << " " << j << " " << dp[i][j] << "ij\n";
            result += dp[i][j];
        }
    }
    
    return result + 1;
}

ll up_to(ll i, ll j) {
    ll result = 0;
    for (ll k = i - 1; k >= j; k--) {
        result += dp[i][k];
    }
    return result;
}

ll get_round(ll a) {
    if (a < 2) return 1;

    ll len = floor(log2(a)) + 1;
    ll result = get_prev(len - 1);
    ll zeros = 0;

    //cout << result << " res\n";

    for (ll i = len - 2; i >= 0; i--) {
        //cout << i << " " << result << "\n";
        if ((a & (1 << i)) == 0) {
            zeros++;
        }
        else {
            ll need = max(0ll, (len + 1) / 2 - zeros - 1);
            //cout <<  up_to(i + 1, need) << " " << i + 1 << " " << need << "\n";
            result += up_to(i + 1, need);
        }
    }

    if (zeros >= (len + 1) / 2) result++;

    return result;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAB0102";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
    cin >> A >> B;

    solve_dp();

    //cout << get_round(12) << "\n";
	
    cout << get_round(B) - get_round(A - 1) << "\n";

	return 0;
}