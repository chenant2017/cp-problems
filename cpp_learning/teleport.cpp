#include <bits/stdc++.h>

#define ll long long
#define MAXN 100010
#define f first
#define s second

using namespace std;

ll N;
pair<ll, ll> moves[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "teleport";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

	double sum = 0;
	ll count = 0;

	for (ll i = 0; i < N; i++) {
		ll a, b;
		cin >> a >> b;

		moves[i].f = a;
		moves[i].s = b;

		if (abs(a) < abs(a - b)) {
			sum += b;
			count++;
		}
	}

	double y = sum / count;
	double dist = 0;

	for (ll i = 0; i < N; i++) {
		dist += min((double)abs(moves[i].f - moves[i].s), 
					abs(moves[i].f) + abs(y - moves[i].s));
	}

	cout << dist << "\n";

	return 0;
}