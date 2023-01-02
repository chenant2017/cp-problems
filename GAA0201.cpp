#include <bits/stdc++.h>
#define MAXN 10010
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N, M, T;
ll c[MAXN];
ll shortest[MAXN];
ll parent[MAXN];
ll pass[MAXN] = {0};
vector<pll> adj[MAXN];

void dijkstra(ll start) {
    for (ll i = 1; i <= N; i++) {
        shortest[i] = 1e15;
    }

    shortest[start] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto curr = pq.top().s;
        pq.pop();

        for (auto i: adj[curr]) {
            if (shortest[curr] + i.f < shortest[i.s]) {
                shortest[i.s] = shortest[curr] + i.f;
                parent[i.s] = curr;
                pq.push({shortest[i.s], i.s});
            }
            else if (shortest[curr] + i.f == shortest[i.s]) {
                if (curr < parent[i.s]) {
                    parent[i.s] = curr;
                }
            }
        }
    }
}

void trace(ll end) {
    pass[end] += c[end];
    ll e = end;
    while (parent[e] != 1) {
        e = parent[e];
        pass[e] += c[end];
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAA0201";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M >> T;

    for (ll i = 1; i <= N; i++) {
        cin >> c[i];
    }

    ll a, b, t;
    for (ll i = 0; i < M; i++) {
        cin >> a >> b >> t;
        adj[a].push_back({t, b});
        adj[b].push_back({t, a});
    }

    dijkstra(1);
   

    for (ll i = 2; i <= N; i++) {
        trace(i);
    }

    ll ans = 0;

    for (ll i = 2; i <= N; i++) {
        if (T < shortest[i]) {
            ans = max(ans, pass[i] * (shortest[i] - T));
        }
    }

    cout << ans << "\n";
	
	return 0;
}