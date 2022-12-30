#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s;
string t;
ll Q;

bool pairwise[20][20] = {false};

bool check_pair(char c1, char c2) {
    string u = "";
    string v = "";

    for (auto i: s) {
        if (i == c1 || i == c2) u += i;
    }

    for (auto i: t) {
        if (i == c1 || i == c2) v += i;
    }

    return u == v;
}

bool check_one(char c) {
    string u = "";
    string v = "";

    for (auto i: s) {
        if (i == c) u += i;
    }

    for (auto i: t) {
        if (i == c) v += i;
    }

    return u == v;
}

bool check_query(string q) {
    if (q.size() == 1) {
        return check_one(q[0]);
    }
    for (ll i = 0; i < q.size() - 1; i++) {
        for (ll j = i + 1; j < q.size(); j++) {
            if (!pairwise[q[i] - 'a'][q[j] - 'a']) return false;        
        }
    }
    return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "subset";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> s;
    cin >> t;

    for (char c1 = 'a'; c1 < 'r'; c1++) {
        for (char c2 = c1 + 1; c2 <= 'r'; c2++) {
            if (check_pair(c1, c2)) {
                pairwise[c1 - 'a'][c2 - 'a'] = true;
                pairwise[c2 - 'a'][c1 - 'a'] = true;
            }
        }
    }

    cin >> Q;

    /*for (ll i = 0; i < 4; i++) {
        for (ll j = 0; j < 4; j++) {
            cout << (ll) pairwise[i][j] << " ";
        }
        cout << "\n";
    }*/

    string q;
    for (ll i = 0; i < Q; i++) {
        cin >> q;
        if (check_query(q)) {
            cout << "Y";
        }
        else {
            cout << "N";
        }
    }
    cout << "\n";
	
	return 0;
}