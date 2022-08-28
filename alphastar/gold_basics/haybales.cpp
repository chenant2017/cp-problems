#include <bits/stdc++.h>
#define f first 
#define s second 
#define MAXN 100
using namespace std;

typedef long long ll;
typedef tuple<ll, ll, ll> tll;

ll N, X, Y;
ll barn[MAXN + 1][MAXN + 1];
ll dx[] = {0, 0, 1, -1};
ll dy[] = {1, -1, 0, 0};

queue<tll> bales;

void dfs(ll i, ll j, ll b) {
    if (!(i >= 0 && i <= MAXN) ||
        !(j >= 0 && j <= MAXN) ||
        barn[i][j] == -1 || 
        barn[i][j] <= b) return;
    //cout << i << " " << j << " " << b << "\n";
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

void bfs() {
    dfs(X, Y, 0);

    //cout << bales.size() << "\n";

    while (!bales.empty()) {
        //cout << bales.size() << "\n";
        ll i, j, b;
        tie(i, j, b) = bales.front();
        bales.pop();

        //cout << i << " " << j << " " << b << " ijb\n";

        barn[i][j] = b;

        for (ll d = 0; d < 4; d++) {
            ll nexti = i + dx[d];
            ll nextj = j + dy[d];

            if (nexti >= 0 && nexti <= MAXN &&
                nextj >= 0 && nextj <= MAXN &&
                barn[nexti][nextj] != -1 &&
                barn[nexti][nextj] > b
                ) {
                    //cout << nexti << " " << nextj << "\n";
                    dfs(nexti, nextj, b);   
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