#include <bits/stdc++.h>
#define x first 
#define f first
#define s second
#define y second
#define MAXN 1010
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N, C;

struct Seg {
    pll p1, p2;

    Seg(pll a, pll b) {
        p1 = a;
        p2 = b;
    }
};

struct Poly {
    vector<Seg> segs;
    ll minx = 1e7, maxx = -1, miny = 1e7, maxy = -1;

    void add(Seg a) {
        segs.push_back(a);

        minx = min(minx, a.p1.x);
        minx = min(minx, a.p2.x);
        maxx = max(maxx, a.p1.x);
        maxx = max(maxx, a.p2.x);

        miny = min(miny, a.p1.y);
        miny = min(miny, a.p2.y);
        maxy = max(maxy, a.p1.y);
        maxy = max(maxy, a.p2.y);
    }
};

map<pll, ll> comp;
map<pll, vector<pll>> adj;
vector<vector<ll>> poly_adj;
vector<vector<ll>> poly_par; //parent
vector<ll> points_in;
vector<pll> pts;
vector<Poly> polys;
vector<bool> visited;

void get_comp(pll p, ll c) { // dfs
    if (comp[p] != -1) return;
    comp[p] = c;

    for (auto i: adj[p]) {
        get_comp(i, c);
    }
}

ll cp(pll a, pll b) {
    ll result = a.x * b.y - a.y * b.x;
    if (result > 0) {
        return 1;
    }
    else if (result == 0) {
        return 0;
    }
    else {
        return -1;
    }
}

pll diff(pll a, pll b) {
    return {a.x - b.x, a.y - b.y};
}

bool intersect(Seg a, Seg b) {
    pll v1 = diff(a.p2, a.p1);
    pll v2 = diff(b.p1, a.p1);
    pll v3 = diff(b.p2, a.p1);

    bool cond = (cp(v1, v2) * cp(v1, v3) <= 0);

    v1 = diff(b.p1, b.p2);
    v2 = diff(a.p1, b.p1);
    v3 = diff(a.p2, b.p1);

    cond = cond && (cp(v1, v2) * cp(v1, v3) <= 0);

    return cond;
}

bool pip(pll a, Poly p) {
    set<ll> xs;

    ll count = 0;

    Seg line = {a, {1e7, a.y}};

    for (auto i: p.segs) {
        if (intersect(line, i)) {
            if (i.p1.y == a.y) {
                if (xs.find(i.p1.x) == xs.end()) {
                    xs.insert(i.p1.x);
                    count++;
                }
            } 
            else if(i.p2.s == a.y) {
                if (xs.find(i.p2.x) == xs.end()) {
                    xs.insert(i.p2.x);
                    count++;
                }
            }
            else {
                count++;
            }
        }
    }
    
    return (count % 2 == 1);
}

bool contains(Poly a, Poly b) {
    return a.minx < b.minx && a.maxx > b.maxx &&
            a.miny < b.miny && a.maxy > b.maxy;
}

void get_points_in(ll i) {
    if (visited[i]) return;
    visited[i] = true;

    ll result = 0;

    for (auto p: pts) {
        if (pip(p, polys[i])) {
            result++;
        }
    }

    for (auto j: poly_adj[i]) {
        if (poly_par[j].size() == 1) {
            get_points_in(j);
            result -= points_in[j];
        }
    }

    points_in[i] = result;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAA1101";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> C;

    for (ll i = 0; i < N; i++) {
        pll p1, p2;
        cin >> p1.x >> p1.y;
        cin >> p2.x >> p2.y;

        if (p1 > p2) swap(p1, p2);

        adj[p1].push_back(p2);

        comp[p1] = -1;
        comp[p2] = -1;
    }

    ll comps = 0;

    for (auto i: adj) {
        if (comp[i.f] == -1) {
            get_comp(i.f, comps);
            comps++;
        }
    }

    polys.resize(comps);
    poly_adj.resize(comps);
    poly_par.resize(comps);
    visited.resize(comps);
    points_in.resize(comps);

    for (auto i: adj) {
        for (auto j: i.s) {
            polys[comp[i.f]].add(Seg(i.f, j));
        }
    }

    for (ll i = 0; i < comps; i++) {
        for (ll j = 0; j < comps; j++) {
            if (contains(polys[i], polys[j])) {
                poly_adj[i].push_back(j);
                poly_par[j].push_back(i);
            }
        }
    }

    pts.resize(C);

    for (ll i = 0; i < C; i++) {
        cin >> pts[i].x >> pts[i].y;
    }

    ll total = 0;
    ll ans = 0;

    for (ll i = 0; i < comps; i++) {
        get_points_in(i);
        ans = max(ans, points_in[i]);
        total += points_in[i];
    }

    ans = max(ans, C - total);

    cout << ans << "\n";
	
	return 0;
}