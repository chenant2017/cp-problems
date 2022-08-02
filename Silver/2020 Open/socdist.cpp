#include <bits/stdc++.h>
#include <cmath>

#define ll long long
#define MAXM 100010
#define f first
#define s second 

using namespace std;

ll N, M;
pair<ll, ll> grass[MAXM];

bool works(ll D) {
	if (D == 0) {
		return true;
	}

	ll pos = 0;
	ll placed = 0; //cows that've been placed

	for (ll i = 0; i < M; i++) {
		auto& g = grass[i];
		if (pos > g.s) {
			continue;
		}

		if (pos < g.f) {
			pos = g.f;
		}

		placed += (g.s - pos) / D + 1;

		pos += D * ((g.s - pos) / D + 1);
	}

	return placed >= N;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "socdist";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;

	for (ll i = 0; i < M; i++) {
		cin >> grass[i].f >> grass[i].s;
	}

	sort(grass, grass + M);

	ll minptr = 0;
	ll maxptr = (grass[M - 1].s) / (N - 1) + 5;

	while (maxptr - minptr > 1) {
		ll mid = (minptr + maxptr) / 2;
		if (works(mid)) {
			minptr = mid;
		}
		else {
			maxptr = mid;
		}
	}

	cout << minptr << "\n";

	return 0;
}