#include <bits/stdc++.h>
#define MAX 200010
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

typedef tuple<ll, ll, ll> tll;


ll N, M;
ll ans[MAX];
ll a[MAX];
vector<tll> adj[MAX];

void dfs(ll i, ll t) {
    //cout << i << " " << t << "\n";
    auto it = lower_bound(adj[i].begin(), adj[i].end(), tll({t, 0, 0}));

    for (; it != adj[i].end(); it++) {
        ll r, d, s;
        tie(r, d, s) = *it;

        if (s < ans[d]) {
            ans[d] = s;
            dfs(d, s + a[d]);
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "230203";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;

    ll c, r, d, s;

    for (ll i = 0; i < M; i++) {
        cin >> c >> r >> d >> s;

        adj[c].emplace_back(r, d, s);
    }

    for (ll i = 1; i <= N; i++) {
        cin >> a[i];
        ans[i] = 1e18;
        sort(adj[i].begin(), adj[i].end());
    }

    ans[1] = 0;
    dfs(1, 0);

    for (ll i = 1; i <= N; i++) {
        if (ans[i] == 1e18) {
            cout << -1 << "\n";
        }
        else {
            cout << ans[i] << "\n";
        }
    }

	
	return 0;
}