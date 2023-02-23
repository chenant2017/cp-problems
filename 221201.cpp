#include <bits/stdc++.h>
#define MAX 200010
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll h[MAX];
ll N, AVG;
vector<ll> adj[MAX];
vector<pll> adj2[MAX];
bool visited[MAX];
ll ans = 0;

ll get_diff(ll i) { // surplus/deficit
    visited[i] = true;
    
    ll result = h[i] - AVG;

    for (auto j: adj[i]) {
        if (visited[j]) continue;
        ll diff = get_diff(j);
        result += diff;

        if (diff > 0) {
            adj2[j].push_back({i, diff});
            ans++;
        }
        else if (diff < 0) {
            adj2[i].push_back({j, -1 * diff});
            ans++;
        }
    }

    return result;
}

void top_sort(ll i, vector<ll>& v) {
    if (visited[i]) return;
    visited[i] = true;

    for (auto j: adj2[i]) {
        top_sort(j.f, v);
    }

    v.push_back(i);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "221201";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;
    
    ll sum = 0;

    for (ll i = 1; i <= N; i++) {
        cin >> h[i];
        sum += h[i];
    }

    AVG = sum / N;

    for (ll i = 0; i < N - 1; i++) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    get_diff(1);

    vector<ll> ts;
    fill(visited, visited + MAX, false);

    for (ll i = 1; i <= N; i++) {  
        top_sort(i, ts);
    }

    cout << ans << "\n";

    for (ll i = ts.size() - 1; i >= 0; i--) {
        for (auto j: adj2[ts[i]]) {
            cout << ts[i] << " " << j.f << " " << j.s << "\n";
        }
    }

	return 0;
}