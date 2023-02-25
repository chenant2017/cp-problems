#include <bits/stdc++.h>
#define MAX 210
using namespace std;

typedef long long ll;

ll N, A, B;

struct Mirror {
    ll x, y;
    char c;

    Mirror(ll a, ll b, char d) {
        x = a;
        y = b;
        c = d;
    }

    bool operator<(const Mirror& m) const {
        return x < m.x || (x == m.x && y < m.y);
    }
};

void toggle(ll i) {
    if (mirs[i].c == '/') {
        mirs[i].c = '\\';
    }
    else {
        mirs[i].c = '/';
    }
}

bool works() {
    
}

Mirror mirs[MAX];

ll byx[MAX];
ll byy[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "130101";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> A >> B;

    for (ll i = 0; i < N; i++) {
        ll x, y; char c;

        mirs[i] = Mirror(x, y, c);
        byx[i] = i;
        byy[i] = i;
    }

    sort(byx, byx + N, [](auto& a, auto& b) {
        return Mirror[a] < Mirror[b];
    });

    sort(byy, byy + N, [](auto& a, auto& b) {
        return Mirror[a].y < Mirror[b].y ||
                (Mirror[a].y == Mirror[b].y && Mirror[a].x < Mirror[b].x);
    });

    for (ll i = 0; i < N; i++) {
        toggle(i);
        if (works()) {
            cout << i + 1 << "\n";
            return 0;
        }
        toggle(i);
    }

    cout << "-1\n";
	
	return 0;
}