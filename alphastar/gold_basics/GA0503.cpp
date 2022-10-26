#include <bits/stdc++.h>
#define MAXN 110
#define f first 
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

vector<pll> adj[MAXN];
ll N, M;

pair<ll, vector<ll>> dijkstra(ll start, ll end, pll doubled) {
    vector<bool> visited (N, false);
    vector<ll> dists(N, pow(10, 7) * N);
    vector<ll> prev (N);
    vector<ll> path;
    dists[start] = 0;
    prev[start] = -1;

    for (ll i = 0; i < N; i++) {
        ll curr = -1;
        for (ll j = 0; j < N; j++) {
            if (!visited[j] && (curr == -1 || dists[j] < dists[curr])){
                curr = j;
            }
        }        

        visited[curr] = true;

        for (auto j: adj[curr]) {
            ll d1, d2;
            d1 = min(j.s, curr);
            d2 = max(j.s, curr);
            ll newdist = j.f + dists[curr];
            if (pll({d1, d2}) == doubled) {
                newdist += j.f;
            }
            if (newdist < dists[j.s]) {
                dists[j.s] = newdist;
                prev[j.s] = curr;
            }
        }
    }

    ll curr = end;
    while (curr != -1) {
        path.push_back(curr);
        curr = prev[curr];
    }

    return pair<ll, vector<ll>>({dists[end], path});
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "dog";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
    cin >> N >> M;

    ll a, b, d;
    for (ll i = 0; i < N; i++) {
        cin >> a >> b >> d;
        a--;
        b--;
        adj[a].push_back(pll({d, b}));
        adj[b].push_back(pll({d, a}));
    }
	
    pair<ll, vector<ll>> di = dijkstra(0, N - 1, pll({-1, -1}));

    return 0;

    for (ll i = 0; i < (di.s).size(); i++) {
        cout << di.s[i] << " ";
    }
    cout << "\n";
    cout << di.f << "\n";

    ll ans = pow(10, 7) * N;

    for (ll i = 0; i < (di.s).size() - 1; i++) {
        pll doubled = pll({di.s[i], di.s[i + 1]});
        if (doubled.f > doubled.s) swap(doubled.f, doubled.s);
        ll di2 = (dijkstra(0, N - 1, doubled)).f;
        ans = min(ans, di2);
    }

    cout << ans - di.f << "\n";

	return 0;
}