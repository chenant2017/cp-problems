#include <bits/stdc++.h>
#define MAXN 1510
using namespace std;

typedef long long ll;

ll N, Q;
ll b[MAXN];
ll r[MAXN];
string dir[MAXN];
ll counts[MAXN][MAXN];

ll dfs(ll i, ll j, ll d) {
    counts[i][j] += d;

    if (i == N && dir[i][j] == 'D') {
        return b[j];
    }
    if (j == N && dir[i][j] == 'R') {
        return r[i];
    }
    
    if (dir[i][j] == 'R') {
        return dfs(i, j + 1, d);
    }
    else {
        return dfs(i + 1, j, d);
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "230102";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 1; i <= N; i++) {
        cin >> dir[i];
        dir[i] = " " + dir[i];
        cin >> r[i];
    }

    for (ll i = 1; i <= N; i++) {
        cin >> b[i];
    }

    ll ans = 0;

    for (ll i = 1; i <= N; i++) {
        for (ll j = 1; j <= N; j++) {
            dfs(i, j, 1);
            
            if (i == N && dir[i][j] == 'D') {
                ans += counts[i][j] * b[j];
            }
            if (j == N && dir[i][j] == 'R') {
                ans += counts[i][j] * r[i];
            }
        }
    }

    cout << ans << "\n";
    
    cin >> Q;

    for (ll i = 0; i < Q; i++) {
        ll a, b;
        cin >> a >> b;

        if (dir[a][b] == 'R') {
            ll n = counts[a][b];
            ll c = dfs(a, b, -1 * n);
            counts[a][b] = n;
            ans -= counts[a][b] * c;

            dir[a][b] = 'D';
            c = dfs(a, b, n);
            counts[a][b] = n;
            ans += counts[a][b] * c;
        }
        else {
            ll n = counts[a][b];
            ll c = dfs(a, b, -1 * n);
            counts[a][b] = n;
            ans -= counts[a][b] * c;

            dir[a][b] = 'R';
            c = dfs(a, b, n);
            counts[a][b] = n;
            ans += counts[a][b] * c;
        }

        cout << ans << "\n";
    }

    /*for (ll i = 1; i <= N; i++) {
        for (ll j = 1; j <= N; j++) {
            cout << counts[i][j] << " ";
        }
        cout << "\n";
    }

    cout << ans << "\n";*/

	
	return 0;
}