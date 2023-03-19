#include <bits/stdc++.h>
#define MAX 100010
using namespace std;

typedef long long ll;

ll N;
ll a[MAX];
vector<ll> b[MAX];
ll v[MAX];
bool visited[MAX];

ll get_shortest(ll i) {
    ll p1 = i;
    ll p2 = a[i];

    while (p1 != p2) {
        p1 = a[p1];
        p2 = a[a[p2]];
    }

    ll shortest = v[p1];

    //cout << p1 << "\n";

    p2 = a[p2];
    shortest = min(shortest, v[p2]);

    //cout << p2 << "\n";

    while (p1 != p2) {
        p2 = a[p2];
        shortest = min(shortest, v[p2]);
        //cout << p2 << " " << v[p2] << "\n";
    }

    return shortest;
}

void dfs(ll i) {
    if (visited[i]) return;
    visited[i] = true;

    //cout << i << "\n";

    dfs(a[i]);

    for (auto j: b[i]) {
        dfs(j);
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "22OP01";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    ll ans = 0;

    for (ll i = 1; i <= N; i++) {
        cin >> a[i];
        cin >> v[i];
        b[a[i]].push_back(i);
        ans += v[i];
    }

    for (ll i = 1; i <= N; i++) {
        if (!visited[i]) {
            //cout << "\n";
            dfs(i);
            ans -= get_shortest(i);
        }
    }

    cout << ans << "\n";
	
	return 0;
}