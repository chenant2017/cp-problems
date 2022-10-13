#include <bits/stdc++.h>
#define MAXN 110

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll N, T;
ll sizes[MAXN][MAXN];
ll times[MAXN][MAXN];
ll destsi[6] = {N - 3, N - 2, N - 2, N - 1, N - 1, N - 1};
ll destsj[6] = {N - 1, N - 1, N - 2, N - 1, N - 2, N - 3};
bool visited[MAXN][MAXN] = {{false}};

void reset() {
    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            times[i][j] = pow(10, 7);
        }
    }
}

ll dijkstra() {
    priority_queue<tll, vector<tll>, greater<tll>> q;
    q.push(tll({0, 0, 0}));

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

        for (ll di = -1; di <= 1; di++) {
            for (ll dj = -1; dj <= 1; dj++) {
                if (di + dj != -1 && di + dj != 1) {
                    continue;
                }
                ll nexti = i + di;
                ll nextj = j + dj;

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

    reset();
    dijkstra();

    ll ans = pow(10, 7);

    for (ll x = 0; x < 6; x++) {
        ll desti = destsi[x];
        ll destj = destsj[x];
        ans = min(ans, times[desti][destj]);
    }
    
    cout << ans << "\n";
	
	return 0;
}

