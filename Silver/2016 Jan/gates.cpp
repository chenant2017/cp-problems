#include <bits/stdc++.h>

#define ll long long
#define MAXN 5000

using namespace std;

ll N;
ll upperN;
bool fences[MAXN][MAXN] = {false};
ll di[4] = {0, 0, -1, 1};
ll dj[4] = {-1, 1, 0, 0};

void floodfill(ll i, ll j) {
	bool in_bounds = (0 <= i && i < upperN && 0 <= j && j < upperN);
	if (!in_bounds || fences[i][j]) {
		return;
	}

	queue<pair<ll, ll>> q;

	q.push(pair<ll, ll>({i, j}));

	while (!q.empty()) {
		//cout << q.size() << "\n";
		ll curri, currj;
		curri = q.front().first;
		currj = q.front().second;
		q.pop();

		in_bounds = (0 <= curri && curri < upperN && 0 <= currj && currj <upperN);
		if (!in_bounds || fences[curri][currj]) {
			continue;
		}

		fences[curri][currj] = true;
		for (ll x = 0; x < 4; x++) {
			ll newi = curri + di[x];
			ll newj = currj + dj[x];

			//cout << newi << " " << newj << "\n";

			in_bounds = (0 <= newi && newi < upperN && 0 <= newj && newj < upperN);
			if (in_bounds && !fences[newi][newj]) {
				q.push(pair<ll, ll>({newi, newj}));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "gates";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);

	cin >> N;

	string steps;
	cin >> steps;

	upperN = (N + 5) * 4;

	ll x = upperN / 2;
	ll y = upperN / 2;

	fences[x][y] = true;

	for (ll i = 0; i < N; i++){
		char step = steps[i];
		for (ll j = 0; j < 2; j++) {
			switch (step) {
				case 'N':
					y--;
					break;
				case 'S':
					y++;
					break;
				case 'E':
					x++;
					break;
				case 'W':
					x--;
					break;
			}
			fences[x][y] = true;
		}
	}

	ll regions = 0;

	for (ll i = 0; i < upperN; i++) {
		for (ll j = 0; j < upperN; j++) {
			if (fences[i][j]) {
				//cout << i << " " << j << "\n";
				continue;
			}
			floodfill(i, j);
			regions++;
		}
	}

	cout << regions - 1 << "\n";

	return 0;
}