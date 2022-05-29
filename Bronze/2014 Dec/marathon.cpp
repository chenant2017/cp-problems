#include <bits/stdc++.h>
#include <cmath>

#define ll long long
#define MAX_N 100000

using namespace std;

struct check {
	int x, y;
};

ll manhattan(check, check);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s = "marathon";
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
	
	ll N;
	cin >> N;
	
	check checks[MAX_N];
	
	for (int i = 0; i < N; i++) {
		cin >> checks[i].x >> checks[i].y;
	}
	
	ll max_shorten = 0;
	ll dist, dist_skip, shorten;
	ll total_dist = manhattan(checks[0], checks[1]);
	
	for (int i = 1; i < N - 1; i ++) {
		dist = manhattan(checks[i], checks[i - 1]) + manhattan(checks[i], checks[i + 1]);
		dist_skip = manhattan(checks[i - 1], checks[i + 1]);
		shorten = dist - dist_skip;
		if (shorten > max_shorten) {
			max_shorten = shorten;
		}
		
		total_dist += manhattan(checks[i], checks[i + 1]);
	}
	
	cout << total_dist - max_shorten << "\n";
	
	return 0;
}

ll manhattan(check a, check b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}
	