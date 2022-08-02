#include <bits/stdc++.h>
#include <cmath>

#define ll long long
#define MAXN 6

using namespace std;

ll N;
string hshoes[MAXN];
int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};

ll dfs(ll i, ll j, bool closing, ll opened, 
	   ll closed, bool visited[MAXN][MAXN]) {

	if (i < 0 || j < 0 ||
		i >= N || j >= N) {
		return 0;
	}
	if (visited[i][j]) {
		return 0;
	}

	visited[i][j] = true;

	if (hshoes[i][j] == '(') {
		if (closing) {
			visited[i][j] = false;
			return 0;
		}
		opened++;
	}
	else {
		closed++;
		if (closing) {
			if (opened == closed) {
				visited[i][j] = false;
				return opened;
			}
		}
		else {
			closing = true;
		}
	}

	ll result = 0;

	for (int x = 0; x < 4; x++) {
		ll a = dfs(i + di[x], j + dj[x], closing, opened, closed, visited);
		if (a > result) {
			result = a;
		}
	}

	visited[i][j] = false;

	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "hshoe";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

	for (ll i = 0; i < N; i++) {
		cin >> hshoes[i];
	}

	bool visited[MAXN][MAXN] = {false};
	cout << dfs(0, 0, false, 0, 0, visited) * 2 << "\n";

	return 0;
}