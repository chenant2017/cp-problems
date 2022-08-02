#include <bits/stdc++.h>

#define ll long long
#define MAXN 1010
#define f first
#define s second

using namespace std;

struct Cow {
	ll x, y, id;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "balancing";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	ll N;
	cin >> N;

	Cow cows[MAXN];
	pair<ll, ll> rel_locs[MAXN];
	ll rel_prefix[MAXN][MAXN] = {0};
	
	for (ll i = 0; i < N; i++) {
		cin >> cows[i].x >> cows[i].y;
		cows[i].id = i;
	}

	sort(cows, cows + N, [](auto& c1, auto& c2) {
		return c1.x < c2.x || (c1.x == c2.x && c1.y < c2.y);
	});

	ll xi = 1;
	rel_locs[cows[0].id].f = 1;

	for (ll i = 1; i < N; i++) {
		if (cows[i].x != cows[i - 1].x) {
			xi++;
		}
		rel_locs[cows[i].id].f = xi;
	}

	sort(cows, cows + N, [](auto& c1, auto& c2) {
		return c1.y < c2.y || (c1.y == c2.y && c1.x < c2.x);
	});

	ll yi = 1;
	rel_locs[cows[0].id].s = 1;

	for (ll i = 1; i < N; i++) {
		if (cows[i].y != cows[i - 1].y) {
			yi++;
		}
		rel_locs[cows[i].id].s = yi;
	}

	for (ll i = 0; i < N; i++) {
		rel_prefix[rel_locs[i].f][rel_locs[i].s] = 1;
	}

	for (ll i = 1; i <= N; i++) {
		for (ll j = 1; j <= N; j++) {
			rel_prefix[i][j] += rel_prefix[i][j - 1];
		}
	}

	for (ll j = 1; j <= N; j++) {
		for (ll i = 1; i <= N; i++) {
			rel_prefix[i][j] += rel_prefix[i - 1][j];
		}
	}

	ll ans = MAXN;

	for (ll a = 1; a <= N; a++) {
		for (ll b = 1; b <= N; b++) {
			ll M = 0;

			ll q1 = rel_prefix[a][N] - rel_prefix[a][b];
			ll q2 = rel_prefix[a][b];
			ll q3 = rel_prefix[N][b] - rel_prefix[a][b];
			ll q4 = rel_prefix[N][N] - rel_prefix[a][N] - rel_prefix[N][b] + rel_prefix[a][b];

			if (q1 > M) M = q1;
			if (q2 > M) M = q2;
			if (q3 > M) M = q3;
			if (q4 > M) M = q4;

			if (M < ans) {
				ans = M;
			}
		}
	}

	cout << ans << "\n";

	return 0;
}