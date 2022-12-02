#include <bits/stdc++.h>
#define MAXN 10000
using namespace std;

typedef long long ll;

ll N, Tmax;
ll cows[MAXN];

bool works(ll K) {
    priority_queue<ll, vector<ll>, greater<ll>> q;
    ll i;
    for (i = 0; i < K; i++) {
        q.push(cows[i]);
    }
    for (i = K; i < N; i++) {
        ll next = q.top() + cows[i];
        q.pop();
        q.push(next);
    }
    ll result = q.top();
    while (!q.empty()) {
        result = q.top();
        q.pop();
    }
    return result <= Tmax;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "pasture";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> Tmax;
	
    for (ll i = 0; i < N; i++) {
        cin >> cows[i];
    }

    ll K = 0;
    ll jump = N / 2;
  
    while (jump > 0) {
        if (works(K + jump)) {
            jump /= 2;
        }
        else {
            K += jump;
        }
    }

    ll ans = K + 1;

    cout << ans << "\n";

	return 0;

}