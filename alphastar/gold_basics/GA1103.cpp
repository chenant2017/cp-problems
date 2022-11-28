#include <bits/stdc++.h>
#define MAX 35
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll, ll> tll;

ll M, N;
ll pond[MAX][MAX];
pll dists[MAX][MAX];
ll counts[MAX][MAX];
bool visited[MAX][MAX] = {false};
int di[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dj[] = {-1, 1, -2, 2, -2, 2, -1, 1};

void dijkstra(ll starti, ll startj) {
    for (ll i = 0; i < M; i++) {
        for (ll j = 0; j < N; j++) {
            dists[i][j] = pll({1000, -1});
        }
    }

    priority_queue<tll, vector<tll>, greater<tll>> q;
    dists[starti][startj] = pll({0, 0});
    counts[starti][startj] = 1;
    q.push(tll({0, 0, starti, startj}));

    while (!q.empty()) {
        auto curr = q.top();
        q.pop();

        ll geese, jumps, i, j;
        tie(geese, jumps, i, j) = curr;

        if (visited[i][j]) continue;
        visited[i][j] = true;

        for (ll d = 0; d < 8; d++) {
            ll i2 = i + di[d];
            ll j2 = j + dj[d];

            if (0 <= i2 && i2 < M &&
                0 <= j2 && j2 < N) {
                
                if (pond[i2][j2] != 2) {
                    pll dist2;
                    if (pond[i2][j2] == 0) {
                        dist2 = pll({geese + 1, jumps + 1});
                    }
                    else {
                        dist2 = pll({geese, jumps + 1});
                    }
                    if (dist2 < dists[i2][j2]) {
                        dists[i2][j2] = dist2;
                        q.push(tll({dist2.f, dist2.s, i2, j2}));
                        counts[i2][j2] = counts[i][j];
                    }
                    else if (dist2 == dists[i2][j2]) {
                        counts[i2][j2] += counts[i][j];
                    }   
                }
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GA1103";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> M >> N;

    ll starti, startj;
    ll desti, destj;

    for (ll i = 0; i < M; i++) {
        for (ll j = 0; j < N; j++) {
            cin >> pond[i][j];
            if (pond[i][j] == 3) {
                starti = i;
                startj = j;
            }
            if (pond[i][j] == 4) {
                desti = i;
                destj = j;
            }
        }
    }

    dijkstra(starti, startj);
    pll dist = dists[desti][destj];

    if (dist.f == 1000) {
        cout << "-1\n";
    }
    else {
        cout << dist.f << "\n" << dist.s << "\n" << counts[desti][destj] << "\n";
    }   
	
	return 0;
}