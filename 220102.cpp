#include <bits/stdc++.h>
#define MAXN 300010
using namespace std;

typedef long long ll;

ll N;
ll heights[MAXN];

ll dists() {
    ll result = 0;
    stack<ll> mono;

    for (ll i = 0; i < N; i++) {
        while (!mono.empty() && heights[mono.top()] < heights[i]) {
            result += i - mono.top() + 1;
            mono.pop();
        }
        mono.push(i);
    }

    return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "220102";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) {
        cin >> heights[i];
    }

    ll ans = dists();
    reverse(heights, heights + N);
    ans += dists();

    cout << ans << "\n";
	
	return 0;
}