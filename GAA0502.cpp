#include <bits/stdc++.h>
#define MAXN 1010
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N;
pll points[MAXN];
set<pll> adj[MAXN];
bool visited[MAXN];

ll dist(pll a, pll b) {
    return (pow(a.f - b.f, 2) + pow(a.s - b.s, 2));
}

ll dfs(ll i, ll x) {
    ll count = 0;
    if (visited[i]) return count;
    visited[i] = true;
    count++;

    for (auto j: adj[i]) {
        if (j.f > x) break;
        count += dfs(j.s, x);
    }
    
    return count;
}

bool works(ll x) {
    for (ll i = 0; i < N; i++) {
        visited[i] = false;
    }
    ll c = dfs(0, x);
    //cout << c << "\n";
    return c == N;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAA0502";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
    cin >> N;
 
    for (ll i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }

    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            if (i == j) continue;
            adj[i].insert({dist(points[i], points[j]), j});
        }
    }

    ll x = 1.5e9;
    ll jump = 7.5e8;

    while (jump > 0) {
        if (works(x - jump)) {
            x -= jump;
        }
        else {
            jump /= 2;
        }
    }    

    cout << x << "\n";
	
	return 0;
}