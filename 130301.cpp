#include <bits/stdc++.h>
#define MAX ((ll) 1e6)
using namespace std;

typedef long long ll;

ll N, M;
vector<ll> b, e;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "cowrace";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;

    b.push_back(0);
    e.push_back(0);

    ll v, t;

    for (ll i = 0; i < N; i++) {
        cin >> v >> t;

        for (ll j = 0; j < t; j++) {
            b.push_back(*b.rbegin() + v);
        }
    }

    for (ll i = 0; i < M; i++) {
        cin >> v >> t;

        for (ll j = 0; j < t; j++) {
            e.push_back(*e.rbegin() + v);
        }
    }

    /*for (auto i: b) {
        cout << i << "\t";
    }
    cout << "\n";

    for (auto i: e) {
        cout << i << "\t";
    }
    cout << "\n";*/

    ll ans = 0;
    char leader = '0';
    ll T = b.size();

    for (ll i = 0; i < T; i++) {
        if (b[i] > e[i] && leader != 'B') {
            leader = 'B';
            ans++;
        }
        else if (e[i] > b[i] && leader != 'E'){
            leader = 'E';
            ans++;
        }
    }

    cout << max(0ll, ans - 1) << "\n";

    return 0;
}