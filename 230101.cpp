#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll T, N;
string s1, s2;
map<char, char> adj;
map<char, set<char>> adj2;
map<char, bool> visited;
bool unlooped = false;

pair<bool, bool> cycle(char c) {
    bool circle = true;

    char p1 = c;
    char p2 = adj[c];

    while (p1 != p2) {
        p1 = adj[p1];
        p2 = adj[adj[p2]];
    }

    if (adj2[p1].size() > 1) circle = false;

    p2 = adj[p2];
    ll length = 1;
    while (p1 != p2) {
        p2 = adj[p2];
        if (adj2[p2].size() > 1) circle = false;
        length++;
    }

    return {length > 1, circle};
}

void dfs(char c, ll& n) {
    if (visited[c]) return;
    visited[c] = true;

    if (adj.find(c) == adj.end()) {
        unlooped = true;
    }
    else if (adj[c] != c) {
        n++;
    }

    if (!visited[adj[c]]) {
        dfs(adj[c], n); 
    }

    for (auto i: adj2[c]) {
        if (!visited[i]) {
            dfs(i, n);
        }
    }
}

ll solve() {
    adj.clear();
    adj2.clear();
    visited.clear();
    unlooped = false;

    for (ll i = 0; i < N; i++) {
        if (adj.find(s1[i]) != adj.end() && adj[s1[i]] != s2[i]) {
            return -1;
        }
        adj[s1[i]] = s2[i];
        adj2[s2[i]].insert(s1[i]);
    }

    ll ans = 0;

    bool extra = false;

    for (auto i: s1) { 
        if (visited[i]) continue;

        ll n = 0;
        dfs(i, n);
        pair<bool, bool> cyc = cycle(i);
        ans += n;
        if (cyc.first) {
            ans++;
            if (cyc.second) extra = true;
        }
    }

    if (adj2.size() == 52) {
        return -1;
    }
    
    return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "230101";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> T;

    while (T--) {
        cin >> s1 >> s2;
        N = s1.size();

        cout << solve() << "\n";
    }

	
	return 0;
}