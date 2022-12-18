#include <bits/stdc++.h>
#define MAXN 510
using namespace std;

typedef long long ll;

ll N;
vector<ll> adj[MAXN];

bool path_exists(ll a, ll b, set<ll>& visited) {
    visited.insert(a);
    if (a == b) return true;
    for (auto i: adj[a]) {
        if (visited.find(i) == visited.end() && path_exists(i, b, visited)) {
            return true;
        }
    }
    return false;
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
            if (!done) adj[i].push_back(k);
            if (k == i) done = true;
        }
    }

    for (ll i = 0; i < N; i++) {
        for (auto j: adj[i]) {
            set<ll> visited;
            if (path_exists(j, i, visited)) {
                //cout << "there is path from " << j + 1 << " to " << i + 1 << "\n";
                cout << j + 1 << "\n";
                break;
            }
        }
    }
	
	return 0;
}