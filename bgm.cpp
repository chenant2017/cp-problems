#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N;
map<char, vector<ll>> counts;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "bgm";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);

    cin >> N;

    vector<char> vars = {'B','E','S','I','G','O','M'};

    for (auto v: vars) {
        counts[v] = vector<ll>(7, 0);
    }

    for (ll i = 0; i < N; i++) {
        char var; ll val;
        cin >> var >> val;
        counts[var][(val + 700000) % 7]++;
    }

    ll ans = 0;
	
	for (ll b = 0; b < 7; b++) {
        for (ll e = 0; e < 7; e++) {
            for (ll s = 0; s < 7; s++) {
                for (ll i = 0; i < 7; i++) {
                    for (ll g = 0; g < 7; g++) {
                        for (ll o = 0; o < 7; o++) {
                            for (ll m = 0; m < 7; m++) {
                                ll exp = (b + e + s + s + i + e) * 
                                         (g + o + e + s) *
                                         (m + o + o);
                                if (exp % 7 == 0) {
                                    ans += counts['B'][b] *
                                           counts['E'][e] *
                                           counts['S'][s] *
                                           counts['I'][i] *
                                           counts['G'][g] *
                                           counts['O'][o] *
                                           counts['M'][m];
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << ans << "\n";
	
	return 0;
}