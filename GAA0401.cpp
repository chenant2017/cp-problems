#include <bits/stdc++.h>
#define x first 
#define y second
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> ppll;

ll N, xl, yl, xb, yb;

auto cmpy = [](const pll& a, const pll& b) {
    return a.y < b.y || (a.y == b.y && a.x < b.y);
};

set<pll> uvx;
set<pll, decltype(cmpy)> uvy(cmpy);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAA0401";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> xl >> yl >> xb >> yb;

    uvx.insert({xl, yl});
    uvy.insert({xl, yl});
    uvx.insert({xb, yb});
    uvy.insert({xb, yb});

    for (ll i = 0; i < N; i++) {
        ll x_, y_;
        cin >> x_ >> y_;
        uvx.insert({x_, y_});
        uvy.insert({x_, y_});
    }

    ll ans = -1;

    queue<ppll> q;
    q.push({{xl, yl}, 0});
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        if (uvx.find(curr.f) == uvx.end()) {
            continue;
        }

        uvx.erase(curr.f);
        uvy.erase(curr.f);

        if (curr.f == pll({xb, yb})) {
            ans = curr.s - 1;
            break;
        }  

        auto xit1 = uvx.lower_bound({curr.f.x, -1});
        auto xit2 = uvx.upper_bound({curr.f.x, 1e10});
        auto yit1 = uvy.lower_bound({-1, curr.f.y});
        auto yit2 = uvy.upper_bound({1e10, curr.f.y});

        for (auto it = xit1; it != xit2; it++) {
            q.push({*it, curr.s + 1});
        }
        for (auto it = yit1; it != yit2; it++) {
            q.push({*it, curr.s + 1});
        }
    }

    cout << ans << "\n";
	
	return 0;
}