#include <bits/stdc++.h>
#define MAX 1010
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

struct Seg {
	pll p1, p2;
	Seg(pll a, pll b) {
		p1 = a;
		p2 = b;
		if (p1 > p2) swap(p1, p2);
	}

	bool operator<(const Seg& se) const {
		return pair<pll, pll>({p1, p2}) < pair<pll, pll>({se.p1, se.p2});
	}
};

ll N, C;
map<pll, vector<pll>> adj;
map<pll, ll> comp;
set<Seg> polys [MAX];
map<vector<ll>, ll> ans;

void get_comps(pll p, ll c) {
	if (comp[p] != 0) return;
	comp[p] = c;
	for (auto i: adj[p]) {
		polys[c].insert(Seg(p, i));
		if (comp[i] == 0) {
			get_comps(i, c);
		}	
	}
}

ll cp(pll a, pll b) {
	return a.f * b.s - b.f * a.s;
}

pll diff(pll a, pll b) {
	return {a.f - b.f, a.s - b.s};
}

bool intersect(Seg a, Seg b) {
	pll v1, v2, v3;
	v1 = diff(a.p2, a.p1);
	v2 = diff(b.p1, a.p1);
	v3 = diff(b.p2, a.p1);

	bool b1 = cp(v1, v2) * cp(v1, v3) < 0;

	v1 = diff(b.p2, b.p1);
	v2 = diff(a.p1, b.p1);
	v3 = diff(a.p2, b.p1);

	bool b2 = cp(v1, v2) * cp(v1, v3) < 0;

	return b1 && b2;
}

bool pip(pll p, ll po) {
	ll count = 0;
	Seg ray = Seg(p, {p.f + 1, p.s + 1e7});
	for (auto i: polys[po]) {
		if (intersect(ray, i)) {
			count++;
		}
	}

	return count % 2 == 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAA1101";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
    cin >> N >> C;

    for (ll i = 0; i < N; i++) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
		adj[{x1, y1}].push_back({x2, y2});
		adj[{x2, y2}].push_back({x1, y1});
    }

	ll c = 0;
	for (auto i: adj) {
		if (comp[i.f] == 0) {
			c++;
			get_comps(i.f, c);
		}
	}

	for (ll i = 0; i < C; i++) {
		pll p;
		cin >> p.f >> p.s;

		vector<ll> v;
		for (ll j = 1; j <= c; j++) {
			if (pip(p, j)) {
				v.push_back(j);
			}
		}

		ans[v]++;
	}

	ll max_count = 0;

	for (auto i: ans) {
		//for (auto j: i.f) cout << j << " ";
		//cout << "   " << i.s << "\n";
		max_count = max(max_count, i.s);
	}

	cout << max_count << "\n";
	
	return 0;
}