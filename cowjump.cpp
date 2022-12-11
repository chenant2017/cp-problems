#include <bits/stdc++.h>
#define MAXN 100010
#define f first 
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

struct Segment {
    pll p1, p2;
};

struct Point {
    ll x, y, se, i;
    bool operator<(const Point& p) {
        return tuple<ll, ll, ll, ll>({x, y, se, i}) < tuple<ll, ll, ll, ll>({p.x, p.y, p.se, p.i});
    } 
};

ll N;
ll x;
ll ans;
ll END = 0;
ll START = 1;
Segment segs[MAXN];
vector<Point> points;

ll xp(pll a, pll b) {
    return a.f * b.s - a.s * b.f;
}

pll diff(pll a, pll b) {
    return pll({a.f - b.f, a.s - b.s});
}

bool diff_side(Segment a, Segment b) {
    if (xp(diff(a.p1, b.p1), diff(a.p1, b.p2)) > 0 
        != xp(diff(a.p2, b.p1), diff(a.p2, b.p2)) > 0) {
        return true;
    }
    if (xp(diff(a.p1, b.p1), diff(a.p1, b.p2)) * 
        xp(diff(a.p2, b.p1), diff(a.p2, b.p2)) == 0) {
        return true;
    }
    return false;
}

bool intersect(Segment a, Segment b) {
    return (diff_side(a, b) && diff_side(b, a));
}

double y(Segment a) {
    if (a.p2.f == a.p1.f) return a.p1.s; //for vertical line
    double m = (double)(a.p2.s - a.p1.s) / (a.p2.f - a.p1.f);
    return (double) a.p1.s + (x - a.p1.f) * m;

}

auto seg_cmp = [](const ll& a, const ll& b) {
    return y(segs[a]) < y(segs[b]);
};

void update(ll& ans1, ll& ans2, ll a, ll b) {
    if (ans1 == -1) {
        ans1 = a;
        ans2 = b;
    }
    else {
        if (a == ans1 && b == ans2) return;
        if (ans1 == ans2) return;
        if (a == ans1 || a == ans2) {
            ans1 = a;
            ans2 = a;
        }
        if (b == ans1 || b == ans2) {
            ans1 = b;
            ans2 = b;
        }
    }
}

int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	
	string fname = "cowjump";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N; 

    for (ll i = 0; i < N; i++) {
        Segment s;
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        s.p1 = pll({x1, y1});
        s.p2 = pll({x2, y2});

        if (s.p1 > s.p2) swap(s.p1, s.p2);

        segs[i] = s;
    }

    for (ll i = 0; i < N; i++) {
        Point p;
        p.i = i;

        p.x = segs[i].p1.f;
        p.y = segs[i].p1.s;
        p.se = START;
        points.push_back(p);

        p.x = segs[i].p2.f;
        p.y = segs[i].p2.s;
        p.se = END;
        points.push_back(p);
    }

    sort(points.begin(), points.end());

    x = 0;

    set<ll, decltype(seg_cmp)> active (seg_cmp); 

    ll ans1 = -1, ans2 = 0;

    cout << points.size() << "\n";

    for (auto p: points) {
        if (p.se == START) {
            x = p.x;
            active.insert(p.i);
            auto it = active.find(p.i);
            cout << *it << " a\n";
            auto it2 = it;
            it2++;
            if (it2 != active.end() && intersect(segs[*it], segs[*it2])) {
                update(ans1, ans2, min(*it, *it2), max(*it, *it2));

            }

            it2 = it;
            it2--;
            if (it != active.begin() && intersect(segs[*it], segs[*it2])) {
                update(ans1, ans2, min(*it, *it2), max(*it, *it2));
            }
        }
        else {
            bool found = false;
            auto it = active.begin();
            for (; it != active.end(); it++) {
                if (*it == p.i) {
                    cout << "found\n";
                    found = true;
                    break;
                }
            }
            assert(found);
            cout << *it << " b\n";
            auto it2 = it;
            auto it3 = it; 
            it2++;
            it3--;

            cout << "mxvbc\n";

            if (it2 != active.end() && it != active.begin() && intersect(segs[*it2], segs[*it3])) {
                cout << "fdas\n";
                update(ans1, ans2, min(*it3, *it2), max(*it3, *it2));
                update(ans1, ans2, min(*it3, *it2), max(*it3, *it2));
            } 
            cout << "adsf\n";
            active.erase(p.i);
        }
        cout << "weruio\n";
    }

    cout << min(ans1, ans2) + 1 << "\n";
	
	return 0;
}