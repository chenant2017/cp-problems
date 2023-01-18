#include <bits/stdc++.h>
#define MAX 1010
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
struct Rect {
    ll x1, y1, x2, y2;
    
    Rect(ll p, ll q, ll r, ll s) {
        x1 = p;
        y1 = q;
        x2 = r;
        y2 = s;
    }

    Rect() {
        Rect(0, 0, 0, 0);
    }
};

ll X, Y, I;
Rect rects[MAX];
vector<pll> xs;
set<pll> ys;
set<ll> activex;

ll area(ll i) {
    set<ll> activey;

    ll height = 0;

    ll start = ys.begin()->first;

    for (auto k: ys) {
        ll y, j;
        tie(y, j) = k;
 
        if (activey.find(j) == activey.end()) {
            //cout << "push " << y << "\n";
            if (activey.empty()) {
                start = y;
            }
            activey.insert(j);
        }
        else {
            //cout << "erase " << y << "\n";
            activey.erase(j);
            if (activey.empty()) {
                height += y - start;
            }
        }
    }

    ll width = xs[i + 1].first - xs[i].first;

    //cout << height << " " << width << "\n";
    //cout << height << " " << width << " hw\n";
    return height * width;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAA0703";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> X >> Y >> I;

    for (ll i = 0; i < I; i++) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;
        y1--;
        xs.push_back({x1, i});
        xs.push_back({x2, i});
        rects[i] = Rect(x1, y1, x2, y2);
    }

    sort(xs.begin(), xs.end());

    ll ans = 0;

    for (ll i = 0; i < xs.size() - 1; i++) {
        ll x, j;
        tie(x, j) = xs[i];
        //cout << x << " " << j << " xj\n";
        if (activex.find(j) == activex.end()) {
            activex.insert(j);
            ys.insert({rects[j].y1, j});
            ys.insert({rects[j].y2, j});
            ll a = area(i);
            //cout << xs[i].first << " " << a << "\n";
            ans += a;
        }
        else {
            activex.erase(j);
            ys.erase({rects[j].y1, j});
            ys.erase({rects[j].y2, j});
            ll a = area(i);
            ans += a;
        }
    }

    cout << ans << "\n";
	
	return 0;
}