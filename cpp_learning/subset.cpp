#include <bits/stdc++.h>
#define MAX 100010
using namespace std;

typedef long long ll;

ll Q;
string s, t;
ll s_counts[26] = {0};
ll t_counts[26] = {0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "subset";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
    cin >> s >> t >> Q;

    for (char c: s) {
        s_counts[c - 'a']++;
    }
    for (char c: t) {
        t_counts[c - 'a']++;
    }
	
    for (ll i = 0; i < Q; i++) {
        string q;
        cin >> q;
        unordered_set<char> letters;
        bool works = true;
        for (char c: q) {
            if (s_counts[c - 'a'] != t_counts[c - 'a']) {
                works = false;
                break;
            }
            letters.insert(c);
        }
        if (!works) {
            cout << "N";
            continue;
        }
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