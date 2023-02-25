#include <bits/stdc++.h>
#define MAX 1010
using namespace std;

typedef long long ll;

ll N, M;
ll tl[MAX];

bool add(ll a, ll b, char c) {
    if (tl[a] == 0) {
        if (tl[b] == 0) {
            if (c == 'T') {
                tl[a] = 1;
                tl[b] = 1;
            }
            else {
                tl[a] = 1;
                tl[b] = 2;
            }
        }
        else {
            if (c == 'T') {
                tl[a] = tl[b];
            }
            else {
                tl[a] = 3 - tl[b];
            }
        }
        return true;
    }
    else {
        if (tl[b] == 0) {
            return add(b, a, c);
        }
        else {
            if (c == 'T') {
                return tl[a] == tl[b];
            }
            else {
                return tl[a] != tl[b];
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "truth";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;

    for (ll i = 0; i < M; i++) {
        ll a, b; char c;
        cin >> a >> b >> c;

        if (!add(a, b, c)) {
            cout << i << "\n";
            return 0;
        }
    }

    cout << N << "\n";
	
	return 0;
}