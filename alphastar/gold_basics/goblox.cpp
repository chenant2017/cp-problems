#include <bits/stdc++.h>
#define MAXN 110
#define MAXM 10010
#define f first
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N, M;
ll dists[MAXN];
ll from[MAXN];
vector<pll> adj[MAXN];
bool visited[MAXN];

pair<ll, vector<ll>> dijkstra(ll start, ll end) {
    for (ll i = 1; i <= N; i++) {
        visited[i] = false;
    }
    for (ll i = 1; i <= N; i++) {
        dists[i] = 1000000 * 100;
    }
    for (ll i = 1; i <= N; i++) {
        from[i] = 0;
    }

    priority_queue<pll> q;
    dists[start] = 0;
    q.push(pll({0, start}));

    while (!q.empty()) {
        auto c = q.top().s;
        q.pop();

        if (visited[c]) continue;
        visited[c] = true;

        for (auto& i: adj[c]) {
            ll newdist = dists[c] + i.f;
            if (newdist < dists[i.s]) {
                dists[i.s] = newdist;
                from[i.s] = c;
                q.push(pll({-dists[i.s], i.s}));
            }
        }
    } 

    vector<ll> path;
    ll c = end;
    while (c != start) {
        path.push_back(c);
        c = from[c];
    }
    path.push_back(start);

    return pair<ll, vector<ll>>({dists[end], path});
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "goblox";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;

    for (ll i = 0; i < M; i++) {
        ll A, B, D;
        cin >> A >> B >> D;

        adj[A].push_back(pll({D, B}));
        adj[B].push_back(pll({D, A}));
    }

    auto result = dijkstra(1, N);
    vector<ll>& path = result.s;
    ll len = result.f;
    ll ans = 0;

    for (ll i = 1; i < path.size(); i++) {
        for (auto& j: adj[path[i]]) {
            if (j.s == path[i - 1]) {
                j.f *= 2;
                ll len2 = dijkstra(1, N).f;
                //cout << len2 << " after doubling " << path[i] << " " << path[i - 1] << "\n";
                ans = max(ans, len2 - len);
                j.f /= 2;
                break;
            }
        }
    }

    cout << ans << "\n";

	return 0;
}