#include <bits/stdc++.h>
#define f first
#define s second
#define MAXN 1010
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pdl;

ll N, B;
pdl costs[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "gifts";
	freopen((fname + ".in").c_str(), "r", stdin);
	
	cin >> N >> B;
	
	for (ll i = 0; i < N; i++) {
		cin >> costs[i].f >> costs[i].s;
	}
	
	ll ans = -1;
	for (ll disc = 0; disc < N; disc++) {
		priority_queue<ll, vector<ll>, greater<ll>> cheapest;
		for (ll i = 0; i < N; i++) {
			if (i == disc) {
				cheapest.push(costs[i].f / 2 + costs[i].s);
			}
			else {
				cheapest.push(costs[i].f + costs[i].s);
			}
		}

		ll count = 0;
		ll cost = 0;
		while (!cheapest.empty() && cost + cheapest.top() <= B){
			cost += cheapest.top();
			cheapest.pop();
			count++;
		}

		if (count > ans) {
			ans = count;
		}
	}

	cout << ans << "\n";

	return 0;
}