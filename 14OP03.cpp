#include <bits/stdc++.h>
#define MAXN 50010
using namespace std;

typedef long long ll;

ll N, M;
vector<ll> adj[MAXN];
ll color[MAXN];

ll ones(ll i, ll c, ll& v) {
    if (color[i] != 0) return 0;

    color[i] = c;
    ll result = (c == 1);
    v++;

    for (auto j: adj[i]) {
        if (color[j] == 0) {
            ll o = ones(j, 3 - c, v);
            if (o == -1) {
                return -1;
            }
            
            result += o;
        }
        else {
            if (color[j] != 3 - c) return -1;
        }
    }

    return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "decorate";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;

    for (ll i = 0; i < M; i++) {
        ll a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ll ans = 0;

    for (ll i = 1; i <= N; i++) {
        if (color[i] == 0) {
            ll v = 0;
            ll o = ones(i, 1, v);
            if (o == -1) {
                cout << "-1\n";
                return 0;
            }

            ans += max(o, v - o);
        }
    }

    cout << ans << "\n";
	
	return 0;
}