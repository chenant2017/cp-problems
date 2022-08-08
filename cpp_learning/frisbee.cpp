#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N;
vector<ll> heights;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "frisbee";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

	for (ll i = 0; i < N; i++) {
		ll h;
		cin >> h;
		heights.push_back(h);
	}

	ll ans = 0;
	stack<ll> mono;
	mono.push(0);

	for (ll i = 1; i < N; i++) {
		while (!mono.empty() && heights[i] > heights[mono.top()]) {
			ans += i - mono.top() + 1;
			mono.pop();
		}
		if (!mono.empty()) {
			ans += i - mono.top() + 1;
		}
		mono.push(i);
	}

	/*stack<ll> mono2;
	mono.push(N - 1);

	for (ll i = N - 1; i >= 0; i--) {
		while (!mono.empty() && heights[i] > heights[mono.top()]) {
			ans += mono.top() - i;
			cout << 
			mono.pop();
		}
		if (!mono.empty()) {
			ans += mono.top() - i;
		}
		mono.push(i);
	}*/

	cout << ans << "\n";

	
	return 0;
}