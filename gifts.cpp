#include <bits/stdc++.h>
#define MAXN 510
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N;
vector<ll> adj[MAXN];
map<pll, bool> path_existed;

bool path_exists(ll a, ll b) {
    if (path_existed.find(pll({a, b})) != path_existed.end()) {
        return path_existed[pll({a, b})];
    }

    for (auto i: adj[a]) {
        if (path_exists(i, b)) {
            path_existed[pll({i, b})] = true;
            return true;
        }
    }
    path_existed[pll({a, b})] = false;
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
            if (k == i) done = true;
            if (!done) adj[i].push_back(k);
        }
    }

    for (ll i = 0; i < N; i++) {
        unordered_set<ll> visited;
        if (path_exists(i, i)) {
            //cout << "there is path from " << j + 1 << " to " << i + 1 << "\n";
            cout << j + 1 << "\n";
            break;
        }
    }
	
	return 0;
}