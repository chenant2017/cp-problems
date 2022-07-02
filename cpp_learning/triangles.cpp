#include <bits/stdc++.h>

#define ll long long
#define f first
#define s second
using namespace std;

map<ll, vector<ll>> byx;
map<ll, vector<ll>> byy;
map<pair<ll, ll>, pair<ll, ll>> ans;

ll N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "triangles";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

	for (ll i = 0; i < N; i++) {
		ll x, y;
		cin >> x >> y;

		byx[x].push_back(y);
		byy[y].push_back(x);

		ans[pair<ll, ll>({x, y})] = pair<ll, ll>({0, 0});
	}

	ll sum;

	for (auto& i: byx) {
		ll xval = i.f;
		vector<ll> &yvals = i.s;
		sort(yvals.begin(), yvals.end());
		sum = 0;

		for (ll j = yvals.size() - 2; j >= 0; j--) {
			sum += yvals[j + 1];
			ans[pair<ll, ll>(xval, yvals[j])].f += sum - yvals[j] * (yvals.size() - 1 - j);
		}

		sum = 0;
		for (ll j = 1; j < yvals.size(); j++) {
			sum += yvals[j - 1];
			ans[pair<ll, ll>(xval, yvals[j])].f += yvals[j] * (j) - sum;
		}
	}

	for (auto& i: byy) {
		ll yval = i.f;
		vector<ll> &xvals = i.s;
		sort(xvals.begin(), xvals.end());
		sum = 0;

		for (ll j = xvals.size() - 2; j >= 0; j--) {
			sum += xvals[j + 1];
			ans[pair<ll, ll>(xvals[j], yval)].s += sum - xvals[j] * (xvals.size() - 1 - j);
		}

		sum = 0;
		for (ll j = 1; j < xvals.size(); j++) {
			sum += xvals[j - 1];
			ans[pair<ll, ll>(xvals[j], yval)].s += xvals[j] * j - sum;
		}
	}

	ll total = 0;

	for (auto& i: ans) {
		total += i.s.f * i.s.s;
	}

	cout << total << "\n";




	return 0;
}