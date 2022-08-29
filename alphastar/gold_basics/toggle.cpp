#include <bits/stdc++.h>
#define MAX 510
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll N, M;
string grid[MAX];
ll ans[MAX][MAX] = {0}; //everything starts with 1 toggle

ll lr[2] = {-1, 1};

void find_nodes(ll starti, ll startj, ll startt, queue<tll>& bq) { //get nodes for BFS
    queue<tll> fq;
    auto start = tll({starti, startj, startt});
    fq.push(start);

    while (!fq.empty()) {
        ll i, j, t;
        tie(i, j, t) = fq.front();
        fq.pop();

        if (ans[i][j] != 0) continue;

        ans[i][j] = t;

        for (auto k: lr) {
            if (0 <= j + k && j + k < M &&
                grid[i][j + k] == '.') {
                
                ll gravity = pow(-1, t + 1);

                ll i2 = i;
                ll j2 = j + k;
                
                while (i2 + gravity >= 0 && i2 + gravity < N && 
                       grid[i2 + gravity][j2] == '.') {
                    i2 += gravity;
                }

                if (i2 + gravity >= 0 && i2 + gravity < N &&
                    grid[i2 + gravity][j2] == '#') {
                        fq.push(tll({i2, j2, t}));

                        ll gravity2 = -1 * gravity;
                        while (i2 + gravity2 >= 0 && i2 + gravity2 < N && 
                            grid[i2 + gravity2][j2] == '.') {
                            i2 += gravity2;
                        }
                        if (i2 + gravity2 >= 0 && i2 + gravity2 < N &&
                            grid[i2 + gravity2][j2] == '#') {
                                bq.push(tll({i2, j2, t + 1}));
                        }
                }   
            }
        }
    }
}

void bfs(ll starti, ll startj) {
    queue<tll> bq;
    bq.push(tll({starti, startj, 1}));

    while (!bq.empty()) {
        ll i, j, t;
        tie(i, j, t) = bq.front();
        bq.pop();

        if (ans[i][j] != 0) continue;
    
        find_nodes(i, j, t, bq);
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "toggle";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;

    ll starti, startj;
    ll dinneri, dinnerj;

    for (ll i = 0; i < N; i++) {
        cin >> grid[i];
        for (ll j = 0; j < M; j++) {
            if (grid[i][j] == 'C') {
                starti = i;
                startj = j;
                grid[i][j] = '.';
            }
            else if (grid[i][j] == 'D') {
                dinneri = i;
                dinnerj = j;
                grid[i][j] = '.';
            }
        }
    }

    bfs(starti, startj);

    cout << ans[dinneri][dinnerj] - 1 << "\n";

	return 0;
}