#include <bits/stdc++.h>
#define MAX 50010
#define MAXB ((ll) 1e6 + 10)
using namespace std;

typedef long long ll;

ll N, K;
ll counts[MAXB];
ll breeds[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "proximity";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> K;

    for (ll i = 0; i < N; i++) {
        cin >> breeds[i];
    }

    for (ll i = 0; i <= K; i++) {
        counts[breeds[i]]++;
    }

    ll ans = -1;

    if (counts[breeds[0]] > 1) {
        ans = max(ans, breeds[0]);
    }

    for (ll i = 1; i < N; i++) {
        counts[breeds[i - 1]]--;

        if (i + K < N) {
            counts[breeds[i + K]]++;
        }

        if (counts[breeds[i]] > 1) {
            ans = max(ans, breeds[i]);
        }
    }

    cout << ans << "\n";
	
	return 0;
}