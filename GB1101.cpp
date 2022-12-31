#include <bits/stdc++.h>
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N;
vector<pll> points;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GB1101";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) {
        ll a, b;
        cin >> a >> b;

        points.push_back(pll({a, i}));
        points.push_back(pll({b, i}));
    }

    sort(points.begin(), points.end());

    ll ans = 0;
    set<ll> active;

    ll ptr = 0;
    while (ptr < 2 * N) {
        vector<ll> to_remove;


        if (active.find(points[ptr].s) == active.end()) {
            active.insert(points[ptr].s);
        }
        else {
            to_remove.push_back(points[ptr].s);
        }

        while (ptr + 1 < 2 * N && points[ptr + 1].f == points[ptr].f) {
            ptr++;
            if (active.find(points[ptr].s) == active.end()) {
                active.insert(points[ptr].s);
            }
            else {
                to_remove.push_back(points[ptr].s);
            }
        }

        
        ans = max(ans, (ll) active.size());

        for (auto i: to_remove) {
            active.erase(i);
        }

        ptr++;
    }
	
    cout << ans << "\n";

	return 0;
}