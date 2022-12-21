#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s1, s2;

ll solve_dp() {
    vector<ll> prev (s2.size() + 1);
    for (ll i = 0; i <= s2.size(); i++) {
        prev[i] = i;
    }
    vector<ll> curr (s2.size() + 1, 0);

    for (ll i = 1; i <= s1.size(); i++) {
        curr[0] = i;
        for (ll j = 1; j <= s2.size(); j++) {
            curr[j] = min({curr[j - 1], prev[j], prev[j - 1]}) + 1;
            
            if (s1[i - 1] == s2[j - 1]) {
                curr[j] = min(curr[j], prev[j - 1]);
            }
            //cout << i << " " << j << " " << curr[j] << "\n";
        }
        prev = curr;
    }

    return curr[s2.size()];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GB0304";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> s1 >> s2;
	
    cout << solve_dp() << "\n";

	return 0;
}