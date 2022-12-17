#include <bits/stdc++.h>
#define MAXN 100010
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N, M;
pll points[MAXN];
vector<ll> adj[MAXN];
bool visited[MAXN] = {false};

void dfs(ll& minx, ll& miny, ll& maxx, ll& maxy, ll start) {
    if (visited[start]) return;
    visited[start] = true;

    minx = min(minx, points[start].f);
    maxx = max(maxx, points[start].f);
    miny = min(miny, points[start].s);
    maxy = max(maxy, points[start].s);

    for (auto i: adj[start]) {
        if (!visited[i]) {
            dfs(minx, miny, maxx, maxy, i);
        }
    }
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "fenceplan";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;

    for (ll i = 0; i < N; i++) {
        cin >> points[i].f >> points[i].s;
    }
	
    for (ll i = 0; i < M; i++) {
        ll a, b;
        cin >> a >> b;

        a--;
        b--;

        adj[a].push_back(b);
        adj[b].push_back(a);    
    }
	
    
    ll ans = 4 * pow(10, 9);

    for (ll i = 0; i < N; i++) {
        if (!visited[i]) {
            ll minx = pow(10, 9), miny = pow(10, 9), maxx = -1, maxy = -1;
            dfs(minx, miny, maxx, maxy, i);

            ans = min(ans, 2 * (maxx + maxy - (minx + miny)));
        }
    }

    cout << ans << "\n";

	return 0;
}