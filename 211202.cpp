#include <bits/stdc++.h>
#define MAX 100010
using namespace std;

typedef long long ll;

ll T, N, M;
bool visited[MAX];
vector<ll> adj[MAX];
vector<vector<ll>> comps;

void dfs(ll i, vector<ll>& comp) {
    if (visited[i]) return;
    visited[i] = true;

    comp.push_back(i);

    for (auto j: adj[i]) {
        dfs(j, comp);
    }
}

ll get_cost(vector<ll>& ref, ll i) {
    ll cost = 1e18;

    auto it2 = upper_bound(ref.begin(), ref.end(), i);
    auto it1 = it2; it1--; 

    if (it2 != ref.end()) {
        cost = min(cost, *it2 - i);
    }

    if (it2 != ref.begin()) {
        cost = min(cost, i - *it1);
    }

    return cost;
}

ll min_diff(vector<ll>& v1, vector<ll>& v2) {
    if (v1.size() > v2.size()) {
        return min_diff(v2, v1);
    }

    ll result = 1e18;

    for (auto i: v1) {
        result = min(result, get_cost(v2, i));
    }

    return result;
}



ll solve() {
    vector<ll> comp1;
    dfs(1, comp1);

    sort(comp1.begin(), comp1.end());

    if (visited[N]) return 0;

    vector<ll> compN;
    dfs(N, compN);

    sort(compN.begin(), compN.end());

    ll ans = pow(min_diff(comp1, compN), 2);

    for (ll i = 1; i <= N; i++) {
        if (!visited[i]) {
            vector<ll> comp;
            dfs(i, comp);
            sort(comp.begin(), comp.end());
            comps.push_back(comp);
        }
    }

    for (auto& comp: comps) {
        ll poss = pow(min_diff(comp1, comp), 2) + pow(min_diff(compN, comp), 2);
        ans = min(ans, poss);
    }

    return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "211202";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);

    cin >> T;

    while (T--) {
        cin >> N >> M;

        fill(visited, visited + MAX, false);
        fill(adj, adj + MAX, vector<ll>());
        comps.clear();
        
        for (ll i = 0; i < M; i++) {
            ll a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        cout << solve() << "\n";
    }
	
	return 0;
}