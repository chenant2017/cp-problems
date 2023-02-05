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
            result += dp[i][j];
        }
    }
    
    return result;
}

ll get_round(ll a) {
    cout << a << " a\n";

    ll len = floor(log2(a)) + 1;

    ll i = len - 2;

    cout << i << " starti\n";

    while (i >= 0) {
        if ((a & (ll)pow(2, i)) != 0) {
            break;
        }
        i--;
    }

    cout << i << " i\n";

    if (i == -1) return 1;

    ll zeros = max(0ll, (ll) ceil((double) len / 2.0 ) - (len - 2 - i));

    return get_round(a % ((ll)pow(2, i + 1))) + get_prev(i, zeros);
}

int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	
	string fname = "GAB0102";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> A >> B;

    solve_dp();

    cout << get_round(12) << "\n";
	
	return 0;
}