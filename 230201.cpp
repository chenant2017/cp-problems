#include <bits/stdc++.h>
#define MAX 110
using namespace std;

typedef long long ll;

ll a[MAX];
ll b[MAX];
ll c[MAX];

ll T, N, C, M;

bool works(ll m) {
    if (m < 0) return false;

    ll all_lower = -1e18;
    ll all_higher = 1e18;

    for (ll i = 0; i < N; i++) {
        ll r = a[i] * C + b[i] * M - c[i];

        if (a[i] == b[i]) {
            all_lower = max(all_lower, 0ll);
            all_higher = min(all_higher, C - 1);

            if (b[i] * m < r) return false;
        }
        else if (a[i] > b[i]) {
            ll lower = ceil( ((double) (r - b[i] * m)) / (a[i] - b[i]) );

            lower = max(lower, max(m - M + 1, 0ll));
            ll higher = min(C - 1, m);

            all_higher = min(all_higher, higher);
            all_lower = max(all_lower, lower);

            if (higher < lower) return false;
        }
        else {
            ll higher = floor( ((double) (r - b[i] * m)) / (a[i] - b[i]) );

            higher = min(higher, min(C - 1, m));

            ll lower = max(m - M + 1, 0ll);

            all_lower = max(all_lower, lower);
            all_higher = min(all_higher, higher);

            if (higher < lower) return false;
        }
    }

    if (all_higher < all_lower) return false;

    return true;
}

ll solve() {
    ll low = -1; 
    ll high = M - 1 + C - 1;

    while (high - low > 1) {
        ll mid = (high + low) / 2;

        if (works(mid)) {
            //cout << mid << "\n";
            high = mid;
        }
        else {
            low = mid;
        }
    }

    return high;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "230201";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> T;

    while (T--) {
        cin >> N >> C >> M;

        for (ll i = 0; i < N; i++) {
            cin >> a[i] >> b[i] >> c[i];
        }

        cout << solve() << "\n";
    }
	
	return 0;
}