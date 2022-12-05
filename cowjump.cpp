#include <bits/stdc++.h>
#define MAXN 100010
#define x first 
#define y second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N;

struct Segment {
    pll p1;
    pll p2;
};

Segment segs[MAXN];
vector<ll> intersects1;

pll diff(pll p1, pll p2) {
    return pll({p1.x - p2.x, p1.y - p2.y});
}

ll x_product(pll p1, pll p2) {
    return p1.x * p2.y - p1.y * p2.x;
}

bool intersect(Segment s1, Segment s2) {
    ll xp1 = x_product(diff(s2.p1, s1.p1), diff(s2.p1, s1.p2));
    ll xp2 = x_product(diff(s2.p2, s1.p1), diff(s2.p2, s1.p2));

    ll xp3 = x_product(diff(s1.p1, s2.p1), diff(s1.p1, s2.p2));
    ll xp4 = x_product(diff(s1.p2, s2.p1), diff(s1.p2, s2.p2));

    return (xp1 * xp2 <= 0 && xp3 * xp4 < 0) || (xp1 * xp2 < 0 && xp3 * xp4 <= 0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "cowjump";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) {
        cin >> segs[i].p1.x >> segs[i].p1.y
            >> segs[i].p2.x >> segs[i].p2.y;
        if (segs[i].p1 > segs[i].p2) swap(segs[i].p1, segs[i].p2); 
    }

    /*Segment s1, s2;
    s1.p1 = pll({0, 0});
    s1.p2 = pll({1, 1});
    s2.p1 = pll({2, 2});
    s2.p2 = pll({3, 3});

    if (intersect(s1, s2)) cout << "yes\n";

    return 0;*/

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
            intersects1.push_back(i);
        }
    }

    cout << intersects1[0] + 1 << "\n";
	
	return 0;
}