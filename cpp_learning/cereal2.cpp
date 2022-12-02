#include <bits/stdc++.h>
#define MAX 100010
#define f first
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pdl;

ll N, M;
pdl cows[MAX];
vector<pdl> adj[MAX];
bool v_cereal[MAX] = {false};
pdl no_start = pdl({-1, -1});


//initialize big objects globally to save time
bool taken[MAX] = {false};
bool v_cow[MAX] = {false};

vector<ll> path;

pdl get_start(ll i, ll prev, pdl ans) {
	if (v_cereal[i]) {
		return ans;
	}
	v_cereal[i] = true;

	for (auto j: adj[i]) {
		if (v_cereal[j.f]) {
			if (j.f != prev) {
				ans.f = cows[j.s].f;
				ans.s = j.s;
			}
		}
		else {
			ans = get_start(j.f, i, ans);
		}
	}
	return ans;
}

void dfs(ll c) {
	if (taken[cows[c].f]) {
		if (taken[cows[c].s]) {
			return;
		}
		taken[cows[c].s] = true;
	}
	else {
		taken[cows[c].f] = true;
	}

	v_cow[c] = true;
	path.push_back(c);

	for (auto i: adj[cows[c].f]) {
		if (!v_cow[i.s]) {
			dfs(i.s);
		}
	}

	for (auto i: adj[cows[c].s]) {
		if (!v_cow[i.s]) {
			dfs(i.s);
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "cereal2";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);

	cin >> N >> M;

	for (ll i = 1; i <= N; i++) {
		ll a, b;
		cin >> a >> b;

		cows[i] = pll({a, b});

		adj[a].push_back(pll({b, i}));
		adj[b].push_back(pll({a, i}));
	}

	for (ll i = 1; i <= M; i++) {
		pdl start = get_start(i, -1, no_start);

		if (start.f != -1) {
			if (!v_cow[start.s]) {
				dfs(start.s);
			}
		}
	}

	for (ll i = 1; i <= N; i++) {
		if (!v_cow[i]) {
			dfs(i);
		}
	}

	ll hungry = 0;

	for (ll i = 1; i <= N; i++) {
		if (!v_cow[i]) {
			path.push_back(i);
			hungry++;
		}
	}

	cout << hungry << "\n";

	for (auto i: path) {
		cout << i << "\n";
	}
	
	return 0;
}