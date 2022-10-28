#include <bits/stdc++.h>
#define MAXN 310
#define f first 
#define s second 

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N, M, T;
vector<pll> adj[MAXN];
ll shortest[MAXN][MAXN];

void fw() {
    for (ll i = 1; i <= N; i++) {
        for (ll j = 1; j <= N; j++) {
            shortest[i][j] = pow(10, 7);
        }
    }
    for (ll i = 1; i <= N; i++) {
        for (auto j: adj[i]) {
            shortest[i][j.f] = j.s;
        }
        shortest[i][i] = 0;
    }

    /*for (ll i = 1; i <= N; i++) {
        for (ll j = 1; j <= N; j++) {
            cout << shortest[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";*/

    for (ll k = 1; k <= N; k++) { //intermediate node
        for (ll i = 1; i <= N; i++) {
            for (ll j = 1; j <= N; j++) {
                shortest[i][j] = min(shortest[i][j], 
                                     max(shortest[i][k], shortest[k][j]));
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "jumping";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M >> T;

	for (ll i = 0; i < M; i++) {
		ll st, e, h;
		cin >> st >> e >> h;

        adj[st].push_back(pll({e, h}));
	}

    fw();

    /*for (ll i = 1; i <= N; i++) {
        for (ll j = 1; j <= N; j++) {
            cout << shortest[i][j] << " ";
        }
        cout << "\n";
    }*/

    for (ll i = 0; i < T; i++) {
        ll a, b;
        cin >> a >> b;
        if (shortest[a][b] == pow(10, 7)) {
            cout << "-1\n";
        }
        else {
            cout << shortest[a][b] << "\n";
        }
    }
	
	return 0;
}