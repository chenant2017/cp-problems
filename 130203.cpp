#include <bits/stdc++.h>
#define MAX 110
using namespace std;

typedef long long ll;

ll N;
bool field[MAX][MAX];
bool visited[MAX][MAX];
ll dx[] = {0, 0, 1, -1};
ll dy[] = {1, -1, 0, 0};

ll dfs(ll x, ll y) {
    if (visited[x][y]) return 0;
    visited[x][y] = true;

    ll result = 0;

    for (ll d = 0; d < 4; d++) {
        ll x2 = x + dx[d];
        ll y2 = y + dy[d];

        if (0 <= x2 && x2 <= 101 && 
            0 <= y2 && y2 <= 101) {

            if (field[x2][y2]) {
                result++;
            }
            else {
                result += dfs(x2, y2);
            }
        }
    }

    return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "perimeter";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;
        field[x][y] = true;
    }
    
    ll ans = 0;

    for (ll j = 0; j <= 101; j++) {
        ans += dfs(0, j);
        ans += dfs(101, j);
    }

    for (ll i = 1; i <= 100; i++) {
        ans += dfs(i, 0);
        ans += dfs(i, 101);
    }

    cout << ans << endl;
	
	return 0;
}