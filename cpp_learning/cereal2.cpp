//Silver 2022 Jan #3

#include <bits/stdc++.h>
#define MAX 100010
#define f first   
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N, M;

vector<pll> adj[MAX];
vector<pll> edges (MAX);

pll find_start(ll& start, vector<bool>& visited_v) {
	pll result = pll({-1, -1});

	vector<bool> visited_e (MAX, false);
	stack<pll> q; //node, edge it's planning to go on
	
	for (auto& i: adj[start]) {
		pll p = pll({start, i.s});
		q.push(p);
		result.f = edges[i.s].f;
		result.s = i.s;
	}

	while (!q.empty()) {
		auto curr = q.top(); 
		q.pop();
		if (visited_e[curr.s]) {
			result.f = edges[curr.s].f;
			result.s = curr.s;
			break;
		}

		visited_v[curr.f] = true;
		visited_e[curr.s] = true;

		ll next = edges[curr.s].f;
		if (next == curr.f) {
			next = edges[curr.s].s;
		}

		for (auto& i: adj[next]) {
			if (i.s == curr.s) {
				continue;
			}
			q.push(pll({next, i.s}));
		}
	}
	return result;
}

void get_path(pll& start, vector<bool>& cow, 
		vector<bool>& cereal, vector<ll>& path) {
	stack<pll> q;

	cow[start.s] = true;
	cereal[start.f] = true;
	path.push_back(start.s);

	//cout << start.f << " " << start.s << " start\n";

	for (auto& i: adj[start.f]) {
		//cout << cow[i.s] << " >:(\n";
		if (!cow[i.s] && !cereal[i.f]) q.push(i);
	}
	
	while (!q.empty()) {
		auto curr = q.top();
		q.pop();

		if (cereal[curr.f] || cow[curr.s]) continue;

		cow[curr.s] = true;
		cereal[curr.f] = true;
		//cout << curr.f << " " << curr.s << "\n";

		path.push_back(curr.s);

		for (auto& i: adj[curr.f]) {
			if (!cow[i.s] && !cereal[i.f]) q.push(i);
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

	for (ll i = 1; i <= N; i++){
		ll a, b;
		cin >> a >> b;
		edges[i] = pll({a, b});
		adj[a].push_back(pll({b, i}));
		adj[b].push_back(pll({a, i}));
	}

	vector<bool> visited_v (MAX, false);
	vector<bool> cow (MAX, false);
	vector<bool> cereal(MAX, false);
	vector<ll> path;
	ll fed = 0;

	for (ll i = 1; i <= N; i++) {
		if (!visited_v[i]) {
			pll result = find_start(i, visited_v);
			if (result.f != -1 && !cereal[result.f] && !cow[result.s]) { //other conditions too
				get_path(result, cow, cereal, path);
			}
		}
	}

	ll hungry = 0;

	for (ll i = 1; i <= N; i++) {
		if (!cow[i]) {
			hungry++;
			path.push_back(i);
		}
	}

	cout << hungry << "\n";
	
	for (auto i: path) {
		cout << i << "\n";
	}
	
	return 0;
}