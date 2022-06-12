#include <bits/stdc++.h>
#include <cmath>

#define ll long long
#define MAXN 1010

using namespace std;

ll N;
string output[MAXN];
bool visited[MAXN][MAXN] = {false};
int di[4] = {0, 0, 1, -1};
int dj[4] = {1, -1, 0, 0};
ll perim;
ll area;
ll ansp = 4 * pow(MAXN, 2);
ll ansa = 0;

void floodfill(ll i, ll j) {
	if (visited[i][j]) {
		return;
	}

	visited[i][j] = true;
	area++;

	for (int d = 0; d < 4; d++) {
		ll newi = i + di[d];
		ll newj = j + dj[d];

		if (newi >= 0 && newi < N &&
			newj >= 0 && newj < N) {

			if (output[newi][newj] == '#') {
				floodfill(newi, newj);
			}
			else {
				perim++;
			}
		}
		else {
			perim++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "perimeter";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

	for (ll i = 0; i < N; i++) {
		cin >> output[i];
	}

	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < N; j++) {
			if (output[i][j] == '.' || visited[i][j]) {
				continue;
			}
			perim = 0;
			area = 0;
			floodfill(i, j);
			if (area > ansa) {
				ansa = area;
				ansp = perim;
			}
			else if (area == ansa) {
				if (perim < ansp) {
					ansp = perim;
				}
			}
		}
	}

	cout << ansa << " " << ansp << "\n";

	return 0;
}