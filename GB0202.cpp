#include <bits/stdc++.h>
#define MAX 110
#define MAXT 20

using namespace std;

typedef long long ll;
ll N, M, T;
ll R1, C1, R2, C2;
string pasture[MAX];
ll ans[MAX][MAX][MAXT] = {0};

ll di[] = {0, 0, -1, 1};
ll dj[] = {-1, 1, 0, 0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GB0202";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M >> T;
	
    for (ll i = 0; i < N; i++) {
        string s;
        cin >> s;
        pasture[i] = s;
    }

    cin >> R1 >> C1 >> R2 >> C2;
    R1--; C1--; R2--; C2--;

    ans[R1][C1][0] = 1;

    for (ll t = 1; t <= T; t++) {
        for (ll i = 0; i < N; i++) {
            for (ll j = 0; j < M; j++) {
                if (pasture[i][j] == '*') continue;

                for (ll d = 0; d < 4; d++) {
                    ll nexti = i + di[d];
                    ll nextj = j + dj[d];

                    if (0 <= nexti && nexti < N &&
                        0 <= nextj && nextj < M) {
                        ans[i][j][t] += ans[nexti][nextj][t - 1];
                    }
                }
            }
        }
    }

    cout << ans[R2][C2][T] << "\n";

	return 0;
}