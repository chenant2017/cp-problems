#include <bits/stdc++.h>

#define ll long long
#define MAXN 55
#define f first
#define s second

using namespace std;
ll N;
pair<ll, ll> cows[MAXN];
vector<ll> ecows;
vector<ll> ncows;
ll ans[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
		
	cin >> N;

	for (ll i = 0; i < N; i++) {
		string dir;
		ll x, y;
		cin >> dir >> x >> y;

		cows[i] = pair<ll, ll>({x, y});

		if (dir[0] == 'E') {
			ecows.push_back(i);
		}
		else {	
			ncows.push_back(i);
		}
	}

	sort(ncows.begin(), ncows.end(), [](auto a, auto b) {
		return cows[a].f < cows[b].f;
	});

	sort(ecows.begin(), ecows.end(), [](auto a, auto b) {
		return cows[a].s < cows[b].s;
	});

	for (ll i = 0; i < N; i++) {
		ans[i] = -1;
	}

	for (auto i: ncows) {
		for (auto j: ecows) {
			if (ans[j] != -1 || ans[i] != -1) {
				continue;
			}


			ll disti = cows[j].s - cows[i].s;
			ll distj = cows[i].f - cows[j].f;

			if (disti > 0 && distj > 0) {
				if (distj > disti) {
					ans[j] = distj;
				}
				else if (disti > distj) {
					ans[i] = disti;
				}
			}

		}
	}

	for (ll i = 0; i < N; i++) {
		if (ans[i] == -1) {
			cout << "Infinity\n";
		}
		else {
			cout << ans[i] << "\n";
		}
	}

	return 0;
}