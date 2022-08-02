#include <bits/stdc++.h>

#define MAXN  100010
#define ll long long
#define f first
#define s second

using namespace std;

ll N;
pair<ll, ll> points[MAXN];
pair<ll, ll> yminmax1[MAXN];
pair<ll, ll> yminmax2[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "moop";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);

	cin >> N;

	for (ll i = 0; i < N; i++) {
		cin >> points[i].f >> points[i].s;
	}

	sort(points, points + N);


	yminmax1[0] = pair<ll, ll>({points[0].s, points[0].s});

	for (ll i = 1; i < N; i++) {
		yminmax1[i] = yminmax1[i - 1];
		if (points[i].s < yminmax1[i - 1].f) {
			yminmax1[i].f = points[i].s;
		}
		if (points[i].s > yminmax1[i - 1].s) {
			yminmax1[i].s = points[i].s;
		}
	}


	yminmax2[N - 1] = pair<ll, ll>({points[N - 1].s, points[N - 1].s});

	for (ll i = N - 2; i >= 0; i--) {
		yminmax2[i] = yminmax2[i + 1];
		if (points[i].s < yminmax2[i + 1].f) {
			yminmax2[i].f = points[i].s;
		}
		if (points[i].s > yminmax2[i + 1].s) {
			yminmax2[i].s = points[i].s;
		}
	}

	ll ans = 1;

	for (ll i = 0; i < N - 1; i++) {
		if (yminmax1[i].f > yminmax2[i + 1].s) {
			ans++;
		}
	}

	cout << ans << "\n";
	


	return 0;
}