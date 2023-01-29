#include <bits/stdc++.h>
#define MAX 100010
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N;
pll ranges[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "mountains";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;
        ranges[i].f = x - y;
        ranges[i].s = x + y;
    }

    sort(ranges, ranges + N);

    ll mst = -1e18;
    ll med = -1e18;

    ll ans = 0;

    for (ll i = 0; i < N; i++) {
        ll st, ed;
        tie(st, ed) = ranges[i];

        if (ed > med) {
            if (st > mst) {
                ans++;
            }
            med = ed;
            mst = st;
        }
    }

    cout << ans << "\n";
	
	return 0;
}