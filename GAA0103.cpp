#include <bits/stdc++.h>
#define MAXN 100010
#define f first  
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N, D;
vector<ll> B(MAXN);
vector<ll> E(MAXN);
vector<ll> ans(2 * MAXN);
set<pll> unvisited_B;
set<pll> unvisited_E;
queue<pll> q;
queue<pll> q2;
ll moves = 1;


void bfs(pll& c, set<pll>& unvisited1, set<pll>& unvisited2) {
	if (unvisited1.find(c) == unvisited1.end()) {
		return;
	}
	unvisited1.erase(c);

	ans[c.s] = moves;

	auto it1 = unvisited2.lower_bound({c.f - D, -1});
	auto it2 = unvisited2.upper_bound({c.f, 2 * N + 5});

	for (auto it = it1; it != it2; it++) {
		q2.push(*it);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAA0103";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> D;

    for (ll i = 0; i < N; i++) {
        cin >> B[i] >> E[i];
        unvisited_B.insert({E[i], i});  
		if (E[i] == 0) {
			q.push({E[i], i});
		}
    }

	for (ll i = N; i < 2*N; i++) {
		cin >> B[i] >> E[i];
        unvisited_E.insert({B[i], i});
		if (B[i] == 0) {
			q.push({B[i], i});
		}
	}

	while (!q.empty()) {
		auto c = q.front();
		q.pop();

		if (c.s < N) {
			bfs(c, unvisited_B, unvisited_E);
		}
		else {
			bfs(c, unvisited_E, unvisited_B);
		}

		if (q.empty()) {
			swap(q2, q);
			moves++;
		}
	}

	for (ll i = 0; i < N; i++) {
		cout << ans[i] << "\n";
	}
	
	return 0;
}