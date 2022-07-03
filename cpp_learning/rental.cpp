#include <bits/stdc++.h>

#define ll long long
#define MAX 100010
#define f first
#define s second

using namespace std;

ll N, M, R;
ll cows[MAX];
pair<ll, ll> stores[MAX];
ll rentals[MAX];

vector<ll> get_profit(ll gallons, ll ptrM, ll remM) {
	ll profit = 0;

	while (gallons > 0 && ptrM < M) {
		if (gallons <= remM) {
			remM -= gallons;
			profit += gallons * stores[ptrM].s;

			if (remM == 0) {
				ptrM++;
				if (ptrM < M) {
					remM = stores[ptrM].f;
				}
			}

			gallons = 0;
		}
		else {
			gallons -= remM;
			profit += remM * stores[ptrM].s;
			ptrM++;
			if (ptrM < M) {
				remM = stores[ptrM].f;
			}
		}
	}
	vector<ll> result;
	result.push_back(profit);
	result.push_back(ptrM);
	result.push_back(remM);

	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "rental";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M >> R;

	for (ll i = 0; i < N; i++) {
		cin >> cows[i];
	}

	for (ll i = 0; i < M; i++) {
		cin >> stores[i].f >> stores[i].s;
	}

	for (ll i = 0; i < R; i++) {
		cin >> rentals[i];
	}

	sort(cows, cows + N);
	sort(stores, stores + M, [](auto& a, auto& b) {
		return a.s > b.s;
	});
	sort(rentals, rentals + R, greater<ll>());
	rentals[R] = 0;

	ll ptr1 = 0;
	ll ptr2 = N - 1;
	ll ptrM = 0;
	ll remM = stores[0].f;
	ll ptrR = 0;

	ll ans = 0;

	while (ptr1 != ptr2) {
		vector<ll> gp = get_profit(cows[ptr2], ptrM, remM);
		if (gp[0] > rentals[ptrR]) {
			ans += gp[0];
			ptr2--;
			ptrM = gp[1];
			remM = gp[2];
		}
		else {
			ans += rentals[ptrR];
			ptr1++;
			if (ptrR < R) {
				ptrR++;
			}
		}
	}

	vector<ll> gp = get_profit(cows[ptr1], ptrM, remM);
	if (gp[0] > rentals[ptrR]) {
		ans += gp[0];
	}
	else {
		ans += rentals[ptrR];
	}

	cout << ans << "\n";

	return 0;
}