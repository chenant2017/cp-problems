#include <bits/stdc++.h>
#define MAX 1000010
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N, M, R;
ll G = 0;

ll c[MAX];
pll buys[MAX];
ll rents[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "rental";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M >> R;

    for (ll i = 1; i <= N; i++) {
        cin >> c[i];
    }

    sort(c + 1, c + N + 1);

    for (ll i = 0; i < M; i++) {
        ll q, p;
        cin >> q >> p;
        buys[i] = {p, q};
    }

    sort(buys, buys + M, greater<pll>());

    for (ll i = 1; i <= R; i++) {
        cin >> rents[i];
    }

    sort(rents + 1, rents + R + 1, greater<ll>());

    ll ans = 0;
    ll ptr = 0;
    ll total = 0;

    for (ll i = 1; i <= min(N, R); i++) {
        total += rents[i];
    }

    //cout << total << "\n";

    for (ll i = N; i >= 1; i--) { 
        if (i <= R) {
            total -= rents[i];
            //cout << "down " << rents[i] << "\n";
        }

        ll up = 0;

        //cout << ptr << " " << buys[ptr].first << " " << buys[ptr].second << " ptr\n";
        //cout << c[i] << " c[i]\n";

        while (c[i] > 0 && ptr < M) {
            if (buys[ptr].second > c[i]) {
                buys[ptr].second -= c[i];
                total += c[i] * buys[ptr].first;
                up += c[i] * buys[ptr].first;
                c[i] = 0;
            }
            else {
                total += (buys[ptr].second) * buys[ptr].first;
                up += (buys[ptr].second) * buys[ptr].first;
                c[i] -= buys[ptr].second;
                buys[ptr].second = 0;
                ptr++;
            }
        }

        //cout << "up " << up << "\n";

        //cout << total << "\n";

        ans = max(ans, total);
    }

    cout << ans << "\n";

	return 0;
}