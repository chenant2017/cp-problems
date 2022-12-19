#include <bits/stdc++.h>
#define MAXH 5010
#define MAXC 50010
using namespace std;

typedef long long ll;

ll C, H;
ll volumes[MAXH];
vector<ll> dp_prev;
vector<ll> dp_curr;

void solve_dp() {
    dp_prev = vector<ll>(C + 1, 0);
    dp_curr = vector<ll>(C + 1, 0);

    for (ll i = 1; i <= H; i++) {
        for (ll j = 0; j <= C; j++) {
            dp_curr[j] = dp_prev[j];
            if (j - volumes[i] >= 0) {
                dp_curr[j] = max(dp_curr[j], volumes[i] + dp_prev[j - volumes[i]]);
            }
        }
        dp_prev = dp_curr;
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GB0302";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> C >> H;

    for (ll i = 1; i <= H; i++) {
        cin >> volumes[i];
    }

    solve_dp();

    cout << dp_curr[C] << "\n";
	
	return 0;
}