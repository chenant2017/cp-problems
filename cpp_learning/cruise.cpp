#include <bits/stdc++.h>
#include <cmath>

#define ll long long
#define MAXN 1010
#define MAXM 510
#define f first
#define s second	

using namespace std;

ll N, M, K;
vector<ll> operations[MAXN];
ll rivers[MAXN][2];
int steps[MAXM];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "cruise";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M >> K;

	for (ll i = 1; i <= N; i++) {
		cin >> rivers[i][0] >> rivers[i][1];
	}

	for (ll i = 0; i < M; i++) {
		string step;
		cin >> step;
		if (step[0] == 'L') {
			steps[i] = 0;
		}
		else {
			steps[i] = 1;
		}
	}

	for (ll i = 1; i <= N; i++) {
		ll result = i;
		for (ll j = 0; j < M; j++) {
			result = rivers[result][steps[j]];
		}
		operations[i].push_back(result);
	}

	for (ll i = 1; i <= ceil(log2(K)); i++) {
		for (ll j = 1; j <= N; j++) {
			ll twice_result = operations[ operations[j][i - 1] ][i - 1];
			operations[j].push_back(twice_result);
		}	
	}

	ll port = 1;
	ll moves = 0;
	ll moves_jump = pow(2, floor(log2(K)));

	while (moves != K) {
		if (moves + moves_jump <= K) {
			moves += moves_jump;
			port = operations[port][log2(moves_jump)];
		}
		else {
			moves_jump /= 2;
		}
	}

	cout << port << "\n";
	

	return 0;
}