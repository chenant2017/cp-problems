#include <bits/stdc++.h>
#define MAX 410
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N, K;
ll field[MAX][MAX];
ll prefix[MAX][MAX];
ll dp[MAX][MAX];

ll first(ll i, ll j) {
    pll start = {i + 1, j - K - 1};
    if (start.s < 0) {
        start.f -= (0 - start.s);
        start.s = 0;
    }

    pll end = {i - K, j};
    if (end.f < 1) {
        end.s -= (1 - end.f);
        end.f = 1;
    }

    return prefix[end.f][end.s] - prefix[start.f][start.s];
}

ll last(ll i, ll j) {
    pll start = {i + K + 1, j - 1};
    if (start.f > N + 1) {
        start.s += (N + 1 - start.f);
        start.f = N + 1;
    }

    pll end = {i, j + K};
    if (end.s > N) {
        end.f += (end.s - N);
        end.s = N;
    }

    return prefix[end.f][end.s] - prefix[start.f][start.s];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAB0504";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
    cin >> N >> K;
	
    for (ll i = 1; i <= N; i++) {
        for (ll j = 1; j <= N; j++) {
            cin >> field[i][j];
        }
    }

    for (ll i = N; i >= 1; i--) {
        for (ll j = 1; j <= N; j++) {
            prefix[i][j] = field[i][j] + prefix[i + 1][j - 1];
        }
    }

    for (ll j = 1; j <= N; j++) {
        //cout << j << " j\n";
        for (ll k = 1; k <= N; k++) {
            for (ll l = 1; l <= K + 1 - abs(j - k); l++) {
                //cout << l << " " << k << "\n";
                dp[1][j] += field[l][k];
            }
        }
    }


    for (ll i = 2; i <= N; i++) {
        for (ll k = 1; k <= N; k++) {
            for (ll l = 1; l <= K + 1 - abs(i - k); l++) {
                dp[i][1] += field[k][l];
            }
        }
    }

    /*for (ll i = 1; i <= N; i++) {
        for (ll j = 1; j <= N; j++) {
            cout << dp[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";*/

    for (ll i = 2; i <= N; i++) {
        for (ll j = 2; j <= N; j++) {
            dp[i][j] = dp[i - 1][j - 1] - first(i - 1, j - 1) + last(i, j);
        }
    }

    /*for (ll i = 1; i <= N; i++) {
        for (ll j = 1; j <= N; j++) {
            cout << dp[i][j] << "\t";
        }
        cout << "\n";
    }*/

    ll ans = 0;

    for (ll i = 1; i <= N; i++) {
        for (ll j = 1; j <= N; j++) {
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << "\n";
	
	return 0;
}