#include <bits/stdc++.h>
#define MAX 1010
using namespace std;

typedef long long ll;

ll N, M, C;
ll dp[MAX][MAX] = {0};
ll m[MAX];

vector<ll> parents[MAX];

void solve_dp() {
    for (ll day = 0; day < MAX; day++) {
        for (ll city = 0; city <= N; city++) {
            dp[day][city] = -1;
        }
    }

    dp[0][1] = 0;


    for (ll day = 1; day < MAX; day++) {
        for (ll city = 1; city <= N; city++) {
            for (auto p: parents[city]) {
                if (dp[day - 1][p] >= 0) {
                    dp[day][city] = max(dp[day][city], dp[day - 1][p] + m[city]);
                }
            }
            //cout << dp[day][city] << " ";
        }
        //cout << "\n";
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GB1103";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M >> C;

    for (ll i = 1; i <= N; i++) {
        cin >> m[i];
    }

    for (ll i = 0; i < M; i++) {
        ll a, b;
        cin >> a >> b;
        parents[b].push_back(a);
    }

    solve_dp();

    ll ans = 0;

    for (ll i = 1; i < MAX; i++) {
        ans = max(ans, (ll) (dp[i][1] - C * pow(i, 2)));
    }
	
    cout << ans << "\n";

	return 0;
}