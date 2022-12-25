#include <bits/stdc++.h>
#define MAX 110
using namespace std;

typedef long long ll;

ll N;
vector<ll> original;
ll dp[MAX][MAX][MAX]; // curr, last breakout, # breakouts left
bool ready[MAX][MAX][MAX] = {false};

ll get_dp(ll i, ll l, ll b) {
    if (ready[i][l][b]) return dp[i][l][b];

    if (i == N) {
        if (b > 1) {
            dp[i][l][b] = 1000;
        }
        else if (b == 1) {
            dp[i][l][b] = (original[N] != 0);
        }
        else {
            dp[i][l][b] = (original[N] != N - l);
        }
        ready[i][l][b] = true;
        return dp[i][l][b];
    }

    if (b == 0) {
        dp[i][l][b] = get_dp(i + 1, l, b) + (original[i] != i - l);
        ready[i][l][b] = true;
        return dp[i][l][b];
    }

    ll poss1 = get_dp(i + 1, l, b) + (original[i] != i - l);
    ll poss2 = get_dp(i + 1, i, b - 1) + (original[i] != 0); 
    dp[i][l][b] = min(poss1, poss2);

    ready[i][l][b] = true;
    return dp[i][l][b];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GB0703";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    original.push_back(0);

    for (ll i = 0; i < N; i++) {
        ll a;
        cin >> a;
        original.push_back(a);
    }

    for (ll i = 0; i < N; i++) {
        cout << get_dp(1, 1, i) << "\n";
    }

    for (ll i = 1; i <= N; i++) {
        for (ll j = 1; j <= N; j++) {
            for (ll k = 0; k <= N; k++) {
                cout << dp[i][j][k] << " ";
            }
            cout << "\n";
        }
        cout << "\n\n";
    }
	
	return 0;
}