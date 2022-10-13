#include <bits/stdc++.h>
#define MAXN 110

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll N, T;
ll sizes[MAXN][MAXN];
ll times[MAXN][MAXN];
bool visited[MAXN][MAXN] = {{false}};

void reset() {
    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            times[i][j] = pow(10, 7);
        }
    }
}

ll dijkstra(pll start) {
    priority_queue<tll, vector<tll>, greater<tll>> q;

    while (!q.empty()) {
        ll t, i, j;
        tie(t, i, j) = q.top();
        q.pop();

        if (visited[i][j]) continue;
        visited[i][j] = true;

        for (ll di = 0; di <= 3; di++) {
            ll dj = 3 - di;
            for (ll si = -1; si <= 1; si += 2) {
                for (ll sj = -1; sj <= 1; sj++) {
                    ll nexti = i + di * si;
                    ll nextj = j + dj * dj;

                    if (0 <= nexti && nexti < N &&
                        0 <= nextj && nextj < N &&
                        !visited[nexti][nextj]) {
                        times[nexti][nextj] = min(times[nexti][nextj], 
                                                  times[i][j] + sizes[nexti][nextj] + 
                                                  3 * T);
                        q.push(tll({times[nexti][nextj], nexti, nextj}));
                    }
                }
            }
        }

        for (ll di = -1; )

    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "carrot";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> T;

    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            cin >> sizes[i][j];
        }
    }


	
	return 0;
}

