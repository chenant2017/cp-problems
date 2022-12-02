#include <bits/stdc++.h>
#define MAX 100010
using namespace std;

typedef long long ll;

ll Q;
string s, t;
ll s_counts[26] = {0};
ll t_counts[26] = {0};

//Using breaks helps get partial credit.

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

        ll tptr = 0;

        for (ll j = 0; j < s.size(); j++) {
            if (letters.find(s[j]) != letters.end()) {
                while (tptr < t.size() && letters.find(t[tptr]) == letters.end()) {
                    tptr++;
                }
                if (tptr == t.size() || t[tptr] != s[j]) {
                    works = false;
                    break;
                }
                tptr++;
            }
        }
        cout << (works ? "Y":"N");
    }
    cout << "\n";

	return 0;
}