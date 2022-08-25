#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll Q;
string s, t;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "subset";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
    cin >> s >> t >> Q;
	
    for (ll i = 0; i < Q; i++) {
        string q;
        cin >> q;
        unordered_set<char> letters;
        for (char c: q) letters.insert(c);
        string s_mod = string();
        for (char c: s) {
            if (letters.find(c) != letters.end()) s_mod += c;
        }
        string t_mod = string();
        for (char c: t) {
            if (letters.find(c) != letters.end()) t_mod += c;
        }
        cout << (s_mod == t_mod ? "Y":"N");
    }
    cout << "\n";

	return 0;
}