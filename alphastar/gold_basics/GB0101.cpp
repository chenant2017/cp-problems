#include <bits/stdc++.h>
#define MAXR 100
using namespace std;

typedef long long ll;

ll board[MAXR][MAXR];
ll R;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GB0101";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> R;

    for (ll i = 0; i < R; i++) {
        for (ll j = 0; j < i + 1; j++) {
            cin >> board[i][j];
        }
    }

    for (ll i = 1; i < R; i++) {
        for (ll j = 0; j < i + 1; j++) {
            ll choice1 = -1, choice2 = -1;
            if (j > 0) {
                choice1 = board[i - 1][j - 1];
            }
            if (j < i) {
                choice2 = board[i - 1][j];
            }
            board[i][j] += max(choice1, choice2);
        }
    }

    ll ans = 0;

    for (ll i = 0; i < R; i++) {
        ans = max(ans, board[R - 1][i]);
    }

    cout << ans << "\n";
	
	return 0;
}