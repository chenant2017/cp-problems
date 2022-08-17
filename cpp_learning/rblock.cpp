#include <bits/stdc++.h>
#define MAXN 255
#define MAXM 250010
#define f first
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, set<ll>> pls;
typedef pair<ll, ll> pll;

ll N, M;
ll edges[MAXM];
vector<pll> adj[MAXN];

pls solve(ll field, set<ll> visited) {
	pls result;
	result.f = -1;
	result.s = visited;
	
	if (field == N) {
		result.f = 0;
		return result;
	}

	for (auto& i: adj[field]) {
		if (visited.find(i.s) == visited.end()) {
			visited.insert(i.s);
			auto p = solve(i.f, visited);
			if (edges[i.s] + p.f < result.f || result.f == -1) {
				result.f = edges[i.s] + p.f;
				result.s = p.s;
			}
			visited.erase(i.s);
		}
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "rblock";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;

	for (ll i = 0; i < M; i++) {
		ll a, b, l;
		cin >> a >> b >> l;
		edges[i] = l;
		adj[a].push_back(pll({b, i}));
		adj[b].push_back(pll({a, i}));
	}

	set<ll> visited;
	pls ans1 = solve(1, visited);

	ll ans = 0;

	for (auto i: ans1.s) {
		edges[i] *= 2;
		pls ans2 = solve(1, visited);
		if (ans2.f - ans1.f > ans) {
			ans = ans2.f - ans1.f;
		}
		edges[i] /= 2;
	}

	cout << ans << "\n";

	return 0;
}
