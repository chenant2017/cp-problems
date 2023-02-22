#include <bits/stdc++.h>
#define MAX 2020
#define MAXN 410
using namespace std;

typedef long long ll;

ll N, K;
ll field[MAX][MAX];
ll pdr[MAX][MAX];
ll pdl[MAX][MAX];
ll dp[MAXN][MAXN];

void get_prefix() {
    for (ll i = 1; i < MAX; i++) {
        for (ll j = 1; j < MAX; j++) {
            pdr[i][j] = field[i][j] + pdr[i - 1][j - 1];
        }
    }

    for (ll i = 1; i < MAX; i++) {
        for (ll j = 0; j < MAX - 1; j++) {
            pdl[i][j] += field[i][j] + pdl[i - 1][j + 1];
        }
    }
}

ll nw(ll i, ll j) {
    return pdl[i][j - K] - pdl[i - K - 1][j + 1];
}

ll ne(ll i, ll j) {
    return pdr[i][j + K] - pdr[i - K - 1][j - 1];
}

ll se(ll i, ll j) {
    return pdl[i + K][j] - pdl[i - 1][j + K + 1];
}

ll sw(ll i, ll j) {
    return pdr[i + K][j] - pdr[i - 1][j - K - 1];
}

ll n(ll i,ll j) {
    return nw(i, j) + ne(i, j) - field[i - K][j];
}

ll e(ll i, ll j) {
    return ne(i, j) + se(i, j) - field[i][j + K];
}

ll s(ll i, ll j) {
    return se(i, j) + sw(i, j) - field[i + K][j];
}

ll w(ll i, ll j) {
    return nw(i, j) + sw(i, j) - field[i][j - K];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAB0504";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> K;

    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            cin >> field[i + K + 1][j + K + 1];
        }
    }

    for (ll i = 0; i <= K; i++) {
        for (ll j = 0; j <= K - i; j++) {
            dp[0][0] += field[i + K + 1][j + K + 1];
        }
    }

    get_prefix();

    for (ll i = 0; i < N; i++) {
        if (i != 0) {
            dp[i][0] = dp[i - 1][0] + s(i + K + 1, K + 1) - n(i + K, K + 1);
        }   

        for (ll j = 1; j < N; j++) {
            dp[i][j] = dp[i][j - 1] + e(i + K + 1, j + K + 1) - w(i + K + 1, j + K);
        }
    }

    ll ans = 0;

    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << "\n";
	
	return 0;
}