//Silver 2021 Feb #2

#include <bits/stdc++.h>

#define ll long long
#define MAXN 66000

using namespace std;

ll N, K;
ll years[MAXN];
ll closestB[MAXN]; // closest before
ll closestA[MAXN]; // closest after
priority_queue<ll> reductions;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> K;

	for (ll i = 0; i < N; i++) {
		ll year;
		cin >> year;
		years[i] = year;
	}

	sort(years, years + N, greater<ll>());
	years[N] = 0;

	closestB[N] = 0;

	for (ll i = 0; i < N; i++) {
		closestA[i] = 12 * (years[i] / 12);
		closestB[i] = closestA[i] + 12;
	}

	ll non_reduced = closestB[0];
	
	for (ll i = 0; i < N; i++) {
		ll time = years[i] - years[i + 1];
		if (closestB[i + 1] < years[i] && closestA[i] > closestB[i + 1]) {
			ll reduction = closestA[i] - closestB[i + 1];
			if (reduction > 0) {
				reductions.push(reduction);
			}
		}
	}

	ll jumps = 1;

	while (!reductions.empty() && jumps < K) {
		non_reduced -= reductions.top();
		reductions.pop();
		jumps++;
	}

	cout << non_reduced << "\n";

	return 0;
}