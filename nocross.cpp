#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;

typedef long long ll;

ll N;
ll fields1[MAXN];
ll fields2[MAXN];
vector<ll> prev_maxes(MAXN);
vector<ll> curr_maxes(MAXN);
vector<ll> prev_dp(MAXN);
vector<ll> curr_dp(MAXN);

ll solve_dp() {
    ll result = 0;

    for (ll i = 0; i <= N; i++) {
        prev_dp[i] = 0;
        prev_maxes[i] = 0;
    }

    for (ll i = 1; i <= N; i++) {
        curr_dp[0] = 0;
        curr_maxes[0] = 0;

        for (ll j = 1; j <= N; j++) {
            curr_dp[j] = prev_maxes[j - 1];

            if (abs(fields1[i] - fields2[j]) <= 4) { 
                curr_dp[j]++;
            }

            result = max(result, curr_dp[j]);
            
            curr_maxes[j] = max(curr_dp[j], max(curr_maxes[j - 1], prev_maxes[j]));
        }   

        /*for (ll j = 1; j <= N; j++) {
            cout << curr_dp[j] << " ";
        }
        cout << "\n";*/

        prev_dp = curr_dp;
        prev_maxes = curr_maxes;
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