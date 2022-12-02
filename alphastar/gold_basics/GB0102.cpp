#include <bits/stdc++.h>
#define MAXN 20010
using namespace std;

typedef long long ll;

ll N;
ll sequence[MAXN];
ll longest[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GB0102";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) {
        cin >> sequence[i];
    }

    longest[0] = 1;

    for (ll i = 1; i < N; i++) {
        longest[i] = 1;
        for (ll j = 0; j < i; j++) {
            if (sequence[j] < sequence[i]) {
                longest[i] = max(longest[i], longest[j] + 1);
            }
        }
    }

    ll ans = 0;
    for (ll i = 0; i < N; i++) {
        ans = max(ans, longest[i]);
    }

    cout << ans << "\n";
	
	return 0;
}