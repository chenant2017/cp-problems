#include <bits/stdc++.h>
#define MAX 510
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll M, N, T;
ll elev[MAX][MAX];
ll ans[MAX][MAX];
pll parent[MAX][MAX];
ll sizes[MAX][MAX];

struct Edge {
    pll p, q;
    ll w;

    Edge(pll p_, pll q_) {
        p = p_;
        q = q_;
        w = abs(elev[p.f][p.s] - elev[q.f][q.s]);
    }

    bool operator<(const Edge& e) {
        if (w < e.w) return true;
        if (w == e.w) {
            if (p < e.p) return true;
            if (p == e.p) {
                if (q < e.q) return true;
            }
        }
        return false;
    }
};
vector<Edge> edges;

pair<pll, ll> rep(pll p) {
    pll& q = parent[p.f][p.s];

    if (q == p) {
        return {p, ans[p.f][p.s]};
    }

    auto r = rep(q);

    if (ans[p.f][p.s] == -1) {
        q = r.f;
        ans[p.f][p.s] = r.s;
        return r;
    }
    else {
        q = r.f;
        return {r.f, ans[p.f][p.s]};
    }
}

void merge(pll p, pll q, ll w) {
    p = rep(p).f;
    q = rep(q).f;

    //cout << ans[p.f][p.s] << "\n";

    if (sizes[p.f][p.s] < sizes[q.f][q.s]) swap(p, q);
    sizes[p.f][p.s] += sizes[q.f][q.s];
    if (sizes[p.f][p.s] >= T) {
        if (ans[p.f][p.s] == -1) ans[p.f][p.s] = w;
        if (ans[q.f][q.s] == -1) ans[q.f][q.s] = w;
    }
    parent[q.f][q.s] = p;
}

bool same(pll p, pll q) {
    return rep(p).f == rep(q).f;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "skilevel";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> M >> N >> T;

    for (ll i = 0; i < M; i++) {
        for (ll j = 0; j < N; j++) {
            cin >> elev[i][j];
            ans[i][j] = -1;
        }
    }

    for (ll i = 0; i < M; i++) {
        for (ll j = 0; j < N; j++) {
            if (j + 1 < N) {
                Edge e = Edge({i, j}, {i, j + 1});
                edges.push_back(e);
            }
            if (i + 1 < M) {
                Edge e = Edge({i, j}, {i + 1, j});
                edges.push_back(e);
            }
        }
    }

    sort(edges.begin(), edges.end());

    for (ll i = 0; i < M; i++) {
        for (ll j = 0; j < N; j++) {
            sizes[i][j] = 1;
            parent[i][j] = {i, j};
        }
    }

    for (auto i: edges) {
        //cout << i.w << " " << i.p.f << " " << i.p.s << " " << i.q.f << " " << i.q.s << "\n";
        if (!same(i.p, i.q)) {
            merge(i.p, i.q, i.w);
        }
    }   

    ll total = 0;

    /*for (ll i = 0; i < M; i++) {
        for (ll j = 0; j < N; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }*/

    for (ll i = 0; i < M; i++) {
        for (ll j = 0; j < N; j++) {
            bool b;
            cin >> b;
            rep({i, j});
            if (b) total += ans[i][j];
        }
    }

    cout << total << "\n";
	
	return 0;
}