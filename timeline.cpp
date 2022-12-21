#include <bits/stdc++.h>
#define MAXN 100010
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N, M, C;
vector<pll> adj[MAXN];
ll S[MAXN];
ll ans[MAXN] = {0};
vector<ll> top_sort;
bool visited[MAXN] = {false};

void dfs(ll i) {
     if (visited[i]) return;
     visited[i] = true;

     for (auto j: adj[i]) {
        if (!visited[j.f]) {
            dfs(j.f);
        }
     }

     top_sort.push_back(i);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "timeline";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M >> C;

    for (ll i = 1; i <= N; i++) {
        cin >> S[i];
    }

    for (ll i = 0; i < C; i++) {
        ll a, b, x;
        cin >> a >> b >> x;
        adj[a].push_back(pll({b, x}));
    }

    for (ll i = 1; i <= N; i++) {
        dfs(i);
    }
    
    reverse(top_sort.begin(), top_sort.end());

    for (auto i: top_sort) {
        ans[i] = max(ans[i], S[i]);
        for (auto j: adj[i]) {
            ans[j.f] = max(ans[j.f], ans[i] + j.s);
        }
    }
	
    for (ll i = 1; i <= N; i++) {
        cout << ans[i] << "\n";
    }

	return 0;
}