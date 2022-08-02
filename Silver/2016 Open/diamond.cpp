#include <bits/stdc++.h>

#define ll long long
#define MAXN 50010

using namespace std;

ll N, K;
ll diamonds[MAXN];
ll sizes[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "diamond";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> K;

	for (ll i = 0; i < N; i++) {
		cin >> diamonds[i];
	}

	sort(diamonds, diamonds + N);

	ll start = 0;
	ll end = 0;

	for (; start < N; start++) {
		while (end + 1 < N && 
			   diamonds[end + 1] - diamonds[start] <= K) {
			end++;
		}
		sizes[start] = end - start + 1;
	}

	ll max_sizes[MAXN];
	max_sizes[N] = 0;

	ll max_size = -1;
	for (ll i = N - 1; i >= 0; i--) {
		if (sizes[i] > max_size) {
			max_size = sizes[i];
		}
		max_sizes[i] = max_size;
	}

	ll ans = -1;
	for (ll i = 0; i < N; i++) {
		ll total = sizes[i] + max_sizes[i + sizes[i]];
		if (total > ans) {
			ans = total;
		}
	}

	cout << ans << "\n";


	return 0;
}