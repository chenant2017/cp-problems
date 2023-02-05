#include <bits/stdc++.h>
#define MAX 50010
using namespace std;

typedef long long ll;

ll N;
ll bales1[MAX];
ll bales2[MAX];
ll ldp[MAX];
ll rdp[MAX];

void solve_dp(ll* dp, ll* bales) {
    dp[0] = 0;
    ll j = -1;

    for (ll i = 1; i < N; i++) {
        while (bales[i] - bales[j + 1] >= dp[j + 1] + 1) {
            j++;
        }
        ll dp1 = max(bales[i] - bales[j], dp[j] + 1);
        ll dp2 = 1e18;
        if (j + 1 < i) {
            dp2 = max(bales[i] - bales[j + 1], dp[j + 1] + 1);
        }
        dp[i] = min(dp1, dp2);
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAB0103";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;
    
    for (ll i = 0; i < N; i++) {
        cin >> bales1[i];
        bales2[i] = -bales1[i];
    }

    sort(bales1, bales1 + N);
    sort(bales2, bales2 + N);
    
    solve_dp(ldp, bales1);
    solve_dp(rdp, bales2);

    reverse(rdp, rdp + N);

    /*for (ll i = 0; i < N; i++) {
        cout << rdp[i] << " ";
    }

    cout << "\n";

    for (ll i = 0; i < N; i++) {
        cout << ldp[i] << " ";
    }
    cout << "\n";*/

    double ans = 1e18;
    for (ll i = 0; i < N; i++) {
        ans = min(ans, (double) max(rdp[i], ldp[i]));
    }

    for (ll i = 0; i < N - 1; i++) {
        //cout << (double) bales1[i + 1] - bales1[i] / 2 << " " << (double) max(ldp[i], rdp[i + 1]) + 1 << "\n";
        double poss = max((double) (bales1[i + 1] - bales1[i]) / 2.0, (double) max(ldp[i], rdp[i + 1]) + 1.0);
        ans = min(ans, poss);
    }


    cout << fixed;
    cout << setprecision(1) <<ans << "\n";
	
	return 0;
}