#include <bits/stdc++.h>
#define MAXN 50010
using namespace std;

typedef long long ll;

ll N, K;
ll diamonds[MAXN];
ll start_from[MAXN];
ll max_from[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "diamond";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> K;

    for (ll i = 0; i < N; i++) {
        cin >> diamonds[i];
    }

    sort(diamonds, diamonds + N);

    ll ptr2 = 0;

    for (ll ptr1 = 0; ptr1 < N; ptr1++) {
        while (ptr2 + 1 < N && diamonds[ptr2 + 1] <= diamonds[ptr1] + K) {
            ptr2++;
        }
        start_from[ptr1] = ptr2 - ptr1 + 1;
    }

    ll curr_max = 0;

    for (ll i = N - 1; i >= 0; i--) {
        curr_max = max(curr_max, start_from[i]);
        max_from[i] = curr_max;
    }
    
    ll ans = 0;

    for (ll i = 0; i < N; i++) {
        ll poss = start_from[i];
        if (i + start_from[i] < N) {
            poss += max_from[i + start_from[i]];
        }
        ans = max(ans, poss);
    }
	
    cout << ans << "\n";

	return 0;
}