#include <bits/stdc++.h>
#define MAXN 110
using namespace std;

typedef long long ll;

ll N, M;
vector<ll> path;
ll shortest[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GA0904";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;

    ll a;
    for (ll i = 0; i < M; i++) {
        cin >> a;
        path.push_back(a);
    }

    for (ll i = 1; i <= N; i++) {
        for (ll j = 1; j <= N; j++) {
            cin >> shortest[i][j];
        }
    }

    for (ll k = 1; k <= N; k++) {
        for (ll i = 1; i <= N; i++) {
            for (ll j = 1; j <= N; j++) {
                shortest[i][j] = min(shortest[i][j], 
                                     shortest[i][k] + shortest[k][j]);
            }
        }
    }

    ll total = 0;

    for (ll i = 0; i < path.size(); i++) {
        total += shortest[path[i]][path[i + 1]];
    }

    cout << total << "\n";
	
	return 0;
}