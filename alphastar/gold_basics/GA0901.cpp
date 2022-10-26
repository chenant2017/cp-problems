#include <bits/stdc++.h>
#define MAXN 100010
#define f first  
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N, M, C;
ll S[MAXN];
vector<pll> adj[MAXN];

vector<ll> topo_sort() {
    vector<ll> path;

    vector<ll> indegrees(N, 0);
    for (ll i = 0; i < N; i++) {
        for (auto j: adj[i]) {
            indegrees[j.s]++;
        }
    }

    queue<ll> q;

    for (ll i = 0; i < N; i++) {
        if (indegrees[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        path.push_back(curr);

        for (auto j: adj[curr]) {
            indegrees[j.s]--;
            if (indegrees[j.s] == 0) {
                q.push(j.s);
            }
        }
    }

    return path;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "ac";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M >> C;

    for (ll i = 0; i < N; i++) {
        cin >> S[i];
    }

    ll a, b, x;
    for (ll i = 0; i < C; i++) {
        cin >> a >> b >> x;
        a--; b--;
        adj[a].push_back(pll({x, b}));
    }

    vector<ll> path = topo_sort();

    for (auto i: path) {
        for (auto j: adj[i]) {
            S[j.s] = max(S[j.s], S[i] + j.f);
        }
    }

    for (ll i = 0; i < N; i++) {
        cout << S[i] << "\n";
    }
	
	return 0;
}