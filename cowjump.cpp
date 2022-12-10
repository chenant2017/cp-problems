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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "cowjump";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
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

    ll ans;

    for (ll i = N - 1; i >= 0; i--) {
        ll intersects = 0;
        for (ll j = 0; j < N; j++) {
            if (i == j) continue;
            if (intersect(segs[i], segs[j])) {
                intersects++;
            }
        }
        if (intersects >= 2) {
            cout << i + 1 << "\n";
            return 0;
        }
        if (intersects == 1) {
            ans = i + 1;
        }
    }

    cout << ans << "\n";

    /*sort(segs, segs + N, [](auto& a, auto& b)) {
        return a.p1 < b.p1;
    }

    for (ll i = 0; i < N; i++) {
        Point p;
        p.x = segs[i].p1.f;
        p.y = segs[i].p1.s;
        p.se = 1;
        points.push_back(p);
        p.x = segs[i].p2.f;
        p.y = segs[i].p2.s;
        p.se = 0;
        points.push_back(p);
    }

    sort(points.begin(), points.end());

    set<ll> active; 
    for (auto points.)*/
	
	return 0;
}