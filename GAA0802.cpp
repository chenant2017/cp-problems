#include <bits/stdc++.h>
#define MAXN 50010
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N;
pll pts[MAXN];
ll xr[MAXN];
ll xl[MAXN];
ll yt[MAXN];
ll yb[MAXN];

void get_a(ll* a) {
    ll minx = 1e10;
    ll maxx = 0;
    ll miny = 1e10;
    ll maxy = 0;

    for (ll i = 0; i < N; i++) {
        minx = min(minx, pts[i].f);
        maxx = max(maxx, pts[i].f);
        miny = min(miny, pts[i].s);
        maxy = max(maxy, pts[i].s);
        a[i] = (maxx - minx) * (maxy - miny);
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAA0802";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) {
        cin >> pts[i].f >> pts[i].s;
    }

    sort(pts, pts + N);
    get_a(xl);
    reverse(pts, pts + N);
    get_a(xr);
    reverse(xr, xr + N);

    sort(pts, pts + N, [](auto& a, auto& b) {
        return a.s < b.s || (a.s == b.s && a.f < b.f);
    });
    get_a(yb);
    reverse(pts, pts + N);
    get_a(yt);
    reverse(yt, yt + N);

    ll ans = 2e18;

    for (ll i = 0; i < N - 1; i++) {
        ans = min(ans, xl[i] + xr[i + 1]);
        ans = min(ans, yb[i] + yt[i + 1]);
    }

    cout << xr[0] - ans << "\n";
	
	return 0;
}