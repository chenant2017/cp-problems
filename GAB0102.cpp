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
            if (j > 0) {
                dp[i][j] += dp[i - 1][j - 1];
            }
            dp[i][j] += dp[i - 1][j];
        }
    }
}

ll get_prev(ll a, ll zeros) {
    ll result = 0;

    for (ll i = 1; i <= a; i++) {
        for (ll j = i - 1; j >= 0 && j + a - i >= zeros; j--) {
            cout << i << " " << j << " " << dp[i][j] << "ij\n";
            result += dp[i][j];
        }
    }
    
    return result + 1;
}

ll get_round(ll a) {
    if (a == 1) return 0;
    //cout << a << " a\n";

    ll len = floor(log2(a)) + 1;

    ll i = len - 2;

    while (i >= 0) {
        if ((a & (1 << i)) != 0) {
            break;
        }
        i--;
    }

    //cout << i << " i\n";

    if (i == -1) return 1;

    ll zeros = max(0ll, (ll) ceil((double) len / 2.0 ) - (len - 1 - i));

    cout << zeros << "\n";
 
    //cout << get_round(a % (1 << (i + 1))) << " " << get_prev(i, zeros) << "result\n";

    return get_round(a % (1 << (i + 1))) 
    + get_prev(i, zeros);
}

ll get_sol(ll a) {
    ll len = floor(log2(a)) + 1;
    ll z = ceil((double) len / 2.0);

    return get_round(a) + get_prev(len - 1, z);
}

int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	
	string fname = "GAB0102";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> A >> B;

    solve_dp();

    cout << get_sol(8) << " sol\n";
    cout << get_prev(2, 1) << " p\n";

    return 0;

    cout << get_sol(B) - get_sol(A - 1) << "\n";
	
	return 0;
}