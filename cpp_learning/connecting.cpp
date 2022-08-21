#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll T, N, M;

vector<bool> visited;
vector<vector<ll>> adj;
vector<vector<ll>> comps;

vector<ll> dfs(ll i) {
    vector<ll> result;
    if (visited[i]) {
        return result;
    }
    visited[i] = true;
    result.push_back(i);
    for (auto j: adj[i]) {
        vector<ll> v = dfs(j);
        result.insert(result.end(), v.begin(), v.end());
    }
    return result;
}

ll cheapest_path(ll i, ll j) {
    sort(comps[i].begin(), comps[i].end());
    sort(comps[j].begin(), comps[j].end());

    ll p = 0, q = 0;

    ll result = pow(N, 2);

    while (p < comps[i].size() && q < comps[j].size()) {
        ll diff = abs(comps[i][p] - comps[j][q]);
        result = min(diff, result);

        if (comps[i][p] < comps[j][q]) p++;
        else q++;
    }

    return pow(result, 2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "connecting";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> T;

    for (ll t = 0; t < T; t++) {
        cin >> N >> M;

        ll ans = 5 * pow(N, 2);

        visited.resize(N + 1);
        for (ll i = 1; i <= N; i++) {
            visited[i] = false;
        }
        adj.clear();
        adj.resize(N + 1);
        comps.clear();

        for (ll i = 0; i < M; i++) {
            ll a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        ll comp1 = -1;
        ll compN = -1;

        for (ll i = 1; i <= N; i++) {
            auto comp = dfs(i);
            comps.push_back(comp);
            if (visited[1] && comp1 == -1) comp1 = comps.size() - 1;
            if (visited[N] && compN == -1) compN = comps.size() - 1;
        }

        if (comp1 == compN)  {
            cout << "0\n";
            continue;
        }

        for (ll i = 0; i < comps.size(); i++) {
            ll cost = cheapest_path(comp1, i) + cheapest_path(compN, i);
            ans = min(ans, cost);
        }

        ans = min(ans, (ll)pow(N - 1, 2));

        cout << ans << "\n";
    }
	
	return 0;
}