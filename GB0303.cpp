#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
string s1, s2;

ll solve_dp() {
    vector<ll> prev (s1.size(), 0);
    vector<ll> curr (s1.size(), 0);

    for (ll i = 1; i < s2.size(); i++) {
        for (ll j = 1; j < s1.size(); j++) {
            if (s2[i] == s1[j]) {
                curr[j] = 1 + prev[j - 1];
            }
            else {
                curr[j] = max(prev[j], curr[j - 1]);
            }
        }
        prev = curr;
    }

    return curr[s1.size() - 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GB0303";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> s1 >> s2;
    s1 = " " + s1;
    s2 = " " + s2;

    cout << solve_dp() << "\n";
	
	return 0;
}