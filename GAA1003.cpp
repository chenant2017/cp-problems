#include <bits/stdc++.h>
#define MAXN 210
#define x first 
#define y second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N;
pll pts[MAXN];
vector<double> v;
multiset<vector<double>> subs;
vector<double> cw;
vector<double> ccw;

double dist(pll a, pll b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double angle(pll a, pll b, pll c) {
    pll u = {a.x - b.x, a.y - b.y};
    pll v = {c.x - b.x, c.y - b.y};

    double dot = u.x * v.x + u.y * v.y;
    double umag = dist(a, b);
    double vmag = dist(b, c);

    return acos(dot / (umag * vmag));
}

void get_subs() {
    for (ll i = 0; i < v.size(); i++) {
        for (ll j = i; j < v.size(); j++) {
            vector<double> s;
            for (ll k = i; k <= j; k++) {
                s.push_back(v[k]);
            }
            subs.insert(s);
        }
    }
}

void get_ccw() {
    ccw.resize(v.size());

    ccw[0] = v[0];
    
    for (ll i = 1; i < v.size(); i++) {
        ccw[i] = ccw[i - 1];
        if (v[i] > 0) {
            ccw[i] += v[i];
        }
    }
}

void get_cw() {
    cw.resize(v.size());

    cw[v.size() - 1] = 0;

    for (ll i = v.size() - 2; i >= 0; i--) {
        cw[i] = cw[i + 1];
        if (v[i] > 0) {
            cw[i] += v[i];
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAA1003";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) {
        cin >> pts[i].x >> pts[i].y;
    }

    for (ll i = 0; i < N; i++) {
        double d = dist(pts[i], pts[(i + 1) % N]);
        double a = -1 * angle(pts[i], pts[(i + 1) % N], pts[(i + 2) % N]);
        if (i == N - 1) {
            a = -10;
        }
        v.push_back(d);
        v.push_back(a);
    }

    get_subs();
    get_ccw();
    get_cw();

    double ans = 0;

    for (ll i = 1; i < v.size(); i += 2) {
        vector<double> t;

        double orig = min(cw[i], ccw[i]);

        double dist2 = 0;

        ll j = i;

        for (; j < v.size(); j += 2) {
            t.push_back(v[j]);
            if (subs.count(t) == 1) {
                break;
            }
            t.push_back(v[j + 1]);
            dist2 += v[j + 1];
        }

        dist2 += min(cw[j], ccw[j]);

        ans = max(ans, dist2 - orig);
    }

    cout << ans << "\n";
	
	return 0;
}