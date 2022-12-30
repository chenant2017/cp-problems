#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GB1004";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> s;

    stack<ll> unbalanced;

    ll ans = 0;

    for (ll i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            unbalanced.push(1);
        }
        else {
            if (unbalanced.empty()) {
                ans++;
                unbalanced.push(1);
            }
            else {
                unbalanced.pop();
            }
        }
    }

    ans += unbalanced.size() / 2;

    cout << ans << "\n";
	
	return 0;
}