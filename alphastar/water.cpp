#include <bits/stdc++.h>
#define MAXN 1010
#define f first  
#define s second 

using namespace std;

typedef long long ll;
typedef tuple<ll, ll, ll> tll;
typedef pair<ll, ll> pll;

ll N, M;
ll dists[MAXN];
vector<tll> adj[MAXN];
set<ll> flows;

double dijkstra(ll fmin) {
    priority_queue<pll, vector<pll>, greater<pll>> q;
    bool visited[MAXN] = {false};

    q.push({0, 1});

    ll fmin_actual = 1010;

    while (!q.empty()) {

        auto curr = q.top();
        q.pop();

        if (visited[curr.s]) continue;
        visited[curr.s] = true;
        dists[curr.s] = curr.f;

        for (auto i: adj[curr.s]) {
            ll c, n, fr;
            tie(c, n, fr) = i;
            ll newdist = dists[curr.s] + c;
            if (fr >= fmin && !visited[curr.s]) {
                fmin_actual = min(fr, fmin_actual);
                q.push(pll({newdist, n}));
            }
        }
    }

    if (visited[N]) {
        return (double) (fmin_actual/dists[N]);
    }   
    else {
        return -1;
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "water";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;

    for (ll i = 0; i < M; i++) {
        ll a, b, c, fr;
        cin >> a >> b >> c >> fr;

        adj[a].push_back(tll({c, b, fr}));
        adj[b].push_back(tll({c, a, fr}));

        flows.insert(fr);
    }

    double ans = -1;

    for (auto fr: flows) {
        ans = max(ans, dijkstra(fr));
    }

    cout << (ll) (ans * pow(10, 6)) << "\n";
	
	return 0;
}

