//2020 Silver Dec #2

#include <bits/stdc++.h>

#define ll long long
#define f first
#define s second
#define MAXN 2510

using namespace std;

ll N;
ll cows[MAXN][MAXN] = {0};
pair<ll, ll> points[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N;

	for (ll i = 0; i < N; i++) {
		cin >> points[i].f >> points[i].s;
	}

	sort(points, points + N);
	ll x = 1;
	for (ll i = 0; i < N; i++) {
		points[i].f = x;
		x++;
	}

	sort(points, points + N, [](auto& a, auto& b) {
		return a.s < b.s || (a.s == b.s && a.f < b.f);
	});
	ll y = 1;
	for (ll i = 0; i < N; i++) {
		points[i].s = y;
		y++;
	}

	for (ll i = 0; i < N; i++) {
		cows[points[i].f][points[i].s] = 1;
	}

	for (ll i = 1; i <= N; i++) {
		for (ll j = 2; j <= N; j++) {
			cows[i][j] += cows[i][j - 1];
		}
	}

	for (ll j = 1; j <= N; j++) {
		for (ll i = 2; i <= N; i++)  {
			cows[i][j] += cows[i - 1][j];
		}
	}

	ll ans = 0;

	for (ll i = 0; i < N - 1; i++) {
		for (ll j = i + 1; j < N; j++) {
			ll minf = min(points[i].f, points[j].f);
			ll maxf = max(points[i].f, points[j].f);
			ll mins = min(points[i].s, points[j].s);
			ll maxs = max(points[i].s, points[j].s);

			ll left = cows[maxf][mins - 1] - cows[minf - 1][mins - 1];
			ll right = cows[maxf][N] - cows[maxf][maxs] - cows[minf - 1][N] + 
					   cows[minf - 1][maxs];

			ans += (left + 1) * (right + 1);
		}
	}

	cout << ans + N + 1 << "\n";

	return 0;
}