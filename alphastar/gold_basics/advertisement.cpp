#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll W, H, L1, L2;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "advertisement";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> W >> H >> L1 >> L2;

    ll ans = 0;

    for (ll i = 0; i <= H; i++) { //vert
        for (ll j = 0; j <= W; j++) { //horiz
            if (i == 0 && j == 0) continue;
            double l;
            //cout << i << " " << j << "\n";
            if (i + j == 1) {
                l = i + j;
                if (L1 <= l && l <= L2) {
                    ans += (H - i + 1) * (W - j + 1);
                    //cout << (H - i + 1) * (W - j + 1) << "\n";
                }
            }
            else if (__gcd(i, j) == 1) {
                l = sqrt(pow(i, 2) + pow(j, 2));
                //cout << "l is " << l << "\n";
                if (L1 <= l && l <= L2) {
                    ans += 2 * (H - i + 1) * (W - j + 1);
                    //cout << 2 * (H - i + 1) * (W - j + 1) << "\n";
                }
            }
            else {
                l = -1;
            }
            
        }
    }

    cout << ans << "\n";
	
	return 0;
}