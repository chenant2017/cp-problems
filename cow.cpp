#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<char, char> pc;

string chars = " COW";
map<pc, char> op;
string s;
ll Q;
string prefix;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "cow";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);

    for (ll i = 0; i < 4; i++) {
        for (ll j = 0; j < 4; j++) {
            char c1 = chars[i], c2 = chars[j];
            char result;

            if (c1 == c2) {
                result = ' ';
            }
            else if (c1 == ' ') {
                result = c2;
            }
            else if (c2 == ' ') {
                result = c1;
            }
            else {
                for (ll k = 1; k <= 3; k++) {
                    if (c1 != chars[k] && c2 != chars[k]) {
                        result = chars[k];
                    }
                }
            }

            op[{c1, c2}] = result;

            //cout << c1 << "," << c2 << "," << result << "\n";
        }
    }
	
    prefix = " ";

	cin >> s;

    for (ll i = 1; i <= s.size(); i++) {
        prefix += op[{prefix[i - 1], s[i - 1]}];
    }

    //cout << prefix << " prefix\n";

    cin >> Q;

    for (ll i = 0; i < Q; i++) {
        ll l, r;
        cin >> l >> r;

        char result = op[{prefix[r], prefix[l - 1]}];
        if (result == 'C') {
            cout << "Y";
        }
        else {
            cout << "N";
        }
    }

    cout << "\n";
	
	return 0;
}