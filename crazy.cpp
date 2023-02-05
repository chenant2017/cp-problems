#include <bits/stdc++.h>
#define MAX 510
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N, C;
set<ll> xs;
map<ll, ll> xc; //compressed
set<ll> ys;
map<ll, ll> yc;
ll field[4 * MAX][4 * MAX];
pll cows[MAX];
ll di[] = {0, 0, 1, -1};
ll dj[] = {1, -1, 0, 0};

struct Seg {
    pll p1, p2;

    Seg (ll x1, ll y1, ll x2, ll y2) {
        p1 = {x1, y1};
        p2 = {x2, y2};
        if (p1 > p2) {
            swap(p1, p2);
        }
    }
    Seg() {
        Seg(0, 0, 0, 0);
    }
};
Seg segs[MAX];

ll dfs(ll i, ll j) {
    ll result = 0;
    stack<pll> q;
    q.push({i, j});

    while (!q.empty()) {
        auto c = q.top(); q.pop();

        if (field[c.f][c.s] == 3) continue;

        if (field[c.f][c.s] == 2) {
            result++;
        }

        field[c.f][c.s] = 3;

        for (ll d = 0; d < 4; d++) {
            ll ni = c.f + di[d];
            ll nj = c.s + dj[d];

            if (0 <= ni && ni <= 2 * (N + C + 1) &&
                0 <= nj && nj <= 2 * (N + C + 1)) {
                if (field[ni][nj] == 0 || field[ni][nj] == 2) {
                    q.push({ni, nj});
                }
            }
        }
    }
    return result;
}


int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	
	string fname = "crazy";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
    cin >> N >> C;

    for (ll i = 0; i < N; i++) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        xs.insert(x1); xs.insert(x2);
        ys.insert(y1); ys.insert(y2);
        Seg s = Seg(x1, y1, x2, y2);
        segs[i] = s;
    }

    for (ll i = 0; i < C; i++) {
        ll x, y;
        cin >> x >> y;
        xs.insert(x); ys.insert(y);
        cows[i] = {x, y};
    }
	
    ll i = 1;
    for (auto it = xs.begin(); it != xs.end(); it++) {
        xc[*it] = i;
        //cout << *it << " " << i << "\n";
        i += 2;
    }

    i = 1;
    for (auto it = ys.begin(); it != ys.end(); it++) {
        yc[*it] = i;
        //cout << *it << " " << i << "\n";
        i += 2;
    }

    for (ll i = 0; i < N; i++) {
        Seg s = segs[i];
        for (ll k = xc[s.p1.f]; k <= xc[s.p2.f]; k++) {
            for (ll l = yc[s.p1.s]; l <= yc[s.p2.s]; l++) {
                field[k][l] = 1;
            }
        }
    }

    for (ll i = 0; i < C; i++) {
        pll p = cows[i];
        field[xc[p.f]][yc[p.s]] = 2;
    }

    ll ans = 0;

    for (ll i = 0; i <= 2 * (N + C + 1); i++) {
        for (ll j = 0; j <= 2 * (N + C + 1); j++) {
            if (field[i][j] == 0 || field[i][j] == 2) {
                ans = max(ans, dfs(i, j));
            }
        }
    }

    cout << ans << "\n";
	
	return 0;
}