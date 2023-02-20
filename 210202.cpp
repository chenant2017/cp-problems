#include <bits/stdc++.h>
#define MAXN 70000
using namespace std;

typedef long long ll;

ll N, K;
ll years[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "210202";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> K;

    for (ll i = 0; i < N; i++) {
        cin >> years[i];
    }

    sort(years, years + N);

    priority_queue<ll> savings;

    for (ll i = 0; i < N - 1; i++) {
        ll lower = 12 * (years[i] / 12 + 1);
        ll upper = 12 * (years[i + 1] / 12);
        if (lower >= years[i] && upper <= years[i + 1]) {
            savings.push(upper - lower);
        }
    }

    savings.push(12 * (years[0] / 12));

    ll ans = 12 * (years[N - 1] / 12 + 1);

    ll count = 0;
    while (count < K - 1 && !savings.empty()) {
        ans -= savings.top();
        savings.pop();
        count++;
    }
	
    cout << ans << "\n";

	return 0;
}