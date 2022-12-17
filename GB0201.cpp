#include <bits/stdc++.h>
#define MAX 110
using namespace std;

typedef long long ll;

ll R, C, K;
ll squares[MAX][MAX];
ll ans[MAX][MAX] = {0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GB0201";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> R >> C >> K;

    for (ll i = 0; i < R; i++) {
        for (ll j = 0; j < C; j++) {
            cin >> squares[i][j];
        }
    }

    ans[0][0] = 1;

    for (ll i = 0; i < R; i++) {
        for (ll j = 0; j < C; j++) {
            for (ll p = 0; p < i; p++) {
                for (ll q = 0; q < j; q++) {
                    if (squares[i][j] != squares[p][q]) {
                        ans[i][j] += ans[p][q];
                        ans[i][j] %= (ll) pow(10, 9) + 7;
                    }
                }
            }
        }
    }

    cout << ans[R - 1][C - 1] << "\n";
	
	return 0;
}