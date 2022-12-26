#include <bits/stdc++.h>
#define x first
#define y second
#define MAXN 100010
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> ppll;

struct Segment {
    pll p1, p2;
};

ll N;
ll currx;
Segment segs[MAXN];
vector<ppll> endpoints;
pll ans = {-1, -1};


ll sign(ll a) {
    if (a > 0) return 1;
    else if (a == 0) return 0;
    return -1;
}

ll cp(pll a, pll b) {
    return a.x * b.y - a.y * b.x;
}

pll diff(pll a, pll b) {
    return {a.x - b.x, a.y - b.y};
}

bool intersect(Segment s1, Segment s2) {
    ll cp1 = cp(diff(s1.p1, s2.p1), diff(s1.p2, s2.p1));
    ll cp2 = cp(diff(s1.p1, s2.p2), diff(s1.p2, s2.p2));
    
    ll cp3 = cp(diff(s2.p1, s1.p1), diff(s2.p2, s1.p1));
    ll cp4 = cp(diff(s2.p1, s1.p2), diff(s2.p2, s1.p2));

    return (sign(cp1) * sign(cp2) <= 0 && sign(cp3) * sign(cp4) <= 0);
}

double gety(Segment s) {
    if (s.p2.x == s.p1.x) return s.p2.y;
    double m = (double) (s.p2.y - s.p1.y) / (s.p2.x - s.p1.x);
    return s.p1.y + m * (currx - s.p1.x);
}

bool cmp(const ll& a, const ll& b) {
    return gety(segs[a]) < gety(segs[b]);
}

bool update_ans(ll a, ll b) {
    if (ans.first == -1) {
        ans = {a, b};
        return false;
    }
    
    else {
        if (a == ans.first || a == ans.second) {
            if (b == ans.first || b == ans.second) {
                return false;
            }
            cout << a + 1 << "\n";
            return true;
        }
        else {
            cout << b + 1 << "\n";
            return true;
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "cowjump";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) {
        Segment& seg = segs[i];
        cin >> seg.p1.x >> seg.p1.y >> seg.p2.x >> seg.p2.y;
        if (seg.p1 > seg.p2) {
            swap(seg.p1, seg.p2);
        }
    }

    for (ll i = 0; i < N; i++) {

    }

    for (ll i = 0; i < N; i++) {
        ppll start = {segs[i].p1, i};
        ppll end = {segs[i].p2, i};

        endpoints.push_back(start);
        endpoints.push_back(end);
    }

    sort(endpoints.begin(), endpoints.end());

    set<ll, decltype(&cmp)> active(cmp);

    
    for (auto e: endpoints) {
        if (active.find(e.second) == active.end()) {

            active.insert(e.second);
            auto it = active.find(e.second);

            auto it2 = it;
            it2++;
            if (it2 != active.end()) {
                if (intersect(segs[*it], segs[*it2])) {
                    if (update_ans(*it, *it2)) {
                        return 0;
                    }
                }
            }

            if (it != active.begin()) {
                it2 = it;
                it2--;
                if (intersect(segs[*it], segs[*it2])) {
                    if (update_ans(*it, *it2)) {
                        return 0;
                    }
                }
            }

        }
        else {

            auto it = active.find(e.second);
            auto it2 = it;
            auto it3 = it;

            it2++;
            it3--;

            if (it2 != active.end() && it != active.begin()) {
                if (intersect(segs[*it2], segs[*it3])) {
                    if (update_ans(*it2, *it3)) {
                        return 0;
                    }
                }
            }

        }
    }

    cout << min(ans.first, ans.second) + 1 << "\n";

	return 0;
}