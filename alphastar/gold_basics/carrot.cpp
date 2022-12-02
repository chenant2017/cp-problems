#include <bits/stdc++.h>
#define MAXN 110
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll sizes[MAXN][MAXN];
ll times[MAXN][MAXN];
bool visited[MAXN][MAXN] = {false};
ll N, T;

ll di[] = {0, 0, 1, 1, 2, 3};
ll dj[] = {1, 3, 0, 2, 1, 0};

ll dijkstra() {
    ll ans = pow(10, 10);

    priority_queue<tll> q;
    times[0][0] = 0;
    q.push(tll({0, 0, 0}));
    
    while (!q.empty()) {
        ll t, i, j;
        tie(t, i, j) = q.top();
        q.pop();
        t *= -1;

        if (visited[i][j]) continue;
        visited[i][j] = true;
        times[i][j] = t;

        ll dist = abs((N - 1) - i) + abs((N - 1) - j);
        //cout << "no\n";
        if (dist <= 2) {
            ans = min(ans, t + dist * T);
        }

        for (ll d = 0; d < 6; d++) {
             for (ll si = -1; si <= 1; si += 2) {
                for (ll sj = -1; sj <=1; sj += 2) {
                    ll ni = i + di[d] * si;
                    ll nj = j + dj[d] * sj;

                    if (0 <= ni && ni < N &&
                        0 <= nj && nj < N) {
                        times[ni][nj] = min(times[ni][nj], t + 3 * T + sizes[ni][nj]);
                        q.push(tll({-1 * times[ni][nj], ni, nj}));
                        //cout << "yes\n";
                    }
                }
            }
        }
    }
    return ans;
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
            times[i][j] = pow(10, 10);
            cin >> sizes[i][j];
        }
    }

    ll ans = dijkstra();

    cout << ans << "\n";
	
	return 0;
}