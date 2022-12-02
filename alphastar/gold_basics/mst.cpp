#include <bits/stdc++.h>
#define MAXV 50010
#define f first
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;


ll V, E;
vector<pll> adj[MAXV];
bool visited[MAXV] = {false};

ll mst() {
    priority_queue<pll, vector<pll>, greater<pll>> q;
    q.push({0, 1});

    ll result = 0;

    while (!q.empty()) {
        auto curr = q.top();
        q.pop();
        if (visited[curr.s]) continue;

        visited[curr.s] = true;

        result += curr.f;
        for (auto i: adj[curr.s]) {
            if (!visited[i.s]) {
                q.push(i);
            }
        }
    }

    return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "mst";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> V >> E;

    for (ll i = 0; i < E; i++) {
        ll A, B, C;
        cin >>  A >> B >> C;
        adj[A].push_back(pll({C, B}));
        adj[B].push_back(pll({C, A}));
    }

    cout << mst() << "\n";
	
	return 0;
}