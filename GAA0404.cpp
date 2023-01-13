#include <bits/stdc++.h>
#define MAXN 110
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N, M;
ll adj[MAXN][MAXN];
ll parent1[MAXN];
ll parent2[MAXN];
ll dists[MAXN];
bool visited[MAXN];
pll doubled;

void dijkstra(ll* parent) {
    for (ll i = 1; i <= N; i++) {
        dists[i] = 1e15;
        visited[i] = false;
    }

    dists[1] = 0;

    for (ll i = 0; i < N; i++) {
        ll curr = -1;
        
        for (ll j = 1; j <= N; j++) {
            if (!visited[j] && (curr == -1 || dists[j] < dists[curr])) {
                curr = j;
            }
        }

        visited[curr] = true;

        for (ll j = 1; j <= N; j++) {
            ll dist = dists[curr] + adj[curr][j];
            if ((curr == doubled.f && j == doubled.s) || 
                (curr == doubled.s && j == doubled.f)) {
                dist += adj[curr][j];
            }
            if (dists[j] > dist) {
                dists[j] = dist;
                parent[j] = curr;
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAA0404";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;

    for (ll i = 1; i <= N; i++) {
        for (ll j = 1; j <= N; j++) {
            adj[i][j] = 1e15;
            if (i == j) adj[i][j] = 0;
        }
    }

    for (ll i = 0; i < M; i++) {
        ll a, b, d;
        cin >> a >> b >> d;
        adj[a][b] = d;
        adj[b][a] = d;
    }

    doubled = {-1, -1};
    dijkstra(parent1);
    ll original = dists[N];

    //cout << "original " << original << "\n";
    //return 0;

    ll ans = 0;

    ll curr = N;
    while (curr != 1) {
        doubled = {curr, parent1[curr]};
        dijkstra(parent2);
        //cout << "new " << dists[N] << "\n";
        ans = max(ans, dists[N] - original);
        curr = parent1[curr];
    }
    
    cout << ans << "\n";
	
	return 0;
}