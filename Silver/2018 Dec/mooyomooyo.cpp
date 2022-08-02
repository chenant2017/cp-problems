#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define MAXN 110
#define f first
#define s second

deque<char> board[10];
ll N, K;
ll di[4] = {0, 0, 1, -1};
ll dj[4] = {1, -1, 0, 0};
vector<pll> v;

vector<pll> fill(ll i, ll j, bool visited[10][MAXN]) {
	vector<pll> result;
	queue<pll> q;
	q.push(pll({i, j}));
	ll count = 0;

	while (!q.empty()) {
		pll curr = q.front();
		q.pop();

		if (visited[curr.f][curr.s]) continue;

		visited[curr.f][curr.s] = true;
		result.push_back(curr);
		count++;

		for (ll d = 0; d < 4; d++) {
			pll next;
			next.f = curr.f + di[d];
			next.s = curr.s + dj[d];
			if (next.f >= 0 && next.f < 10 &&
				next.s >= 0 && 
				next.s < board[next.f].size() &&
				!visited[next.f][next.s] && 
				board[next.f][next.s] == board[curr.f][curr.s]) {
				q.push(next);
			}
		}
	}
	if (count >= K) return result;
	return v;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "mooyomooyo";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> K;

	for (ll i = 0; i < N; i++) {
		string row;
		cin >> row;
		for (ll j = 0; j < 10; j++) {
			if (row[j] != '0') board[j].push_front(row[j]);
		}
	}

	while (true) {
		bool visited[10][MAXN] = {false};
		ll change = 0;
		for (ll i = 0; i < 10; i++) {
			for (ll j = 0; j < board[i].size(); j++) {
				if (!visited[i][j]) {
					auto result = fill(i, j, visited);

					for (auto k: result) {
						board[k.f][k.s] = 0;
						change++;
					}
				}
			}
		}

		if (change == 0) break;

		for (ll i = 0; i < 10; i++) {
			deque<char> next;
			for (ll j = 0; j < board[i].size(); j++) {
				if (board[i][j] != 0) {
					next.push_back(board[i][j]);
				}
			}
			board[i] = next;
		}
	}

	for (ll i = N - 1; i >= 0; i--) {
		for (ll j = 0; j < 10; j++) {
			if (i >= board[j].size()) {
				cout << 0;
			}
			else {
				cout << board[j][i];
			}
		}
		cout << "\n";
	}

	return 0;
}