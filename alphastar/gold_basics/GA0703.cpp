#include <bits/stdc++.h>
#define MAXN 2010
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll; 

pll points[MAXN];
bool visited[MAXN] = {false};
ll N, C;

ll prims() {
	priority_queue<pll, vector<pll>, greater<pll>> q;
	q.push(pll({0, 0}));

	ll total = 0;
	ll visited_ct = 0;
	
	while (!q.empty()) {
		auto curr = q.top();
		q.pop();

		if (visited[curr.s]) continue;
		visited_ct++;
		visited[curr.s] = true;

		total += curr.f;

		for (ll i = 0; i < N; i++) {
			ll dist = pow(points[i].f - points[curr.s].f, 2) +
					  pow(points[i].s - points[curr.s].s, 2);
			if (dist >= C && !visited[i]) q.push(pll({dist, i}));
		}
	}

	if (visited_ct < N) return -1;
	return total;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "fixing2";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> C;

	ll x, y;
	for (ll i = 0; i < N; i++) {
        cin >> x >> y;
		points[i].first = x;
		points[i].second = y;
    }

	cout << prims() << "\n";
	
	return 0;
}

