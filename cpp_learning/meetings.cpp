#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define MAXN 50010
#define f first
#define s second

using namespace std;

struct Cow {
	ll w, x, d;
};

ll N, L;
Cow cows[MAXN];
ll lcows[MAXN];
ll rcows[MAXN];
ll weights[MAXN];
list<ll> rcowsdist;
list<ll> lcowsdist;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "meetings";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> L;

	double total_weight = 0;

	for (ll i = 0; i < N; i++) {
		ll w, x, d;
		cin >> cows[i].w >> cows[i].x >> cows[i].d;
		total_weight += cows[i].w;
	}

	sort(cows, cows + N, [](auto& a, auto& b) {
		return a.x < b.x;
	});

	for (ll i = 0; i < N; i++) {
		weights[i] = cows[i].w;
		if (cows[i].d == 1) {
			rcowsdist.push_front(i);
		}
		else {
			lcowsdist.push_back(i);
		}
	}

	rcows[0] = 0;
	for (ll i = 1; i < N; i++) {
		rcows[i] = rcows[i - 1];
		if (cows[i - 1].d == 1) {
			rcows[i]++;
		}
	}

	lcows[N - 1] = 0;
	for (ll i = N - 2; i >= 0; i--) {
		lcows[i] = lcows[i + 1];
		if (cows[i + 1].d == -1) {
			lcows[i]++;
		}
	}

	for (ll i = 0; i < N; i++) {
		if (cows[i].d == 1) {
			cows[i].w = weights[i + lcows[i]];
		}
		else {
			cows[i].w = weights[i - rcows[i]];
		}
	}

	ll weight = 0;
	ll ans = 0;
	ll dist;

	while (weight < total_weight / 2.0) {
		ll rdist = 2 * L;
		ll ldist = 2 * L;
		if (!rcowsdist.empty()) {
			rdist = L - cows[rcowsdist.front()].x;
		}
		if (!lcowsdist.empty()) {
			ldist = cows[lcowsdist.front()].x;
		}

		if (rdist < ldist) {
			dist = ldist;
			weight += cows[rcowsdist.front()].w;
			rcowsdist.pop_front();
		}
		else if (rdist > ldist) {
			dist = rdist;
			weight += cows[lcowsdist.front()].w;
			lcowsdist.pop_front();
		}
		else if (rdist != 2 * L && rdist == ldist) {
			dist = rdist;
			weight += cows[rcowsdist.front()].w + cows[lcowsdist.front()].w;
			rcowsdist.pop_front();
			lcowsdist.pop_front();
		}
	}

	ll ptr = 0;
	ll lcows2 = 0;

	for (ll i = 0; i < N; i++) {
		if (cows[i].d == -1) {
			if (i <= ptr) {
				lcows2--;
			}
			continue;
		}

		while (ptr + 1 < N && cows[ptr + 1].x - cows[i].x <= dist) {
			ptr++;
			if (ptr > i && cows[ptr].d == -1) {
				lcows2++;
			}
		}

		ans += lcows2;
	}


	cout << ans << "\n";




	return 0;
}