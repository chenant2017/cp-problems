#include <bits/stdc++.h>
#define MAX 100010
using namespace std;

typedef long long ll;

ll N, M, T;
ll a[MAX];
map<ll, ll> counts;

void factors(ll n, ll d) {
    for (ll i = 1; i <= sqrt(n) && i <= M; i++) {
        if (n % i == 0) {
            counts[i] += d;

            if (counts[i] == 0) {
                counts.erase(i);
            }

            if (i != sqrt(n) && n / i <= M) {
                counts[n / i] += d;
                if (counts[n / i] == 0) {
                    counts.erase(n / i);
                }
            }
        }
    }
}

ll solve() {
    //cout << "new\n";
    ll ans = 1e18;

    ll ptr2 = -1;

    for (ll ptr1 = 0; ptr1 < N; ptr1++) {
        while (ptr2 + 1 < N && counts.size() < M) {
            ptr2++;
            factors(a[ptr2], 1);
        }
        if (counts.size() < M) break;
        //cout << ptr1 << " " << ptr2 << "\n";
        ans = min(ans, a[ptr2] - a[ptr1]);
        factors(a[ptr1], -1);
    }

    if (ans == 1e18) return -1;
    return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "1777C";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> T;

    while (T--) {
        counts.clear();

        cin >> N >> M;

        for (ll i = 0; i < N; i++) {
            cin >> a[i];
        }

        sort(a, a + N);

        cout << solve() << "\n";
    }
	
	return 0;
}