#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N, W;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAA0701";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> W;

    stack<ll> s;

    ll ans = 0;

    for (ll i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;

        while (!s.empty() && s.top() > y) {
            ans++;
            //cout << "-" << y << "\n";
            s.pop();
        }

        if (y != 0 && (s.empty() || y != s.top())) {
            s.push(y);
            //cout << y << "\n";
        }
    }

    cout << ans + s.size() << "\n";
	
	return 0;
}