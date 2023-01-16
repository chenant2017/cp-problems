#include <bits/stdc++.h>
#define MAX 100010
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> ppll;

ll N, M;
ll p[MAX];
ll q[MAX];
set<ll> rem;
ppll edges[MAX];
ll parent[MAX];
ll sizes[MAX];

ll get_rep(ll i) {
    ll j = i;
    while (parent[j] != j) {
        j = parent[j];
    }
    parent[i] = j;
    return j;
}

void merge(ll i, ll j) {
    i = get_rep(i);
    j = get_rep(j);
    if (i == j) return;
    if (sizes[i] < sizes[j]) swap(i, j);
    sizes[i] += sizes[j];
    parent[j] = i;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "wormsort";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
    cin >> N >> M;

    for (ll i = 1; i <= N; i++) {
        cin >> p[i];
        if (i != p[i]) rem.insert(i);
    }

    for (ll i = 1; i <= N; i++) {
        q[p[i]] = i;
    }

    for (ll i = 0; i < M; i++) {
        ll a, b, w;
        cin >> a >> b >> w;

        edges[i] = {w, {a, b}};
    }

    for (ll i = 1; i <= N; i++) {
        parent[i] = i;
        sizes[i] = 1;
    }

    sort(edges, edges + M, greater<ppll>());

    ll ans = -1;

    if (!rem.empty()) {
        for (ll i = 0; i < M; i++) {
            ll a, b;
            tie(a, b) = edges[i].s;
            merge(a, b);
            
            vector<ll> v;
            for (auto j: rem) {
                if (get_rep(j) == get_rep(p[j])) {
                    v.push_back(j);
                }
            }

            for (auto j: v) rem.erase(j);

            if (rem.empty()) {
                ans = edges[i].f;
                break;
            }
        }
    }
    
    cout << ans << "\n";
	
	return 0;
}