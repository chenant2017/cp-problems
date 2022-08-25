//2022 Open #1

#include <bits/stdc++.h>
#define MAX 100010
using namespace std;

typedef long long ll;

ll N;
ll a[MAX];
ll v[MAX];
bool visited[MAX] = {false};
bool in_cycle[MAX] = {false};
vector<ll> path;

ll cycle_total(ll i) {
    //cout << "run " << i << '\n';
    path.clear();
    if (visited[i]) return 0;

    visited[i] = true;
    path.push_back(i);

    ll curr = a[i];
    while (!visited[curr]) {
        visited[curr] = true;
        path.push_back(curr);
        curr = a[curr];
    }

    if (in_cycle[curr]) return 0;

    ll smallest = pow(10, 9) + 5;
    ll total = 0;

    bool found = false;

    for (ll j = 0; j < path.size(); j++) {
        if (path[j] == curr) {
            found = true;
        }
        if (found) {
            in_cycle[path[j]] = true;
            total += v[path[j]];
            smallest = min(smallest, v[path[j]]);
        }
    }

    if (found) return total - smallest;
    return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "visits";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
    cin >> N;

    for (ll i = 1; i <= N; i++) {
        cin >> a[i] >> v[i];
    }


    ll ans = 0;
    for (ll i = 1; i <= N; i++) {
        ll ct = cycle_total(i);
        ans += ct;
        //cout << ct << "\n";
    }

    for (ll i = 1; i <= N; i++) {
        if (!in_cycle[i]) {
            ans += v[i];
        }
    }

    cout << ans << "\n";

	return 0;
}