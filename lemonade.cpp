#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

typedef long long ll;

ll N;
ll w[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "lemonade";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) {
        cin >> w[i];
    }

    sort(w, w + N, greater<ll>());

    ll ans = 0;

    for (ll i = 0; i < N; i++) {
        if (i <= w[i]) ans++;
    }

    cout << ans << "\n";
	
	return 0;
}