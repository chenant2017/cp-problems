#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll T, N;
map<char, char> adj;
map<char, vector<char>> adj2;
set<char> visited;
string s1, s2;

bool cycle(char c) {
    if (visited.find(c) != visited.end()) return false;
    
    bool result = true;

    visited.insert(c);
    if (adj2[c].size() > 1) {
        result = false;
    }

    char d = c;

    ll length = 1;

    while (visited.find(adj[d]) == visited.end()) {
        d = adj[d];
        visited.insert(d);
        if (adj2[d].size() > 1) {
            result = false;
        }
        length++;
    }

    if (adj[d] != c || length == 1) {
        result = false;
    }

    return result;
}

ll solve() {
    adj.clear();
    adj2.clear();
    visited.clear();

    ll ans = 0;

    for (ll i = 0; i < N; i++) {
        if (adj.find(s1[i]) == adj.end()) {
            adj[s1[i]] = s2[i];
            adj2[s2[i]].push_back(s1[i]);
            ans += s1[i] != s2[i];
        }
        else {
            if (adj[s1[i]] != s2[i]) {
                return -1;
            }
        }
    }

    for (auto i: s2) {
        if (adj.find(i) == adj.end()) {
            adj[i] = i;
        }
    }

    if (adj2.size() == 52 && s1 != s2) {
        return -1;
    }

    for (auto i: s1) {
        ans += cycle(i);
    }

    return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "230101";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> T;

    while (T--) {
        cin >> s1 >> s2;
        N = s1.size();

        cout << solve() << "\n";
    }
	
	return 0;
}