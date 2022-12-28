#include <bits/stdc++.h>
#define MAXN 1010
#define f first
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N;

void solve_dp(vector<vector<ll>>& dp, vector<pll>& targets) {
    for (ll curr = 0; curr < N; curr++) {
        for (ll pre = 0; pre < curr; pre++) {

            dp[curr][pre] = targets[curr].s + targets[pre].s;

            ll dist = targets[curr].f - targets[pre].f;
            pll search = pll({targets[pre].f - dist, (ll) 1e7});
            auto closest = lower_bound(targets.begin(), targets.end(), search);

            if (closest == targets.begin()) {
                continue;
            }

            closest--;

            for (ll i = 0; i < N; i++) {
                if (targets[i].f > closest->f) {
                    break;
                }

                dp[curr][pre] = max(dp[curr][pre], targets[curr].s + dp[pre][i]);
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GB0903";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    vector<pll> rtargets;
    vector<pll> ltargets;

    for (ll i = 0; i < N; i++) {
        pll t;
        cin >> t.f >> t.s;
        rtargets.push_back(t);
        ltargets.push_back({-t.f, t.s});
    }

    sort(rtargets.begin(), rtargets.end());
    sort(ltargets.begin(), ltargets.end());

    vector<vector<ll>> rdp(N, vector<ll>(N, 0));
    vector<vector<ll>> ldp(N, vector<ll>(N, 0));

    solve_dp(rdp, rtargets);
    solve_dp(ldp, ltargets);

    ll ans = 0;

    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            ans = max(ans, rdp[i][j]);
            ans = max(ans, ldp[i][j]);
        }
    }

    cout << ans << "\n";

	return 0;
}