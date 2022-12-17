#include <bits/stdc++.h>
#define f first  
#define s second 
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N;
vector<pll> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "mountains";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) {
        pll p;
        cin >> p.f >> p.s;
        v.push_back(p);
    }
    v.push_back(pll({-pow(10, 10), 0}));

    sort(v.begin(), v.end(), [](auto& a, auto& b) {
        return a.f - a.s < b.f - b.s;
    });

    ll ans = 0;
    ll prev = 0;

    for (ll i = 1; i <= N; i++) {
        ll yprev = v[prev].f + v[prev].s - v[i].f;
        ll xprev = v[prev].f - v[prev].s;
        //cout << v[i].f << " " << v[i].s << " " << xprev << " " << yprev << "\n";
        if (v[i].s > yprev) {
            if (v[i].f - v[i].s > xprev) {
                ans++;
            }
            prev = i;
        }
    }

    cout << ans << "\n";
	
	return 0;
}