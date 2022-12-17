#include <bits/stdc++.h>
#define MAXN 300010
using namespace std;

typedef long long ll;

ll N;
ll heights[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "frisbee";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) {
        cin >> heights[i];
    }

    stack<ll> mono;

    ll ans = 0;
    for (ll i = 0; i < N; i++) {
        while (!mono.empty() && heights[mono.top()] < heights[i]) {
            ans += i - mono.top() + 1;
            mono.pop();
        }
        if (!mono.empty()) {
            ans += i - mono.top() + 1;
        }
        mono.push(i);
    }
	
    cout << ans << "\n";

	return 0;
}