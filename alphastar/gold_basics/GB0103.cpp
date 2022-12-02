#include <bits/stdc++.h>
#define MAXR 110
#define MAXC 110
using namespace std;

typedef long long ll;

ll R, C;
ll pies[MAXR][MAXC];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "pie";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> R >> C;

    for (ll i = 0; i < R; i++) {
        for (ll j = 0; j < C; j++) {
            cin >> pies[i][j];
        }
    }

    /*for (ll i = 0; i < R; i++) {
        for (ll j = 0; j < C; j++) {
            cout << pies[i][j] << " ";
        }
        cout << "\n";
    }*/

    for (ll i = 1; i < R; i++) {
        for (ll j = 0; j < i; j++) {
            pies[i][j] = 0;
        }
    }

    for (ll j = 1; j < C; j++) {
        for (ll i = 0; i < R; i++) {
            ll max_coins = 0;
            for (ll di = -1; di <= 1; di++) {
                ll nexti = i + di;
                ll nextj = j - 1;
                if (0 <= nexti && nexti < R &&
                    0 <= nextj && nextj < C) {
                    max_coins = max(max_coins, pies[nexti][nextj]);
                }
            }
            pies[i][j] += max_coins;
        }
    }

    /*for (ll i = 0; i < R; i++) {
        for (ll j = 0; j < C; j++) {
            cout << pies[i][j] << " ";
        }
        cout << "\n";
    }*/

    cout << pies[R - 1][C - 1] << "\n";
	
	return 0;
}