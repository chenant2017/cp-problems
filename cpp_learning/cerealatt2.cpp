#include <bits/stdc++.h>

#define ll long long
#define MAX 100010
#define f first
#define s second

using namespace std;

pair<ll, ll> faves[MAX];
ll N, M;
ll taken[MAX] = {0};
list<ll> faves1[MAX];
list<ll> faves2[MAX];

ll give(ll cow, ll cereal) {
	if (cow == N) {
		return -1;
	}

	ll cow1 = N + 5;
	ll cow2 = N + 5;

	auto &ff = faves1[cereal];
	if (!ff.empty()) {
		cow1 = ff.front();
	}

	auto &fs = faves2[cereal];
	for (auto i: fs) {
		if (taken[faves[i].f] != i) {
			cow2 = i;
			break;
		}
	}

	ll cow3 = min(cow1, cow2);

	if (cow3 <= N) {
		taken[cereal] = cow3;
		if (cow3 == cow1) {
			if (taken[faves[cow3].s] == cow3) {
				taken[faves[cow3].s] = 0;
				return give(cow3, faves[cow3].s);
			}
			return 0;
		}	
		else {
			return 0;
		}
	}
	else {
		return -1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "cereal";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;

	for (ll i = 1; i <= N; i++) {
		ll fave1, fave2;
		cin >> fave1 >> fave2;
		pair<ll, ll> fave = pair<ll, ll>({fave1, fave2});
		faves[i] = fave;
		faves1[fave1].push_back(i);
		faves2[fave2].push_back(i);
	}


	ll ans = 0;

	faves2[faves[1].s].pop_front();

	for (ll i = 1; i <= N; i++) {
		if (taken[faves[i].f] != 0) {
			if (taken[faves[i].s] == 0) {
				taken[faves[i].s] = i;
				ans++;
			}
		}
		else {
			taken[faves[i].f] = i;
			ans++;
		}
	}

	cout << ans << "\n";

	for (ll i = 1; i <= N - 1; i++) {
		faves1[faves[i].f].pop_front();
		faves2[faves[i + 1].s].pop_front();

		taken[faves[i].f] = 0;

		ans += give(i, faves[i].f);
		cout << ans << "\n";
	}

	return 0;

}