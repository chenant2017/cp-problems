#include <bits/stdc++.h>
#define MAXM (long long) 1e5 + 10
#define MAXN (long long) 1e5 + 10
#define f first
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll T;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> T;

	for (ll t = 0; t < T; t++) {

		ll N, M;
		pll pairs[MAXM];
		ll unhapp[MAXN];
		ll member_of[MAXN] = {0};

		cin >> N >> M;

		for (ll i = 1; i <= N; i++) {
			cin >> unhapp[i];
		}

		for (ll i = 0; i < M; i++) {
			ll a, b;
			cin >> a >> b;
			pairs[i].f = a;
			pairs[i].s = b;
			member_of[a]++;
			member_of[b]++;
		}

		if (M % 2 == 0) {
			cout << "0\n";
			continue;
		}

		ll ans = (ll) 1e5;

		for (ll i = 1; i <= N; i++) {
			if (member_of[i] % 2 == 1) {
				if (unhapp[i] < ans) {
					ans = unhapp[i];
				}
			}
		}

		for (ll i = 0; i < M; i++) {
			if ((member_of[pairs[i].f] + member_of[pairs[i].s]) % 2 == 0) {
				ll sum = unhapp[pairs[i].f] + unhapp[pairs[i].s];
				if (sum < ans) {
					ans = sum;
				}
			}
		}

		cout << ans << "\n";
	}
	
	return 0;
}