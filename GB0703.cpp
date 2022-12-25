#include <bits/stdc++.h>
#define MAXN 110
using namespace std;

typedef long long ll;

ll N;
vector<ll> original;

ll dp[MAXN][MAXN];

ll get_diff(ll a, ll b) {
    ll result = 0;
    for (ll i = a; i < b; i++) {
        ll val = i - a + 1;
        if (val != original[i]) {
            result++;
        }
    }
    if (original[b] != 0) {
        result++;
    }
    return result;
}

void solve_dp() {
    dp[1][1] = 0;
    if (original[1] != 0) {
        dp[1][1]++;
    }

    for (ll i = 2; i <= N; i++) {
        dp[i][1] = 1000;
        dp[1][i] = 1000;
    }

    for (ll i = 2; i <= N; i++) {
        for (ll breaks = 2; breaks <= N; breaks++) {
            dp[i][breaks] = 1000;

            if (breaks > i) {
                continue;
            }

            for (ll k = 1; k <= i - 1; k++) {
                ll poss = dp[k][breaks - 1] + get_diff(k + 1, i);
                dp[i][breaks] = min(dp[i][breaks], poss);
            }
            if (i == 6 && breaks == 6) {
                cout << get_diff(i + 1, N + 1) << " a\n";
            }
            dp[i][breaks] += get_diff(i + 1, N + 1);
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GB0703";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    original.push_back(-1);

    for (ll i = 0; i < N; i++) {
        ll a;
        cin >> a;
        original.push_back(a);
    }

    original.push_back(0);

    solve_dp();

    for (ll i = 1; i <= N; i++) {
        for (ll j = 1; j <= N; j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
	
	return 0;
}