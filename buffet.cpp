#include <bits/stdc++.h>
#define MAXN 1010
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll qualities[MAXN];
ll dists[MAXN][MAXN];
vector<ll> adj[MAXN];
ll sorted[MAXN];
ll ans[MAXN] = {0};

ll N, E;

void bfs(ll start) {
    vector<bool> visited(N + 1, false);
    queue<pll> q;
    q.push(pll({start, 0}));

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        if (visited[curr.f]) {
            continue;
        }
        visited[curr.f] = true;
        dists[start][curr.f] = curr.s;
        dists[curr.f][start] = curr.s;
        
        for (auto i: adj[curr.f]) {
            if (!visited[i]) {
                q.push(pll({i, curr.s + 1}));
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "buffet";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> E;
    
    for (ll i = 1; i <= N; i++) {
        cin >> qualities[i];
        ll D;
        cin >> D;
        for (ll j = 0; j < D; j++) {
            ll n;
            cin >> n;
            adj[i].push_back(n);
        }
    }

    for (ll i = 1; i <= N; i++) {
        bfs(i);
    }

    for (ll i = 1; i <= N; i++) {
        sorted[i] = i;
    }

    sort(sorted + 1, sorted + N + 1, [](auto a, auto b) {
        return qualities[a] < qualities[b];
    });

    for (ll i = 1; i <= N; i++) {
        cout << sorted[i] << "\n";
    }

    ans[1] = qualities[sorted[1]];

    for (ll i = 2; i <= N; i++) {
        ans[i] = qualities[sorted[i]];
        for (ll j = 1; j < i; j++) {
            ans[i] = max(ans[i], ans[j] + qualities[sorted[i]] - dists[sorted[i]][sorted[j]] * E);
        }
    }

    for (ll i = 1; i <= N; i++) {
        //cout << ans[i] << "\n";
    }

    cout << *max_element(ans + 1, ans + N + 1) << "\n";

	
	return 0;
}