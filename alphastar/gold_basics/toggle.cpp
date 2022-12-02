#include <bits/stdc++.h>
#define MAXN 510
#define MAXM 510
#define f first  
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pdl;
typedef tuple<ll, ll, ll> tll;

ll N, M;
string grid[MAXN];
pdl visited[MAXN][MAXM];
ll dir[] = {-1, 1};
queue<tll> bfsq;

void get_nodes(ll i, ll j, ll t) {
    queue<pdl> q;
    
    q.push(pll({i, j}));

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        ll g = pow(-1, t);

        if (g == 1) {
            if (visited[curr.f][curr.s].f != -1) continue;
            visited[curr.f][curr.s].f = t;
        }
        else {
            if (visited[curr.f][curr.s].s != -1) continue;
            visited[curr.f][curr.s].s = t;
        }

        if ((curr.f + g) >= 0 && (curr.f + g) < N) {
            if (grid[curr.f + g][curr.s] == '.' || 
                grid[curr.f + g][curr.s] == 'D') {
                q.push(pll({curr.f + g, curr.s}));
            }
            
            else {
                bfsq.push(tll({curr.f, curr.s, t + 1}));
                for (auto k: dir) {
                    if (curr.s + k >= 0 && curr.s + k < M && 
                        (grid[curr.f][curr.s + k] == '.' || 
                        grid[curr.f][curr.s + k] == 'D')) {
                            q.push(pll({curr.f, curr.s + k}));
                    }
                }      
            }
        }
    }
}

void bfs(ll starti, ll startj) {
    bfsq.push(tll({starti, startj, 0}));

    while (!bfsq.empty()) {
        ll i, j, t;
        tie(i, j, t) = bfsq.front();
        bfsq.pop();

        get_nodes(i, j, t);
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
            if (grid[i][j] == 'D') {
                dinneri = i;
                dinnerj = j;
            }
        }
    }

    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < M; j++) {
            visited[i][j].f = -1;
            visited[i][j].s = -1;
        }
    }

    bfs(starti, startj);

    ll ans = -1;
    if (visited[dinneri][dinnerj].f != -1) {
        ans = visited[dinneri][dinnerj].f;
    }
    if (visited[dinneri][dinnerj].s != -1) {
        if (ans == -1 || visited[dinneri][dinnerj].s < ans) {
            ans =  visited[dinneri][dinnerj].s;
        }
    }
    
    cout << ans <<"\n";

	return 0;
}