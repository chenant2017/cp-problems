#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll Q, N;
string s;

char add(char a, char b) {
    if (a > b) swap(a, b);

    if (a == b) return ' ';
    if (a == 'C' && b == 'W') return 'O';
    if (a == 'O' && b == 'W') return 'C';
    if (a == 'C' && b == 'O') return 'W';
    if (a == ' ') return b;
    return ' ';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "cow";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
    cin >> s;
    N = s.size();
    s = " " + s;
    //cout << s << "\n";

    string prefix = string(s.size(), ' ');
    for (ll i = 1; i <= N; i++) {
        prefix[i] = add(prefix[i - 1], s[i]);
    }

    cin >> Q;

    for (ll i = 0; i < Q; i++) {
        ll a, b;
        cin >> a >> b;
        if (prefix[b] == add('C', prefix[a - 1])) cout << 'Y';
        else cout << 'N';
    }

    cout << "\n";
	
	return 0;
}