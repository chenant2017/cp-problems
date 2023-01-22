#include <bits/stdc++.h>
#define MAX 510
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll M, N;
ll elevs[MAX][MAX];

struct Edge {
    ll d;
    pll p1, p2;

    Edge(pll a, pll b) {
        p1 = a;
        p2 = b;
        d = abs(elevs[p1.f][p1.s] - elevs[p2.f][p2.s]);
    }
    Edge() {
        p1 = {-1, -1};
        p2 = {-1, -1};
        d = -1;
    }
};

auto ecmp = [](const Edge& a, const Edge& b) {
    if (a.d > b.d) return true;
    if (a.d == b.d) {
        if (a.p1 > b.p1) return true;
        if (a.p1 == b.p1) {
            if (a.p2 > b.p2) return true;
        }
    }
    return false;
};

vector<pll> wp;
priority_queue<Edge, vector<Edge>, decltype(ecmp)> edges(ecmp);
ll sizes[MAX][MAX];
pll parent[MAX][MAX];

pll get_rep(pll a) {
    pll c = a;
    while (parent[c.f][c.s] != c) {
        c = parent[c.f][c.s];
    }
    parent[a.f][a.s] = c;
    return c;
}

bool same(pll a, pll b) {
    return get_rep(a) == get_rep(b);
}

void merge(pll a, pll b) {
    a = get_rep(a);
    b = get_rep(b);

    if (sizes[a.f][a.s] < sizes[b.f][b.s]) {
        swap(a, b);
    }

    sizes[a.f][a.s] += sizes[b.f][b.s];
    parent[b.f][b.s] = a;
}   

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAA0902";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> M >> N;

    for (ll i = 0; i < M; i++) {
        for (ll j = 0; j < N; j++) {
            cin >> elevs[i][j];
        }
    }

    for (ll i = 0; i < M; i++) {
        for (ll j = 0; j < N; j++) {
            bool b; 
            cin >> b;
            if (b) {
                wp.push_back({i, j});
            }
        }
    }

    for (ll i = 0; i < M; i++) {
        for (ll j = 0; j < N; j++) {
            if (i < M - 1) {
                Edge e = Edge({i, j}, {i + 1, j});
                edges.push(e);
            }
            if (j < N - 1) {
                Edge e = Edge({i, j}, {i, j + 1});
                edges.push(e);
            }
        }
    }

    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            parent[i][j] = {i, j};
            sizes[i][j] = 1;
        }
    }

    ll ans;

    for (ll i = 0; i < wp.size() - 1; i++) {
        while (!same(wp[i], wp[i + 1])) {
            Edge e = edges.top();
            edges.pop();

            ans = e.d;

            merge(e.p1, e.p2);
        }
    }

    cout << ans << "\n";
	
	return 0;
}