#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll W, H, L1, L2;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GA1001";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> W >> H >> L1 >> L2;

    ll ans = 0;
    if (L1 == 1) ans += W * (H + 1) + H * (W + 1);

    for (ll dx = 1; dx <= W; dx++) {
        for (ll dy = 1; dy <= H; dy++) {
            double length = sqrt(pow(dx, 2) + pow(dy, 2));
            if (__gcd(dx, dy) == 1 && L1 <= length && length <= L2) {
                ans += 2 * (W - dx + 1) * (H - dy + 1);
            }
        }
    }

    cout << ans << "\n";
	
	return 0;
}