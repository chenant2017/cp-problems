#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

typedef long long ll;

ll N;
ll A[MAXN];
ll sorted[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "sort";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
    cin >> N;

    for (ll i = 0; i < N; i++) {
        ll a;
        cin >> a;
        A[i] = a;
        sorted[i] = a;
    }

    sort(sorted, sorted + N);

    bool same = true;
    for (ll i = 0; i < N; i++) {
        if (sorted[i] != A[i]) {
            same = false;
            break;
        }
    }

    if (same) {
        cout << "1\n";
        return 0;
    }

    ll ans = 0;
    ll min = pow(10, 10);

    for (ll i = N - 1; i >= 0; i--) {
        if (A[i] < min) {
            min = A[i];

            ll greater = 0;

            for (ll j = 0; j < i; j++) {
                if (A[j] > A[i]) {
                    greater++;
                }
            }

            ans = max(ans, greater);
        }
    }

    cout << ans + 1 << "\n";
	
	return 0;
}