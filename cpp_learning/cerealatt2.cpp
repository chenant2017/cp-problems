#include <bits/stdc++.h>

#define ll long long
#define MAX 100010
#define f first
#define s second

using namespace std;

pair<ll, ll> faves[MAX];
ll N, M;
ll taken[MAX] = {0};
set<ll> faves1[MAX];
set<ll> faves2[MAX];

ll give(ll cow, ll cereal) {
	set<ll> &ff = faves1[cereal];
	while (!ff.empty() && *ff.begin() <= cow) {
		ff.erase(ff.begin());
	}

	if (ff.empty()) {
		set<ll> &fs = faves2[cereal];
		while (!fs.empty()) {
			if (*fs.begin() > cow && taken[faves[*fs.begin()].f] != *fs.begin()) {
				break;
			}
			fs.erase(fs.begin());
		}

		if (!fs.empty()) {
			taken[cereal] = *fs.begin();
			return 0;
		}
		else {
			return -1;
		}
	}
	else {
		taken[cereal] = *ff.begin();
		return give(*ff.begin(), faves[*ff.begin()].s);
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
		faves1[fave1].insert(i);
		faves2[fave2].insert(i);
	}


	ll ans = 0;

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
		ans += give(i, faves[i].f);
		cout << ans << "\n";
	}

	return 0;

}