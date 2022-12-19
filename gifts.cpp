#include <bits/stdc++.h>
#define MAXN 510
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N;
vector<ll> adj[MAXN];
bool path_exists[MAXN][MAXN] = {false};

void dfs(ll start, ll curr) {
    if (path_exists[start][curr]) return;
    path_exists[start][curr] = true;

    for (auto i: adj[curr]) {
        //if (!path_exists[start][i]) {
            dfs(start, i);
        //}
    }
}

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
            if (!done) {
                adj[i].push_back(k);
            }
            if (k == i) done = true;
        }
    }

    for (ll i = 0; i < N; i++) {
        dfs(i, i);
    }

    for (ll i = 0; i < N; i++) {
        for (auto j: adj[i]) {
            if (path_exists[j][i]) {
                //cout << "there is path from " << j + 1 << " to " << i + 1 << "\n";
                cout << j + 1 << "\n";
                break;
            }
        }
    }
	
	return 0;
}