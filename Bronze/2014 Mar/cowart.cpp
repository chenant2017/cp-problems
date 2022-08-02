#include <bits/stdc++.h>
#include <cmath>

#define ll long long
#define MAXN 110

using namespace std;

ll N;
string painting[MAXN];
ll regions;
ll di[4] = {0, 0, 1, -1};
ll dj[4] = {1, -1, 0, 0};

void dfs(ll i, ll j, bool visited[MAXN][MAXN], bool is_human) {
	
	if (visited[i][j]) {
		return;
	}
	//cout << i << " " << j << "\n";
	visited[i][j] = true;
	for (ll x = 0; x < 4; x++) {
		ll ii = di[x];
		ll jj = dj[x];
		if (i + ii >= 0 && i + ii < N &&
			j + jj >= 0 && j + jj < N &&
			!visited[i + ii][j + jj]) {

			if (is_human) {
				if (painting[i][j] == painting[i + ii][j + jj]) {
					dfs(i + ii, j + jj, visited, is_human);
				}
			}
			else {
				if (painting[i][j] == 'R' || painting[i][j] == 'G') {
					if (painting[i + ii][j + jj] == 'R' || painting[i + ii][j + jj] == 'G') {
						dfs(i + ii, j + jj, visited, is_human);
					}
				}
				else {
					if (painting[i][j] == painting[i + ii][j + jj]) {
						dfs(i + ii, j + jj, visited, is_human);
					}
				}
			} 
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "cowart";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;
	for (ll i = 0; i < N; i++) {
		cin >> painting[i];
	}

	regions = 0;
	bool visited[MAXN][MAXN] = {false};
	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < N; j++) {
			if (!visited[i][j]) {
				dfs(i, j, visited, true);
				regions++;
			}
		}
	}

	cout << regions << " ";

	regions = 0;
	bool visited2[MAXN][MAXN] = {false};
	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < N; j++) {
			if (!visited2[i][j]) {
				dfs(i, j, visited2, false);
				regions++;
			}
		}
	}

	cout << regions << "\n";
	return 0;
}