#include <bits/stdc++.h>
#define MAXN 110
using namespace std;

typedef long long ll;

ll adj[MAXN][MAXN];
ll dists[MAXN];
bool visited[MAXN];
ll N;

ll prims() {
    ll total = 0;

    for (ll i = 0; i < N; i++) {
        dists[i] = 110000;
    }
    dists[0] = 0;

    for (ll i = 0; i < N; i++) {
        ll curr = -1;
        for (ll j = 0; j < N; j++) {
            if (!visited[j] && (curr == -1 || (dists[j] < dists[curr]))) {
                curr = j;
            }
        }

        visited[curr] = true;
        total += dists[curr];
        dists[curr] = 0;

        for (ll j = 0; j < N; j++) {
            dists[j] = min(dists[j], adj[curr][j]);
        }
    }

    return total;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GA0701";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < N; j++) {
			cin >> adj[i][j];
		}
	}

    cout << prims() << "\n";

	
	return 0;
}