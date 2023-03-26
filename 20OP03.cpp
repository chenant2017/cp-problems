#include <bits/stdc++.h>
#define MAX 100010
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N;
pll parts[MAX];
ll rmax[MAX];
ll lmin[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "moop";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;

        parts[i] = {x, y};
    }

    sort(parts, parts + N);

    rmax[N - 1] = parts[N - 1].s;

    for (ll i = N - 2; i >= 0; i--) {
        rmax[i] = max(rmax[i + 1], parts[i].s);
    }

    lmin[0] = parts[0].s;

    for (ll i = 1; i < N; i++) {
        lmin[i] = min(lmin[i - 1], parts[i].s);
    }

    ll ans = 1;

    for (ll i = 0; i < N - 1; i++) {
        if (lmin[i] > rmax[i + 1]) {
            ans++;
        }
    }

    cout << ans << "\n";
	
	return 0;
}