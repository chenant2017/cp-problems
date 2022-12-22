#include <bits/stdc++.h>
#define MAXN 100010
#define MAXL 1010
#define MAXB 1010
using namespace std;

typedef long long ll;

struct comp {
    ll s, e, f, c;
};

ll L, N, B;
ll dp[MAXL][MAXB] = {{0}}; //max fun at each L and B
comp comps[MAXN];

void solve_dp() {
    for (ll i = 0; i < N; i++) {
        comp& cp = comps[i];

        for (ll j = 0; j <= B; j++) {
            if (j + cp.c <= B) {
                dp[cp.e][j + cp.c] = max(dp[cp.e][j + cp.c], dp[cp.s][j] + cp.f);
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "coaster";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> L >> N >> B;

    for (ll i = 0; i < N; i++) {
        comp& cp = comps[i];
        
        ll x, w;
        cin >> x >> w >> cp.f >> cp.c;

        cp.s = x;
        cp.e = x + w;
    }

    sort(comps, comps + N, [](auto& a, auto& b) {
        return a.s < b.s || (a.s == b.s && a.e < b.e);
    });

    solve_dp();

    /*for (ll i = 0; i <= L; i++) {
        for (ll j = 0; j <= B; j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }*/

    cout << *max_element(dp[L], dp[L] + B + 1) << "\n";
	
	return 0;
}