#include <bits/stdc++.h>
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

set<pll> active;
set<pll> to_add;

ll N;

ll dx[] = {0, 0, 0, -1, 1};
ll dy[] = {0, 1, -1, 0, 0};

pll is_comfy(ll x, ll y) {
    if (active.find({x, y}) == active.end() &&
        to_add.find({x, y}) == to_add.end()) {
        return {1e18, 1e18};
    }

    pll result;

    ll count = 0;
    for (ll d = 1; d < 5; d++) {
        ll x2 = x + dx[d];
        ll y2 = y + dy[d];
        if (active.find({x2, y2}) == active.end() &&
            to_add.find({x2, y2}) == to_add.end()) {
            result = {x2, y2};
        }
        else {
            count++;
        }
    }

    if (count == 3) return result;
    else return {1e18, 1e18};
}

void add(ll x, ll y, set<pll>& st) {
    st.insert({x, y});

    for (ll d = 0; d < 5; d++) {
        ll x2 = x + dx[d];
        ll y2 = y + dy[d];

        pll c = is_comfy(x2, y2);
        if (c != pll({1e18, 1e18})) {
            add(c.f, c.s, to_add);
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "210201";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);

    cin >> N;

    for (ll i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;

        if (to_add.find({x, y}) != to_add.end()) {
            to_add.erase({x, y});
            active.insert({x, y});
        }
        else {
            add(x, y, active);
        }

        cout<< to_add.size() << "\n";
    }
	
	return 0;
}