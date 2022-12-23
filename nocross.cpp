#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;

typedef long long ll;

ll N;
ll fields1[MAXN];
ll fields2[MAXN];
vector<ll> prev_dp(MAXN);
vector<ll> curr_dp(MAXN);

ll solve_dp() {
    ll result = 0;

    for (auto& i: prev_dp) i = 0;

    for (ll i = 1; i <= N; i++) {
        curr_dp[0] = 0;
        for (ll j = 1; j <= N; j++) {
            curr_dp[j] = prev_dp[j - 1];
            if (abs(fields1[i] - fields2[j]) <= 4) { 
                curr_dp[j]++;
            }
            result = max(result, curr_dp[j]);
        }   

        /*for (ll j = 1; j <= N; j++) {
            cout << curr_dp[j] << " ";
        }
        cout << "\n";*/
        prev_dp = curr_dp;
    }

    return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "nocross";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 1; i <= N; i++) {
        cin >> fields1[i];
    }
    for (ll i = 1; i <= N; i++) {
        cin >> fields2[i];
    }

    cout << solve_dp() << "\n";
	
	return 0;
}