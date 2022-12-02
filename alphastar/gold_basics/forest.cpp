#include <bits/stdc++.h>
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

ll N;
multiset<ll> active;
map<ll, pair<vll, vll>> add_rem;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "forest";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) {
        ll a, b, h;
        cin >> a >> b >> h;

        add_rem[a].f.push_back(h);
        add_rem[b].s.push_back(h);
    }

    ll ans = 0;

    auto i = add_rem.begin();
    auto j = add_rem.end();
    j--;

    for (; i != j; i++) {
        for (auto k: i->s.s) {
            active.erase(k);
        }
        for (auto k: i->s.f) {
            active.insert(k);
        }
        auto next = i;
        next++;
        if (!active.empty()) {
             ans += *active.rbegin() * ((next)->f - i->f);
        }
    }

    cout << ans << "\n";
	
	return 0;
}