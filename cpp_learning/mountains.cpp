#include <bits/stdc++.h>

#define ll long long
#define f first
#define s second
#define MAXN 100010

using namespace std;
ll N;

pair<ll, ll> xbounds[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "mountains";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

	for (ll i = 0; i < N; i++) {
		ll x, y;
		cin >> x >> y;
		xbounds[i] = pair<ll, ll>({x - y, y + x});
	}
	
	sort(xbounds, xbounds + N, [](auto& a, auto& b) {
		return a.f < b.f || (a.f == b.f && a.s > b.s);
	});

	ll ans = 0;
	pair<ll, ll> dominant = {-1, -1};

	for (ll i = 0; i < N; i++) {
		if (xbounds[i].s > dominant.s) {
			dominant = xbounds[i];
			ans++;
		}
	}

	cout << ans << "\n";

	

	return 0;
}