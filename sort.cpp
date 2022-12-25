#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

typedef long long ll;

ll N;
ll A[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "sort";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
    cin >> N;

    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }

    ll ans = 0;

    for (ll i = 1; i < N; i++) {
        ll greater = 0;
        for (ll j = 0; j < i; j++) {
            if (A[j] > A[i]) {
                greater++;
            }
        }
        ans = max(ans, greater);
    }

    cout << ans + 1 << "\n";
	
	return 0;
}