#include <bits/stdc++.h>
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<char, char> pc;

ll Q;
string s, t, q;
set<pc> valids;

bool valid(pc p) {
    string u = "";
    string v = "";

    for (ll i = 0; i < s.size(); i++) {
        if (p.f == s[i] || p.s == s[i]) {
            u += s[i];
        }
        if (p.f == t[i] || p.s == t[i]) {
            v += t[i];
        }
    }

    return u == v;
}

ll count(char c, string str) {
    ll result = 0;

    for (auto i: str) {
        result += i == c;    
    }

    return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "22OP02";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> s >> t;

    for (char c1 = 'a'; c1 < 'r'; c1++) {
        for (char c2 = c1 + 1; c2 <= 'r'; c2++) {
            if (valid({c1, c2})) {
                valids.insert({c1, c2});
            }
        }
    }

    //cout << valids.size() << endl;

    cin >> Q;

    while (Q--) {
        cin >> q;  

        bool result = true;

        if (q.size() != 1) {
            for (ll i = 0; i < q.size() - 1; i++) {
                for (ll j = i + 1; j < q.size(); j++) {
                    if (valids.find({q[i], q[j]}) == valids.end()) {
                        result = false;
                        break;
                    }
                }
            }
        }
        else {
            result = count(q[0], s) == count(q[0], t);
        }

        if (result) {
            cout << "Y";
        }
        else {
            cout << "N";
        }
    }    

    cout << "\n";
	
	return 0;
}