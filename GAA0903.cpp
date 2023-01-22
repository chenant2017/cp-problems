#include <bits/stdc++.h>
#define MAX 55
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll R, C;
string past[MAX];
bool in[MAX][MAX];
vector<pll> pts;
ll di[4] = {0, 0, -1, 1};
ll dj[4] = {1, -1, 0, 0};
vector<pll> hull (MAX * MAX * 2);

ll xp(pll a, pll b, pll c) {
    b.f -= a.f;
    b.s -= a.s;
    c.f -= a.f;
    c.s -= a.s;

    return b.f * c.s - b.s * c.f;
}

void ch() { // convex hull
    ll k = 0;

    for (ll i = 0; i < pts.size(); i++) {
        //cout << k << "\n";
        while (k >= 2 && xp(hull[k - 2], hull[k - 1], pts[i]) > 0) {
            k--;
        }
        hull[k] = pts[i];
        k++;
    }

    ll top = k - 1;

    for (ll i = pts.size() - 2; i >= 0; i--) {
        while (k >= top + 2 && xp(hull[k - 2], hull[k - 1], pts[i]) > 0) {
            k--;
        }
        hull[k] = pts[i];
        k++;
    }

    hull.resize(k - 1);
}

ll dist(pll a, pll b) {
    ll ddi = abs(a.f - b.f);
    ll ddj = abs(a.s - b.s);

    return min(ddi, ddj) + abs(ddi - ddj);
}

int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	
	string fname = "GAA0903";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> R >> C;

    for (ll i = 0; i < R; i++) {
        cin >> past[i];
    }

    for (ll i = 0; i < R; i++) {
        for (ll j = 0; j < C; j++) {
            if (past[i][j] == '.') continue;

            if (past[i][j] == 'X') {
                for (ll d = 0; d < 4; d++) {
                    ll ni = i + di[d];
                    ll nj = j + dj[d];

                    if (past[ni][nj] == '.' && !in[ni][nj]) {
                        in[ni][nj] = true;
                        pts.push_back({ni, nj});
                    }
                }
            }
            else if (past[i][j] == '*') {
                pts.push_back({i, j});
            }
        }
    }

    sort(pts.begin(), pts.end());

    ch();

    ll ans = 0;

    for (ll i = 0; i < hull.size() - 1; i++) {
        ans += dist(hull[i], hull[i + 1]);
    }
    ans += dist(*hull.rbegin(), hull[0]);

    cout << ans << "\n";
	
	return 0;
}