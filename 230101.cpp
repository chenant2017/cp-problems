#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll T;
ll N;
string s1;
string s2;


map<char, char> c; //child
map<char, vector<char>> p; // parent;
set<char> visited;

bool cycle(char i) {
    ll v = 0;

    char j = i;
    while (true) {
        if (visited.find(j) != visited.end()) {
            return j == i && v > 1;
        }

        if (p[j].size() > 1) return false;
        visited.insert(j);
        v++;

        j = c[j];
    }
}

ll solve() {
    c.clear();
    p.clear();
    visited.clear();

    N = s1.size();

    ll ans = 0;

    for (ll i = 0; i < N; i++) {
        if (c.find(s1[i]) == c.end()) {
            c[s1[i]] = s2[i];
            p[s2[i]].push_back(s1[i]);

            if (s1[i] != s2[i]) {
                ans++;
            }
        }
        else {
            return -1;
        }
    }

    ll noncycles = 0;
    ll cycles = 0;

    for (auto i: s1) {
        if (visited.find(i) == visited.end() && cycle(i)) {
            //cout << i << "\n";
            cycles++;
        }
    }

    return ans + cycles;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "230101";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> T;

    while (T--) {
        cin >> s1;
        cin >> s2;

        cout << solve() << "\n";
    }
	
	return 0;
}