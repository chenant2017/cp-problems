#include <bits/stdc++.h>
#define f first 
#define s second
#define MAXN 45
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef map<pll, map<ll, ll>> mpl;

ll N, xg, yg;
mpl counts1;
mpl counts2;
vector<pll> steps1;
vector<pll> steps2;
ll ans[MAXN];

void get_counts(mpl& counts, vector<pll>& steps, ll i) {
    if (i == 0) {
        counts[steps[0]][1]++;
        return;
    }

    vector<tuple<pll, ll, ll>> add;

    for (auto c: counts) {
        pll p1 = c.f;
        pll p2 = {p1.f + steps[i].f, p1.s + steps[i].s};
        
        for (auto d: c.s) {
            add.push_back({p2, d.f + 1, d.s});
        }
    }

    for (auto a: add) {
        pll p;
        ll q, r;
        tie(p, q, r) = a;
        counts[p][q] += r;
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "220202";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    cin >> xg >> yg;

    counts1[{0, 0}][0] = 1;
    counts2[{0, 0}][0] = 1;


    for (ll i = 0; i < N / 2; i++) {
        ll x, y;
        cin >> x >> y;
        steps1.push_back({x, y});
    }

    for (ll i = 0; i < N / 2; i++) {
        get_counts(counts1, steps1, i);
    }

    for (ll i = 0; i < N - N / 2; i++) {
        ll x, y;
        cin >> x >> y;
        steps2.push_back({x, y});
    }

    for (ll i = 0; i < N - N / 2; i++) {
        get_counts(counts2, steps2, i);
    }

    for (auto i: counts1) {
        pll p1 = i.f;
        pll p2 = {xg - i.f.f, yg - i.f.s};

        for (auto j: counts2[p2]) {
            for (auto k: counts1[p1]) {
                ans[j.f + k.f] += j.s * k.s;
            }
        }
    }

    for (ll i = 1; i <= N; i++) {
        cout << ans[i] << "\n";
    }
	
	return 0;
}