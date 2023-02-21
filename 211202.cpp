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

ll min_diff(vector<ll>& v1, vector<ll>& v2) {
    ll result = 1e18;
    ll i1 = 0;
    ll i2 = 0;

    while (i1 < v1.size() && i2 < v2.size()) {
        result = min(result, abs(v1[i1] - v2[i2]));
        if (v1[i1] < v2[i2]) {
            i1++;
        }
        else {
            i2++;
        }
    }

    return result;
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

ll solve() {
    vector<ll> comp1;
    dfs(1, comp1);

    sort(comp1.begin(), comp1.end());

    if (visited[N]) return 0;

    vector<ll> compN;
    dfs(N, compN);

    sort(compN.begin(), compN.end());

    ll ans = pow(min_diff(comp1, compN), 2);

    for (ll i = 2; i < N; i++) {
        if (!visited[i]) {
            cout << i << " " << get_cost(comp1, i) << " " << get_cost(compN, i) << "\n";
            ans = min(ans, get_cost(comp1, i) + get_cost(compN, i));
        }
    }

    return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "211202";
	freopen((fname + ".in").c_str(), "r", stdin);
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