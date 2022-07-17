#include <bits/stdc++.h>

#define ll long long
#define f first
#define s second
#define MAX 260

using namespace std;

ll N, B;
ll snow[MAX];
pair<ll, ll> boots[MAX];
ll ends2[MAX][MAX] = {0};

void get_ends2(ll b) {
	ll last_good = 0;
	for (ll i = 0; i <= boots[b].s; i++) {
		if (boots[b].f >= snow[i]) {
			last_good = i;
		}
	}	
	ends2[b][0] = last_good;

	for (ll i = 1; i < N - boots[b].s; i++) {
		if (last_good < i) {
			last_good = i;
		}
		if (boots[b].f >= snow[i + boots[b].s]) {
			last_good = i + boots[b].s;
		}

		ends2[b][i] = last_good;
	}

	for (ll i = N - boots[b].s; i < N; i++) {
		if (last_good < i) {
			ends2[b][i] = i;
		}
		else {
			ends2[b][i] = last_good;
		}	
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "snowboots";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);

	cin >> N >> B;

	for (ll i = 0; i < N; i++) {
		cin >> snow[i];
	}

	for (ll i = 0; i < B; i++) {
		cin >> boots[i].f >> boots[i].s;
		get_ends2(i);
	}

	ll pos = 0;
	ll ans = 0;
	for (ll i = 0; i < B; i++) {
		if (boots[i].f < snow[pos]) {
			ans++;
			continue;
		}

		while (boots[i].f >= snow[pos] && pos != ends2[i][pos]) {
			pos = ends2[i][pos];
		}
		//cout << pos << " is pos\n";
		if (pos == N - 1) break;

		ans++;
	}

	cout << ans << "\n";

	return 0;
}