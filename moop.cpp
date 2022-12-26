#include <bits/stdc++.h>
#define MAXN 100010
#define x first 
#define y second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N;
pll points[MAXN];
vector<ll> adj[MAXN];
bool visited[MAXN];

void floodfill(ll i) {
    if (visited[i]) return;
    visited[i] = true;

    for (auto j: adj[i]) {
        floodfill(j);
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "moop";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) {
        cin >> points[i].x >> points[i].y;
    }

    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            if (i == j) continue;

            if (points[i].x <= points[j].x &&
                points[i].y <= points[j].y) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    ll ans = 0;

    for (ll i = 0; i < N; i++) {
        if (!visited[i]) {
            ans++;
            floodfill(i);
        }
    }

    cout << ans << "\n";
	
	return 0;
}