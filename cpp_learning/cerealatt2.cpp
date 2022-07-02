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

	auto &ff = faves1[cereal];
	if (ff.empty()) {
		auto &fs = faves2[cereal];
		if (fs.empty()) {
			taken[cereal] = 0;
			//cout << cereal << " is no longer taken\n";
			return -1;
		}
		else {
			for (auto i: fs) {
				if (taken[faves[i].f] != i) {
					taken[cereal] = i;
					//cout << i << " took " << cereal << " a\n";
					return 0;
				}
			}
			return -1;
		}	
	}
	else {
		taken[cereal] = ff.front();
		//cout << ff.front() << " took " << cereal << " b\n";
		if (taken[faves[ff.front()].s] == ff.front()) {
			return give(ff.front(), faves[ff.front()].s);
		}
		return 0;
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

		ans += give(i, faves[i].f);
		cout << ans << "\n";
	}

	return 0;

}