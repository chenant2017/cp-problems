#include <bits/stdc++.h>
#define MAXN 110
using namespace std;

typedef long long ll;
typedef tuple<ll, ll, ll> tll;

ll farms[MAXN][MAXN];
ll N, T;
ll di[6] = {3, 2, 1, 1, 0, 0};
ll dj[6] = {0, 1, 0, 2, 1, 3};
ll dists[MAXN][MAXN];
bool visited[MAXN][MAXN];

ll dijkstra() {
    ll result = -1;

    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            dists[i][j] = -1;
        }
    }

    priority_queue<tll, vector<tll>, greater<tll>> q;
    q.push(tll({0, 0, 0}));
    dists[0][0] = 0;

    while (!q.empty()) {
        ll d, i, j;
        tie(d, i, j) = q.top(); q.pop();

        if (visited[i][j]) continue;
        visited[i][j] = true;

        ll dist_end = abs(i - (N - 1)) + abs(j - (N - 1));
        if (dist_end <= 2) {
            ll total_dist = dist_end * T + d;
            if (result == -1 || total_dist < result) {
                result = total_dist;
            }
        }
        
        for (ll si = -1; si <= 1; si += 2) {
            for (ll sj = -1; sj <= 1; sj += 2) {
                for (ll d = 0; d < 6; d++) {
                    ll nexti = i + di[d] * si;
                    ll nextj = j + dj[d] * sj;

                    if (0 <= nexti && nexti < N &&
                        0 <= nextj && nextj < N) {
                        
                        ll newdist = dists[i][j] + farms[nexti][nextj] + 3 * T;

                        if (dists[nexti][nextj] == -1 || newdist < dists[nexti][nextj]) {
                            dists[nexti][nextj] = newdist;
                            if (!visited[nexti][nextj]) {
                                q.push(tll({dists[nexti][nextj], nexti, nextj}));
                            }
                        }
                    }
                }
            }
        }
    }
    return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GA1004";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
    cin >> N >> T;

    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            cin >> farms[i][j];
        }
    }

    cout << dijkstra() << "\n";
	
	return 0;
}