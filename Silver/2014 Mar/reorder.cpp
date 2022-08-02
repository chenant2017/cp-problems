#include <bits/stdc++.h>
#include <cmath>

#define ll long long
#define MAXN 110

using namespace std;

ll N;
ll A[MAXN];
ll B[MAXN];
ll goal[MAXN];

bool visited[MAXN] = {false};

ll get_cycle_size(ll start_loc) {
	ll result = 0;
	ll curr = start_loc;

	while (!visited[curr]) {
		visited[curr] = true;
		result++;
		//cout << A[curr] << "\n";
		curr = goal[A[curr]];

	}
	//cout << "\n";
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "reorder";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

	for (ll i = 1; i <= N; i++) {
		cin >> A[i];
	}

	for (ll i = 1; i <= N; i++) {
		cin >> B[i];
	}

	for (ll i = 1; i <= N; i++) {
		goal[B[i]] = i;
	}

	ll max_size = -1;
	ll num_cycles = 0;

	for (ll i = 1; i <= N; i++) {
		
		ll size = get_cycle_size(i);
		if (size > 1) {
			num_cycles++;
			if (size > max_size) {
				max_size = size;
			}
		}
	}

	cout << num_cycles << " " << max_size << "\n";

	return 0;
}