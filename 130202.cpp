#include <bits/stdc++.h>
#define MAX 100010
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> ppll;

ll N;
ppll paths[MAX];
bool invalid[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "crossings";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) { 
        ll a, b;
        cin >> a >> b;
        paths[i] = {{a, b}, i};
    }

    sort(paths, paths + N);

    ll maxab= -1e18;

    for (ll i = 0; i < N; i++) {
        if (paths[i].f.s < maxab) {
            invalid[paths[i].s] = true;
            //cout << i << "\n";
        }
        else {  
            maxab = paths[i].f.s;
        }
    }

    sort(paths, paths + N, [](auto& a, auto& b) {
        return a.f.s < b.f.s || (a.f.s == b.f.s && a.f.f < b.f.f);
    });

    maxab = -1e18;

    for (ll i = 0; i < N; i++) {
        if (paths[i].f.f < maxab) {
            invalid[paths[i].s] = true;
            //cout << i << "\n";
        }
        else {
            maxab = paths[i].f.f;
        }
    }

    ll ans = 0;
    for (ll i = 0; i < N; i++) {
        ans += !invalid[i];
    }

    cout << ans << endl;

    return 0;
}