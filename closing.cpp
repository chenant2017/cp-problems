#include <bits/stdc++.h>
#define MAXN 3010
using namespace std;

typedef long long ll;

ll N, M;
vector<ll> adj[MAXN];
unordered_set<ll> visited;
unordered_set<ll> remaining;

void dfs(ll start) {
    if (visited.find(start) != visited.end()) return;
    visited.insert(start);

    for (auto i: adj[start]) {
        if (visited.find(i) == visited.end() &&
            remaining.find(i) != remaining.end()) dfs(i);
    }
}

bool is_connected() {
    visited.clear();

    dfs(*remaining.begin());
        
    /*//if (removed.find(i) == removed.end()) {
        if (remaining.find(i) )
            dfs(i);
            break;
        }
    }*/

    return (visited.size() == remaining.size());
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "closing";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;

    for (ll i = 0; i < M; i++) {
        ll a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (ll i = 1; i <= N; i++) {
        remaining.insert(i);
    }

    if (is_connected()) {
        cout << "YES\n";
    }   
    else {
        cout << "NO\n";
    }


    for (ll i = 0; i < N - 1; i++) {
        ll a;
        cin >> a;
        remaining.erase(a);

        if (is_connected()) {
            cout << "YES\n";
        }   
        else {
            cout << "NO\n";
        }
    }


	return 0;
}