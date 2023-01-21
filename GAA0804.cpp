#include <bits/stdc++.h>
#define MAXN 1010
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

struct Rect {
    ll x1, x2, y1, y2;
    Rect(pll ul, pll lr) {
        tie(x1, y2) = ul;
        tie(x2, y1) = lr;
    }
    Rect() {
        Rect({0, 0}, {0, 0});
    }
};

ll N;
Rect rects[MAXN];
vector<pll> xs;
set<ll> ax;
set<pll> ys;

ll area(ll i) {
    ll height = 0;
    set<ll> ay;

    ll prev = ys.begin()->f;
    for (auto j: ys) {
        if (!ay.empty()) {
            height += j.f - prev;
        }
        if (ay.find(j.s) == ay.end()) {
            ay.insert(j.s);
        }
        else {
            ay.erase(j.s);
        }
        prev = j.f;
    }

    return height * (xs[i + 1].f - xs[i].f);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAA0804";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) {
        pll ul, lr;
        cin >> ul.f >> ul.s >> lr.f >> lr.s;

        rects[i] = Rect(ul, lr);
    }

    sort(rects, rects + N, [](auto& a, auto& b) {
        return a.x1 < b.x1 || (a.x1 == b.x1 && a.y1 < b.y1);
    });

    for (ll i = 0; i < N; i++) {
        xs.push_back({rects[i].x1, i});
        xs.push_back({rects[i].x2, i});
    }

    sort(xs.begin(), xs.end());

    ll ans = 0;

    for (ll i = 0; i < xs.size() - 1; i++) {
        if (ax.find(xs[i].s) == ax.end()) {
            ax.insert(xs[i].s);
            ys.insert({rects[xs[i].s].y1, xs[i].s});
            ys.insert({rects[xs[i].s].y2, xs[i].s});
        }   
        else {
            ax.erase(xs[i].s);
            ys.erase({rects[xs[i].s].y1, xs[i].s});
            ys.erase({rects[xs[i].s].y2, xs[i].s});
        }

        ans += area(i);
    }
    
    cout << ans << "\n";

	return 0;
}