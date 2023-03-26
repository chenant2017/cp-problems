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
    }

    for (ll i = 0; i < t.size(); i++) {
        if (p.f == t[i] || p.s == t[i]) {
            v += t[i];
        }
    }

    return u == v;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "22OP02";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> s >> t;

    for (char c1 = 'a'; c1 <= 'r'; c1++) {
        for (char c2 = c1; c2 <= 'r'; c2++) {
            if (valid({c1, c2})) {
                valids.insert({c1, c2});
                //cout << c1 << " " << c2 << endl;
            }
        }
    }

    cin >> Q;

    while (Q--) {
        cin >> q;  

        bool result = true;

        for (ll i = 0; i < q.size(); i++) {
            for (ll j = i; j < q.size(); j++) {
                if (valids.find({q[i], q[j]}) == valids.end()) {
                    //cout << q[i] << " " << q[j] << endl;
                    result = false;
                    break;
                }
            }
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