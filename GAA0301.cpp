#include <bits/stdc++.h>
#define MAXC 225
using namespace std;

typedef long long ll;
typedef tuple<ll, ll, ll> tll;

ll D, P, C, F, S;
vector<tll> edges;
ll profit[MAXC];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAA0301";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
    
    cin >> D >> P >> C >> F >> S;

    for (ll i = 0; i < P; i++) {
        ll a, b;
        cin >> a >> b;
        edges.push_back({a, b, D});
    }

    for (ll i = 0; i < F; i++) {
        ll a, b, t;
        cin >> a >> b >> t;
        edges.push_back({a, b, D-t});
    }

    for (ll i = 1; i <= C; i++) {
        profit[i] = -1e15;
    }

    profit[S] = 0;

    for (ll i = 0; i <= C; i++) {
        bool better = false;
        for (auto e: edges) {
            ll a, b, t;
            tie(a, b, t) = e;

            if (profit[a] + t > profit[b]) {
                better = true;
                //cout << b << " before " << profit[b] << "\n";
                profit[b] = profit[a] + t;
                //cout << "after " << profit[b] << "\n";
            }
        }

        if (!better) break;
        if (i == C && better) {
            cout << "-1\n";
            return 0;
        }
    }

    ll ans = 0;
    for (ll i = 1; i <= C; i++) {
        ans = max(ans, profit[i]);
    }
	
    cout << ans + D << "\n";
	
	return 0;
}