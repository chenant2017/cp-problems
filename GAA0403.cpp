#include <bits/stdc++.h>
#define MAXN 2010
using namespace std;

typedef long long ll;

ll N;
ll adj[MAXN][MAXN];
ll ids[MAXN];
ll dists[MAXN];
bool visited[MAXN] = {false};

ll prims() {
    for (ll i = 0; i < N; i++) {
        dists[i] = -1;
    }

    ll result = 0;
    dists[0] = 0;

    for (ll i = 0; i < N; i++) {
        ll curr = -1;
        for (ll j = 0; j < N; j++) {
            if (!visited[j] && (curr == -1 || dists[j] > dists[curr])) {
                curr = j;
            }
        }

        visited[curr] = true;  
        result += dists[curr];

        for (ll j = 0; j < N; j++) {
            if (adj[curr][j] > dists[j]) {
                dists[j] = adj[curr][j];
            }
        }
    }

    return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAA0403";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;
	
    for (ll i = 0; i < N; i++) {
        cin >> ids[i];
    }

    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            adj[i][j] = ids[i] ^ ids[j];
        }
    }

    cout << prims() << "\n";

	return 0;
}