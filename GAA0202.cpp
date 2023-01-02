#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

typedef long long ll;

ll N, K;
vector<ll> adj[MAXN];
ll Bdist[MAXN];
ll Fdist[MAXN];
bool visited[MAXN];

ll bfs() {
    ll ans = 0;

    for (ll i = 1; i <= N; i++) {
        Bdist[i] = -1;
    }

    Bdist[K] = 0;

    queue<ll> q;
    q.push(K);

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        if (Bdist[curr] >= Fdist[curr]) {
            ans++;
            continue;
        }

        for (auto i: adj[curr]) {
            if (Bdist[i] == -1) {
                Bdist[i] = Bdist[curr] + 1;
                q.push(i);
            }
        }
    }

    return ans;
}

void dfs(ll i) { //dist to closest farmer
    if (visited[i]) return;
    visited[i] = true;

    bool leaf = true;
    for (auto a: adj[i]) {
        if (!visited[a]) {
            leaf = false;
            dfs(a);
            Fdist[i] = min(Fdist[i], Fdist[a] + 1);
        }
    }

    if (leaf) {
        Fdist[i] = 0;
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAA0202";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> K;

    for (ll i = 0; i < N - 1; i++) {
        ll a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (ll i = 1; i <= N; i++) {
        Fdist[i] = 2 * N;
    }

    dfs(K);

    ll ans = bfs();

    cout << ans << "\n";
	
	return 0;
}