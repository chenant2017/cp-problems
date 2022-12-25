#include <bits/stdc++.h>
#define x first
#define y second
#define MAXN 100010
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

struct Segment {
    pll p1, p2;
};

ll N;
Segment segs[MAXN];

ll sign(ll a) {
    if (a > 0) return 1;
    else if (a == 0) return 0;
    return -1;
}

ll cp(pll a, pll b) {
    return a.x * b.y - a.y * b.x;
}

pll diff(pll a, pll b) {
    return pll({a.x - b.x, a.y - b.y});
}

bool intersect(Segment s1, Segment s2) {
    ll cp1 = cp(diff(s1.p1, s2.p1), diff(s1.p2, s2.p1));
    ll cp2 = cp(diff(s1.p1, s2.p2), diff(s1.p2, s2.p2));
    
    ll cp3 = cp(diff(s2.p1, s1.p1), diff(s2.p2, s1.p1));
    ll cp4 = cp(diff(s2.p1, s1.p2), diff(s2.p2, s1.p2));

    return (sign(cp1) * sign(cp2) <= 0 && sign(cp3) * sign(cp4) <= 0);
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

    ll ans = -1;

    for (ll i = 0; i < N; i++) {
        
        ll intersects = 0;
        for (ll j = 0; j < N; j++) {
            if (i == j) continue;
            if (intersect(segs[i], segs[j])) {
                intersects++;
            }
        }

        if (intersects > 1) {
            cout << i + 1 << "\n";
            return 0;
        }
        else if (intersects == 1) {
            if (ans == -1) ans = i + 1;
        }
    }

    cout << ans << "\n";

	return 0;
}