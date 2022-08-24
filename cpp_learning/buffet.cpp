#include <bits/stdc++.h>
#define MAX 1010
#define f first
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N, E;
vector<ll> adj[MAX];
ll quality[MAX];
ll shortest[MAX][MAX];
vector<vector<ll>> comps;
bool all_visited[MAX]; //for getting components

vector<ll> get_shortest(ll i) {
    vector<ll> comp;
    vector<bool> visited(N + 1, false);
    queue<pll> q;
    q.push(pll({i, 0}));

    while (!q.empty()) {
        auto curr = q.front(); 
        q.pop();

        //cout << curr.f << "\n";
        if (visited[curr.f]) continue;

        visited[curr.f] = true;
        if (!all_visited[curr.f]) {
            comp.push_back(curr.f);
            all_visited[curr.f] = true;
        }

        shortest[i][curr.f] = curr.s;
        shortest[curr.f][i] = curr.s;

        for (auto j: adj[curr.f]) {
            if (!visited[j]) {
                q.push(pll({j, curr.s + 1}));
            }
        }
    }
    return comp;
}

ll get_energy(vector<ll>& comp) {
    sort(comp.begin(), comp.end(), [](auto a, auto b) {
        return quality[a] < quality[b];
    });

    vector<ll> sol (comp.size());
    sol[0] = quality[comp[0]];
    
    for (ll i = 1; i < comp.size(); i++) {
        ll inc = 0;
        for (ll j = 0; j < i; j++) {
            ll e = sol[j] - E * shortest[comp[j]][comp[i]];
            inc = max(e, inc);
        }
        sol[i] = quality[comp[i]] + inc;
    }
    return sol[comp.size() - 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "buffet";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> E;

    ll D;

    for (ll i = 1; i <= N; i++) {
        cin >> quality[i] >> D;
        for (ll j = 0; j < D; j++) {
            ll a;
            cin >> a;
            adj[i].push_back(a);
        }
    }

    for (ll i = 1; i <= N; i++) {
        vector<ll> comp = get_shortest(i);
        if (comp.size() > 0) {
            comps.push_back(comp);
        }
    }

    ll ans = 0;

    for (auto& i: comps) {
        ans = max(ans, get_energy(i));
    }

    cout << ans << "\n";

	return 0;
}