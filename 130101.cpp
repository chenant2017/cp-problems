#include <bits/stdc++.h>
#define MAX 210
using namespace std;

typedef long long ll;

ll N, A, B;

struct Mirror {
    ll x, y, i;
    char c;

    Mirror(ll p, ll q, char r, ll s) {
        x = p;
        y = q;
        c = r;
        i = s;
    }

    Mirror() {};

    bool operator<(const Mirror &m) const {
        return x < m.x || (x == m.x && y < m.y);
    }
};

Mirror mirs[MAX];
Mirror mirs2[MAX];
char field[MAX][MAX];

void compress() {
    sort(mirs2, mirs2 + N);

    for (ll j = 0; j < N; j++) { 
        Mirror& mir = mirs2[j];
        if (j > 0) {
            Mirror& pre = mirs2[j - 1];
            if (mirs[pre.i].x == mir.x) {
                mir.x = pre.x;
                continue;
            }
        }
        mir.x = j;
    }
	
    sort(mirs2, mirs2 + N, [](auto& a, auto& b) {
        return a.y < b.y || (a.y == b.y && a.x < b.x);
    });

    for (ll j = 0; j < N; j++) {
        Mirror& mir = mirs2[j];
        if (j > 0) {
            Mirror& pre = mirs2[j - 1];
            if (mirs[pre.i].y == mir.y) {
                mir.y = pre.y;
                continue;
            }
        }
        mir.y = j;
    }
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "mirrors";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
    cin >> N >> A >> B;

    for (ll i = 0; i < N; i++) {
        ll x, y; char c;
        cin >> x >> y >> c;
        mirs[i] = Mirror(x, y, c, i);
        mirs2[i] = Mirror(x, y, c, i);
    }

    compress();

    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            field[i][j] = ' ';
        }
    }

    for (ll j = 0; j < N; j++) {
        field[mirs2[j].x][mirs2[j].y] = mirs2[j].c;
    }

    ll ans = 1e18;

    for (ll i = 0; i < N; i++) {

    }


	return 0;
}