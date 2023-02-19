#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N;
ll a, b;

ll solve() {
    vector<ll> va, vb;

    va.push_back(a);
    while (a > 1) {
        if (a % 2 == 0) {
            a /= 2;
        }
        else {
            a++;
        }
        va.push_back(a);
    }

    vb.push_back(b);
    while (b > 1) {
        if (b % 2 == 0) {
            b /= 2;
        }
        else {
            b--;
        }
        vb.push_back(b);
    }

    ll ans = 1e18;

    for (ll i = 0; i < va.size(); i++) {
        for (ll j = 0; j < vb.size(); j++) {
            if (vb[j] < va[i]) break;
            ans = min(ans, vb[j] - va[i] + i + j);
        }
    }

    return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "220101";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    while (N--) {
        cin >> a >> b;
        cout << solve() << "\n";
    }
	
	return 0;
}