#include <bits/stdc++.h>
#define MAX 1010
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll H, G;
pll hcows[MAX];
pll gcows[MAX];
pll dp[MAX][MAX]; //H, G;

ll dist(pll p1, pll p2) {
    return pow(p1.f - p2.f, 2) + pow(p1.s - p2.s, 2);
}

ll solve_dp() {
    for (ll i = 0; i <= H; i++) {
        for (ll j = 0; j <= G; j++) {
            dp[i][j] = pll({pow(10, 6) * 3000, pow(10, 6) * 3000});
        }
    }

    dp[1][0].f = 0;

    for (ll i = 2; i <= H; i++) {
        dp[i][0].f = dp[i - 1][0].f + dist(hcows[i - 1], hcows[i]);
    }

    for (ll i = 1; i < H; i++) {
        for (ll j = 1; j <= G; j++) {
            dp[i][j].f = min(dp[i - 1][j].f + dist(hcows[i], hcows[i - 1]), 
                             dp[i - 1][j].s + dist(hcows[i], gcows[j]));
            dp[i][j].s = min(dp[i][j - 1].f + dist(hcows[i], gcows[j]), 
                             dp[i][j - 1].s + dist(gcows[j], gcows[j - 1]));
        }
    }

    /*for (ll i = 0; i <= H; i++) {
        for (ll j = 0; j <= G; j++) {
            cout << dp[i][j].f << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    for (ll i = 0; i <= H; i++) {
        for (ll j = 0; j <= G; j++) {
            cout << dp[i][j].s << " ";
        }
        cout << "\n";
    }*/

    return min(dp[H - 1][G].f + dist(hcows[H], hcows[H - 1]), 
               dp[H - 1][G].s + dist(hcows[H], gcows[G]));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "checklist";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> H >> G;

    for (ll i = 1; i <= H; i++) {
        cin >> hcows[i].f >> hcows[i].s;
    }

    for (ll i = 1; i <= G; i++) {
        cin >> gcows[i].f >> gcows[i].s;
    }

    cout << solve_dp() << "\n";
	
	return 0;
}