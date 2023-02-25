#include <bits/stdc++.h>
#define MAX 100010
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N, M;
vector<pll> adj[MAX];
ll dest[MAX];
ll comp[MAX];

void dfs(ll w, ll i, ll c) {
    if (comp[i] != 0) return;
    comp[i] = c;

    for (auto j: adj[i]) {
        if (j.s < w) {
            continue;
        }
        dfs(w, j.f, c);
    }
}

bool works(ll w) {
    fill(comp, comp + MAX, 0);

    ll c = 0;

    for (ll i = 1; i <= N; i++) {
        if (comp[i] == 0) {
            c++;
            dfs(w, i, c);
        }
    }

    for (ll i = 1; i <= N; i++) {
        if (comp[i] != comp[dest[i]]) return false;
    }

    return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "wormsort";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;

    bool already = true;

    for (ll i = 1; i <= N; i++) {
        cin >> dest[i];
        if (i != dest[i]) already = false;
    }

    if (already) {
        cout << "-1\n";
        return 0;
    }

    for (ll i = 0; i < M; i++) {
        ll a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    ll low = 1; 
    ll high = 1e9;

    while (high - low > 1) {
        ll mid = (low + high) / 2;
        if (works(mid)) {
            low = mid;
        } else {
            high = mid;
        }
    }

    cout << low << "\n";

    // case where mid should be -1
	
	return 0;
}