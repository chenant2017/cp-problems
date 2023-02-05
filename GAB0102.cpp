#include <bits/stdc++.h>
#define MAX 35
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll dp[MAX][MAX];

ll A, B;

pll get_cell(ll a) {
    ll ones = 0;
    ll bits = floor(log2(a)) + 1;
    while (a > 1) {
        a -= pow(2, floor(log2(a)));
        ones++;
    }
    if (a == 1) ones++;

    return {bits, ones};
}

ll get_prev(ll a) {
    pll p = get_cell(a);
    if (a == 1) {
        return 0;
    }
    if (p.s == p.f - 1) {
        return pow(2, p.f - 2);
    }
    ll result = 0;
    for (ll i = 0; i < p.f - p.s - 1; i++) {
        result += pow(2, p.f - 1 - i);
    }
    return result;
}

ll get_round(ll a) {
    if (a == 0) return 1;
    if (a == 1) return 1;
    ll result = 0;
    pll p = get_cell(a);

    if (p.s >= ceil((double) p.f / 2.0)) {
        result += a - get_prev(a);
    }

    for (ll i = 1; i < MAX; i++) {
        for (ll j = i - 1; j >= 0; j--) {
            if (p == pll({i, j})) return result;
            if (j >= ceil((double) i / 2.0)) {
                result += dp[i][j];
                //cout << i << " " << j << " " << dp[i][j] << "\n";
            }
        }
    }

    return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAB0102";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
    cin >> A >> B;

    dp[1][0] = 1;
    for (ll i = 2; i < MAX; i++) {
        for (ll j = 0; j < MAX; j++) {
            if (j > 0) {
                dp[i][j] += dp[i - 1][j - 1];
            }
            dp[i][j] += dp[i - 1][j];
        }
    }   

    //cout << get_cell(12).f << " " << get_cell(12).s << "\n";

    cout << get_round(B) - get_round(A - 1) << "\n";
	
	return 0;
}