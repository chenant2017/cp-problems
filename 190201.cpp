#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

typedef long long ll;

ll N;
vector<ll> cows;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "herding";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    cows.resize(N);

    for (ll i = 0; i < N; i++) {
        cin >> cows[i];
    }

    sort(cows.begin(), cows.end());

    ll ans2 = max(cows[N - 2] - cows[0], cows[N - 1] - cows[1]) + 2 - N;
    ll ans1 = 1e18;

    for (ll i = 0; i < N; i++) {
        if (cows[i] + N - 1 > cows[N - 1]) break;

        auto it = upper_bound(cows.begin(), cows.end(), cows[i] + N - 1);
        it--;

        ll j = distance(cows.begin(), it);

        ll count = j - i + 1;
        
        if (count == cows[j] - cows[i] + 1 && N - j == 1) {
            ans1 = min(ans1, N - count + 1);
        }
        else {
            ans1 = min(ans1, N - count);
        }
    }

    cout << ans1 << "\n";
    cout << ans2 << "\n";
	
	return 0;
}