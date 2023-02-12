#include <bits/stdc++.h>
#define MAXN 255
#define f first 
#define s second
using namespace std;

typedef long long ll;

ll N, W, T;
vector<ll> pdp;
vector<ll> cdp;
vector<ll> minw;

typedef pair<ll, ll> pll;

pll cows[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAB0204";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
    cin >> N >> W;

    T = N * 1000 + 5;
    pdp.resize(T);
    cdp.resize(T);
    minw.resize(T);
	
    for (ll i = 0; i < N; i++) {
        cin >> cows[i].f >> cows[i].s;
    }

    for (ll i = 0; i < T; i++) {
        pdp[i] = 1e18;
        minw[i] = 1e18;
    }
    pdp[0] = 0;
    pdp[cows[0].s] = cows[0].f;
    if (cows[0].f >= W) minw[cows[0].s] = cows[0].f;

    for (ll i = 1; i < N; i++) {

        for (ll t = 0; t < T; t++) {
            cdp[t] = pdp[t];
            if (cdp[t] >= W) {
                minw[t] = min(minw[t], cdp[t]);
            }
            if (t - cows[i].s >= 0) {
                ll add = pdp[t - cows[i].s] + cows[i].f;

                cdp[t] = min(cdp[t], add);
                if (add >= W) {
                    minw[t] = min(minw[t], add);
                }
            }
        }

        pdp = cdp;
    }

    double ans = 0;

    for (ll t = 0; t < T; t++) {
        //cout << t << " " << cdp[t] << "\n";
        ans = max(ans, ((double) t) / minw[t]);
    }

    ans *= 1000;

    cout << floor(ans) << "\n";
	
	return 0;
}