#include <bits/stdc++.h>
#define MAX 100010
using namespace std;

typedef long long ll;

set<ll> reaches[MAX];

ll N, K;
ll cows[MAX];
ll ind[MAX];
ll ans[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "mooves";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".ouzt").c_str(), "w", stdout);
	
	cin >> N >> K;

	for (ll i = 1; i <= N; i++) {
		cows[i] = i;
		reaches[i].insert(i);
	}

	for (ll i = 1; i <= K; i++) {
		ll a, b;
		cin >> a >> b;

		swap(cows[a], cows[b]);
		reaches[cows[a]].insert(b);
		reaches[cows[b]].insert(a);
	}

	for (ll i = 1; i <= N; i++) {
		ind[cows[i]] = i;
	}

	for (ll i = 1; i <= N; i++) {
		set<ll> result = reaches[cows[i]];
		ll curr = i;
		while (curr != cows[i]) {
			result.insert(reaches[curr].begin(), reaches[curr].end());
			curr = ind[curr];
		}
		ans[cows[i]] = result.size();
	}

	for (ll i = 1; i <= N; i++) {
		cout << ans[i] << "\n";
	}
	
	return 0;
}