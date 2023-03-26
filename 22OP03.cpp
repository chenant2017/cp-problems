#include <bits/stdc++.h>
#define MAX 200010
using namespace std;

typedef long long ll;
typedef pair<char, char> pc;

ll Q;
string s;
char prefix[MAX];

char op(char c1, char c2) {
    if (c1 == c2) return ' ';
    if (c1 == ' ') return c2;
    if (c2 == ' ') return c1;

    for (auto i: {'C', 'O', 'W'}) {
        if (i != c1 && i != c2) return i;
    }

    return ' ';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "22OP03";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> s;
    s = ' ' + s;

    prefix[0] = ' ';

    for (ll i = 1; i < s.size(); i++) {
        prefix[i] = op(prefix[i - 1], s[i]);
    }

    cin >> Q;
    
    while (Q--) {
        ll l, r;
        cin >> l >> r;

        if (op(prefix[r], prefix[l - 1]) == 'C') {
            cout << "Y";
        }
        else {
            cout << "N";
        }
    }

    cout << "\n";
	
	return 0;
}