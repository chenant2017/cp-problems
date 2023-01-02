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
vector<ll> ans(2 * MAXN, -1);
set<pll> unvisited_B;
set<pll> unvisited_E;
queue<ll> q;
queue<ll> q2;
ll moves = 1;


bool bfs(ll c, set<pll>& unvisited1, set<pll>& unvisited2, vector<ll>& BE1, vector<ll>& BE2) {
	if (unvisited1.find(pll({BE2[c], c})) == unvisited1.end()) {
		return false;
	}
	unvisited1.erase({BE2[c], c});

	ans[c] = moves;

	ll t = BE1[c];
                                                                                                
	//cout << "t "<< t << "\n";

	auto it1 = unvisited2.lower_bound({t - D, -1});
	auto it2 = unvisited2.lower_bound({t + 1, -1});

	//cout << "distance " << distance(it1, it2) << "\n";

	for (auto it = it1; it != it2; it++) {
		//cout << "pushed " << it->s << "\n";
		q2.push(it->s);
	}

	return true;
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
			q.push(i);
		}
    }

	for (ll i = N; i < 2*N; i++) {
		cin >> B[i] >> E[i];
        unvisited_E.insert({B[i], i});
		if (B[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		auto c = q.front();

		//cout << c << " at\n";

		q.pop();

		if (c < N) {
			if (!bfs(c, unvisited_B, unvisited_E, B, E)) {
				continue;
			}
		}
		else {
			if (!bfs(c, unvisited_E, unvisited_B, E, B)) {
				continue;
			}
		}

		if (q.empty()) {
			swap(q2, q);
			moves++;
			//cout << "new move\n";
		}
	}

	for (ll i = 0; i < N; i++) {
		cout << ans[i] << "\n";
	}
	
	return 0;
}