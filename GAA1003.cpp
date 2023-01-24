#include <bits/stdc++.h>
#define MAXN 
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

double dist(pll a, pll b) {
    return sqrt(pow(a.f - b.f, 2) + pow(a.s - b.s, 2));
}

double dot(pll a, pll b, pll c) {
    pll p = {b.f - a.f, b.s - a.s};
    pll q = {c.f - b.f, c.s - b.s};

    return p.f * q.f + p.s * q.s;
}

struct Vt {
    ll x, y, de;
    double dr, dl;
    double angle;

    Vt(ll i) {
        pll pl = pts[(i - 1 + N) % N];
        pll pr = pts[(i + 1 + N) % N];

        dl = dist(pl, pts[i]);
        dr = dist(pr, pts[i]); 

        de = (0 - i + N) % N;
        
        angle = dot(pl, pts[i], pr);
        tie(x, y) = pts[i];
    }
};

ll N;
pll pts[MAXN];
Vt vertices[MAXN];
set<Vt> vts;


ll moves(ll i) {0
    ll j = i;

    ll min_de = 0;
    
    double dl = -1;

    while (true) {
        double angle = vertices[j].angle;

        set<Vt> vts2 = vts;
        vector<Vt> rm;
        for (auto v: vts2) {
            if (v.de < min_de || v.angle != angle) {
                rm.push_back(v);
            }
        }
        for (auto v: rm) {
            vts2.erase(v);
        }

        if (vts2.size() == 1) {
            return (j - i); 
        }

        j = (j + 1) % N;
    }
    return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAA1003";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) {
        cin >> pts[i].f >> pts[i].s;
    }

    for (ll i = 0; i < N; i++) {
        Vt vt = Vt(i);
        vts.insert(vt);
        vertices[i] = vt;
    }

    for (ll i = 0; i < N; i++) {
        ll mv = moves(i);

    }
	
	return 0;
}