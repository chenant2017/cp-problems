#include <bits/stdc++.h>
#define f first 
#define s second
#define MAXN 310
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N, M, T;

vector<pll> adj[MAXN];
ll shortests[MAXN][MAXN] = {0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GA0903";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M >> T;

    for (ll i = 1; i <= N; i++) {
        for (ll j = 1; j <= N; j++) {
            if (i != j) {
                shortests[i][j] = pow(10, 7);
            }
        }
    }

    ll s, e, h;
    for (ll i = 0; i < M; i++) {
        cin >> s >> e >> h;
        adj[s].push_back(pll({e, h}));
        shortests[s][e] = h;
    }

    for (ll k = 1; k <= N; k++) {
        for (ll i = 1; i <= N; i++) {
            for (ll j = 1; j <= N; j++) {
                ll min2 = max(shortests[i][k], shortests[k][j]);
                shortests[i][j] = min(shortests[i][j], min2);
            }
        }
    }

    ll a, b;
    for (ll i = 0; i < T; i++) {
        cin >> a >> b;
        if (shortests[a][b] == pow(10, 7)) cout << "-1\n";
        else cout << shortests[a][b] << "\n";
    }
	
	return 0;
}