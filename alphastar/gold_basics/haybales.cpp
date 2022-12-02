#include <bits/stdc++.h>
#define f first 
#define s second 
#define MAXN 1001
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pdl;
typedef tuple<ll, ll, ll> tll;

ll N, X, Y;
ll barn[MAXN + 1][MAXN + 1];
ll dx[] = {0, 0, 1, -1};
ll dy[] = {1, -1, 0, 0};

queue<tll> bales;

void dfs(ll i, ll j, ll b) {
    stack<pdl> q;
    q.push(pll({i, j}));

    while (!q.empty()) {
        auto curr = q.top();
        q.pop();

        if (!(curr.f >= 0 && curr.f <= MAXN) ||
            !(curr.s >= 0 && curr.s <= MAXN) ||
            barn[curr.f][curr.s] == -1 || 
            barn[curr.f][curr.s] <= b) continue;

        barn[curr.f][curr.s] = b;

        for (ll d = 0; d < 4; d++) {
            ll nexti = curr.f + dx[d];
            ll nextj = curr.s + dy[d];
            if (nexti >= 0 && nexti <= MAXN &&
                nextj >= 0 && nextj <= MAXN) {
                if (barn[nexti][nextj] == -1) {
                    bales.push(tll({nexti, nextj, b + 1}));
                }
                else if (barn[nexti][nextj] > b) {
                    q.push(pll({nexti, nextj}));  
                }
            }    
        }
    }
}

void bfs() {
    dfs(X, Y, 0);

    //cout << bales.size() << "\n";

    while (!bales.empty()) {
        //cout << bales.size() << "\n";
        ll i, j, b;
        tie(i, j, b) = bales.front();
        bales.pop();

        //cout << i << " " << j << " " << b << " ijb\n";
        if (barn[i][j] != -1 && b >= barn[i][j]) continue;
        barn[i][j] = b;

        for (ll d = 0; d < 4; d++) {
            ll nexti = i + dx[d];
            ll nextj = j + dy[d];
            if (nexti >= 0 && nexti <= MAXN &&
                nextj >= 0 && nextj <= MAXN) {
                if (barn[nexti][nextj] == -1) {
                    bales.push(tll({nexti, nextj, b + 1}));
                }
                else if (barn[nexti][nextj] > b) {
                    dfs(nexti, nextj, b);
                }
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "haybales";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> X >> Y;

    for (ll i = 0; i <= MAXN; i++) {
        for (ll j = 0; j <= MAXN; j++) {
            barn[i][j] = 50001;
        }
    }

    for (ll i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;
        barn[x][y] = -1;
    }

    bfs();

    cout << barn[0][0] << "\n";
	
	return 0;
}