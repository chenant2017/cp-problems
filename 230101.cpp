#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll T, N;
string s1, s2;
map<char, char> adj;
map<char, set<char>> adj2;
map<char, bool> visited;

pair<bool, bool> cycle(char c) {
    bool circle = true;

    char p1 = adj[c];
    char p2 = adj[adj[c]];

    while (p1 != p2) {
        p1 = adj[p1];
        p2 = adj[adj[p2]];
    }

    if (adj2[p1].size() != 1) circle = false;

    p2 = adj[p2];
    ll length = 1;
    while (p1 != p2) {
        p2 = adj[p2];
        if (adj2[p2].size() != 1) circle = false;
        length++;
    }

    return {length > 1, circle};
}

void dfs(char c) {
    if (visited[c]) return;
    visited[c] = true;

    if (!visited[adj[c]]) {
        dfs(adj[c]); 
    }

    for (auto i: adj2[c]) {
        if (!visited[i]) {
            dfs(i);
        }
    }
}

ll solve() {
    adj.clear();
    adj2.clear();
    visited.clear();

    ll ans = 0;

    for (ll i = 0; i < N; i++) {
        if (adj.find(s1[i]) != adj.end()) {
            if (adj[s1[i]] != s2[i]) {
                return -1;
            }
        }
        else {
            adj[s1[i]] = s2[i];
            adj2[s2[i]].insert(s1[i]);

            ans += s1[i] != s2[i];
        }
    }

    for (auto i: s2) {
        if (adj.find(i) == adj.end()) {
            adj[i] = i;
        }
    }

    for (auto i: s1) { 
        if (visited[i]) continue;

        dfs(i);
        pair<bool, bool> cyc = cycle(i);
        if (cyc.first && cyc.second) {
            ans++;
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