#include <bits/stdc++.h>
#define f first 
#define s second 
#define MAXN 100010
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N, M;
pll cows[MAXN];
vector<ll> adj[MAXN];
bool visited[MAXN] = {false};

void floodfill(ll i, vector<ll>& extrema) { // minx, maxx, miny, maxy
    if (visited[i]) return;
    visited[i] = true;

    extrema[0] = min(extrema[0], cows[i].f);
    extrema[1] = max(extrema[1], cows[i].f);
    extrema[2] = min(extrema[2], cows[i].s);
    extrema[3] = max(extrema[3], cows[i].s);

    for (auto j: adj[i]) {
        if (!visited[j]) floodfill(j, extrema);
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "fenceplan";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;

    for (ll i = 1; i <= N; i++) {
        cin >> cows[i].f >> cows[i].s;
    }

    for (ll i = 1; i <= M; i++) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ll ans = 4e9;

    for (ll i = 1; i <= N; i++) {
        if (!visited[i]) {
            vector<ll> extrema = {(ll) 1e9, -1, (ll) 1e9, -1};
            floodfill(i, extrema);

            ll perimeter = 2 * (extrema[1] + extrema[3] - extrema[0] - extrema[2]);
            ans = min(perimeter, ans);
        }
    }

    cout << ans << "\n";
	
	return 0;
}