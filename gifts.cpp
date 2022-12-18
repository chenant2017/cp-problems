#include <bits/stdc++.h>
#define MAXN 510
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N;
bool adj[MAXN][MAXN];
ll assigned[MAXN][MAXN];
map<pll, bool> path_existed;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "gifts";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) {
        bool done = false;
        for (ll j = 0; j < N; j++) {
            ll k;
            cin >> k;
            k--;
            assigned[i][j] = k;
            if (!done) adj[i][k] = true;
            if (k == i) done = true;
        }
    }

    for (ll k = 0; k < N; k++) {
        for (ll i = 0; i < N; i++) {
            for (ll j = 0; j < N; j++) {
                adj[i][j] = adj[i][j] || (adj[i][k] && adj[k][j]);
            }
        }
    }

    /*for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            cout << ((adj[i][j]) ? "1" : "0") << " ";
        }
        cout << "\n";
    }*/

    for (ll i = 0; i < N; i++) {
        //cout << i << " i\n";
        for (ll j = 0; j < N; j++) {
            if (adj[i][assigned[i][j]] && adj[assigned[i][j]][i]) {
                //cout << "there is path from " << j + 1 << " to " << i + 1 << "\n";
                cout << assigned[i][j] + 1 << "\n";
                break;
            }
        }
    }
	
	return 0;
}