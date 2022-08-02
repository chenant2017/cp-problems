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

ll barn_dist(Cow& a) {
	if (a.d == 1) {
		return L - a.x;
	}
	else {
		return a.x;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "meetings";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> L;

	double total_weight = 0;

	ll lc = 0;

	for (ll i = 0; i < N; i++) {
		cin >> cows[i].w >> cows[i].x >> cows[i].d;
		total_weight += cows[i].w;
		if (cows[i].d == -1) {
			lc++;
		}
	}

	sort(cows, cows + N, [](auto& a, auto& b) {
		return a.x < b.x;
	});

	ll rc = 0;
	for (ll i = 0; i < N; i++) {
		weights[i] = cows[i].w;
		rcows[i] = rc;
		lcows[i] = lc;
		if (cows[i].d == 1) {
			rc++;
		}
		else {
			lc--;
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
	ll dist = -1;

	sort(cows, cows + N, [](auto& a, auto& b) {
		return barn_dist(a) < barn_dist(b);
	});

	for (ll i = 0; i < N; i++) {
		weight += cows[i].w;
		if (weight >= total_weight / 2.0) {
			dist = barn_dist(cows[i]);
			break;
		}
	}

	sort(cows, cows + N, [](auto& a, auto& b) {
		return a.x < b.x;
	});

	ll ptr = 0;
	list<ll> lcows2;

	ll ans = 0;

	for (ll i = 0; i < N; i++) {
		while (ptr + 1 < N && cows[ptr + 1].x - cows[i].x <= 2 * dist) {
			ptr++;
			if (cows[ptr].d == -1) {
				lcows2.push_back(ptr);
			}
		}
		while (!lcows2.empty() && lcows2.front() <= i) {
			lcows2.pop_front();
		}
		if (cows[i].d == 1) {
			ans += lcows2.size();
		}
	}

	cout << ans << "\n";

	return 0;
}