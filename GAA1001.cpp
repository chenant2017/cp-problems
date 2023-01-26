#include <bits/stdc++.h>
#define MAX 1010
using namespace std;

typedef long long ll;
typedef tuple<ll, ll, ll, bool> tlb;

ll N, M;
ll maze[MAX][MAX];
ll dist[MAX][MAX][2];
ll di[] = {0, 0, -1, 1};
ll dj[] = {1, -1, 0, 0};
bool visited[MAX][MAX][2];

pair<ll, ll> slide(ll i, ll j, ll did, ll djd) {
    while (0 <= i + did && i + did < N && 
           0 <= j + djd && j + djd < M &&
           maze[i + did][j + djd] == 4) {
        
        i += did;
        j += djd;
    }

    if (0 <= i + did && i + did < N && 
        0 <= j + djd && j + djd < M &&
        maze[i + did][j + djd] != 0) {
        i += did;
        j += djd;
    }

    return {i, j};
}

void solve() {
    priority_queue<tlb, vector<tlb>, greater<tlb>> pq;
    pq.push({0, 0, 0, false});
    dist[0][0][false] = 0;

    while (!pq.empty()) {
        ll d, i, j;
        bool o;

        tie(d, i, j, o) = pq.top();
        pq.pop();

        if (visited[i][j][o]) continue;
        visited[i][j][o] = true;
    

        if (maze[i][j] == 2) {
            o = true;
        }

        for (ll dd = 0; dd < 4; dd++) {
            ll ni = i + di[dd];
            ll nj = j + dj[dd];

            if (0 <= ni && ni < N &&
                0 <= nj && nj < M) {
                
                switch (maze[ni][nj]) {
                    case 0:
                        break;
                    case 3:
                        if (!o) break;
                    case 1:
                    case 2:
                        //cout << d + 1 << " " << dist[i][j][o] << "\n";
                        if (d + 1 < dist[ni][nj][o]) {
                            dist[ni][nj][o] = d + 1;
                            pq.push({d + 1, ni, nj, o});
                            
                        }
                        break;
                    case 4:
                        tie(ni, nj) = slide(i, j, di[dd], dj[dd]);
                        ll trav = ni - i + nj - j;
                        if (d + trav < dist[ni][nj][false]) {
                            dist[ni][nj][false] = d + trav;
                            pq.push({d + trav, ni, nj, false});
                        }
                }
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAA1001";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;

    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < M; j++) {
            cin >> maze[i][j];
        }
    }

    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < M; j++) {
            for (ll k = 0; k < 2; k++) {
                dist[i][j][k] = 1e18;
            }
        }
    }

    solve();

    ll ans = min(dist[N - 1][M - 1][false],  dist[N - 1][M - 1][true]);

    if (ans == 1e18) {
        cout << -1 << "\n";
    }
    else {
        cout << ans << "\n";
    }

	
	return 0;
}