#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll X, Y;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "odometer";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> X >> Y;

    ll digitsX = log10(X) + 1;
    ll digitsY = log10(Y) + 1;

    ll ans = 0;

    for (ll digits = 1; digits <= 17; digits++) {
        for (ll i = 1; i <= 9; i++) {
            ll a = i * pow(10, digits - 1);
            if (X <= a && a <= Y) {
                //cout << a << "\n";
                ans++;
            }
        }

        for (ll i = 1; i <= 9; i++) {
            for (ll unique = 0; unique <= 9; unique++) {
                for (ll loc = 0; loc < digits; loc++) {
                    if (loc == 0 && unique == 0) continue;
                    if (i == unique) continue;

                    string num = string();

                    for (ll j = 0; j < digits; j++) {
                        if (j == loc) {
                            num += to_string(unique);
                        }
                        else {
                            num += to_string(i);
                        }
                    }

                    ll a = stoll(num);

                    if (X <= a && a <= Y) {
                        //cout << a << "\n";
                        ans++;
                    }
                }
            }
        }
    }
    
    cout << ans << "\n";
	
	return 0;
}