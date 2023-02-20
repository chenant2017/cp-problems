#include <bits/stdc++.h>
#define MAX 1510
using namespace std;

typedef long long ll;

ll N, S;
ll D;
ll P[MAX];
ll def[MAX]; // default
ll dp[MAX][MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAB0403";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> S;

    D = (S - 1) / (N - 1);

    for (ll i = 0; i < N; i++) {
        cin >> P[i];
    }

    sort(P, P + N);

    for (ll i = 0; i < N; i++) {
        def[i] = 1 + i * D;
    }

    ll moves = S - def[N - 1];

    for (ll j = 0; j <= moves; j++) {
        dp[1][j] = abs(def[1] + j - P[1]);
    }

    for (ll i = 2; i < N; i++) {
        dp[i][0] = abs(def[i] - P[i]) + dp[i - 1][0];

        for (ll j = 1; j <= moves; j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + abs(def[i] + j - P[i]);
        }
    }

    /*for (ll i = 1; i < N; i++) {
        for (ll j = 0; j <= moves; j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }*/

    cout << dp[N - 1][moves] + abs(def[0] - P[0]) << "\n";
	
	return 0;
}