#include <bits/stdc++.h>
#define MAX 100010
using namespace std;

typedef long long ll;

ll T, N, M;
vector<vector<ll>> adj;
vector<ll> comp_of;
vector<vector<ll>> comps;
priority_queue<ll, vector<ll>, greater<ll>> costs;

void dfs(ll start, vector<ll>& v, ll comp) {
    if (comp_of[start] != -1) return;
    comp_of[start] = comp;
    v.push_back(start);

    for (auto i: adj[start]) {
        if (comp_of[i] == -1) dfs(i, v, comp);
    }
}

ll min_diff_internal(vector<ll>& v1, vector<ll>& v2) {
    //if (v1.size() > v2.size()) swap(v1, v2);
    ll result = N;

    for (auto i: v1) {
        auto it1 = lower_bound(v2.begin(), v2.end(), i);

        if (it1 != v2.end()) {
            result = min(result, *it1 - i);
        }
        if (it1 != v2.begin()) {
            it1--;
            result = min(result, i - *it1);
        }
    }

    return result;
}

ll min_diff(vector<ll>& v1, vector<ll>& v2) {
    if (v1.size() < v2.size()) return min_diff_internal(v1, v2);
    else return min_diff_internal(v2, v1);
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

        adj = vector<vector<ll>>(N + 1, vector<ll>());
        comp_of = vector<ll>(N + 1, -1);
        comps.clear();
        costs = priority_queue<ll, vector<ll>, greater<ll>>();

        for (ll i = 0; i < M; i++) {
            ll a, b;
            cin >> a >> b; 

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        ll comp = 0;
        for (ll i = 1; i <= N; i++) {
            if (comp_of[i] == -1) {
                vector<ll> v;
                dfs(i, v, comp);

                sort(v.begin(), v.end());
                comps.push_back(v);
                comp++;
            }
        }

        ll ans = -1;

        for (ll k = 0; k < comps.size(); k++) {
            ll diff1 = min_diff(comps[k], comps[comp_of[1]]);
            ll diff2 = min_diff(comps[k], comps[comp_of[N]]);

            ll cost = pow(diff1, 2) + pow(diff2, 2);

            if (ans == -1 || cost < ans) ans = cost;
        }

        cout << ans << "\n";
    }

	return 0;
}