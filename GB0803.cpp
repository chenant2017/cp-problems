#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N, K;

vector<ll> centers;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GB0803";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
    cin >> N >> K;

    for (ll i = 0; i < K; i++) {
        ll t;
        cin >> t;
        centers.push_back(N - t);
    }

    sort(centers.begin(), centers.end());

    ll ans = max(centers[0], N - centers[K - 1]);

    for (ll i = 0; i < K - 1; i++) {
        ans = max(ans, (centers[i + 1] - centers[i]) / 2);
    }

    cout << ans << "\n";
	
	return 0;
}