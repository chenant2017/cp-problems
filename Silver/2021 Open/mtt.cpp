#include <bits/stdc++.h>

#define ll long long
#define f first
#define s second
#define MAXN 30

using namespace std;

struct Vis {
	bool m[MAXN][MAXN] = {false};
};

struct State {
	ll r, c;
	string board;
};

ll N; 
string maze[MAXN][MAXN];
unordered_map<string, Vis> visited;
ll dr[4] = {0, 0, -1, 1};
ll dc[4] = {-1, 1, 0, 0};

bool winning(string board) {
	vector<ll> diff_pos[5] = {{},
							  {0, 3, 6},
							  {2},
							  {0, 1, 2},
							  {0}};
	
	ll diff;
	ll pos;
	for (ll i = 1; i <= 4; i++) {
		for (ll j: diff_pos[i]) {
			pos = j;
			diff = i;

			if (board[pos] == 'M' &&
				board[pos + diff] == 'O' &&
				board[pos + 2 * diff] == 'O') {
				return true;
			}

			pos = 8 - j;
			diff = -1 * i;

			if (board[pos] == 'M' &&
				board[pos + diff] == 'O' &&
				board[pos + 2 * diff] == 'O') {
				return true;
			}
		}
	}
	return false;
}

ll get_winning(State start) {
	queue<State> q;
	q.push(start);
	unordered_set<string> result;

	while (!q.empty()) {
		State curr = q.front();
		q.pop();

		if (visited[curr.board].m[curr.r][curr.c]) {
			continue;
		}

		visited[curr.board].m[curr.r][curr.c] = true;
		string cell = maze[curr.r][curr.c];
		if (cell[0] == 'M' || cell[0] == 'O') {
			int a = cell[1] - '0';
			int b = cell[2] - '0';

			int place_at = 3 * (a - 1) + (b - 1);
			if (curr.board[place_at] == '.') {
				curr.board[place_at] = cell[0];
				if (winning(curr.board)) {
					result.insert(curr.board);
					continue;
				}
			}
		}

		for (ll x = 0; x < 4; x++) {
			ll newr = curr.r + dr[x];
			ll newc = curr.c + dc[x];

			if (maze[newr][newc] != "###" && 
				!visited[curr.board].m[newr][newc]) {
				State next;
				next.r = newr;
				next.c = newc;
				next.board = curr.board;

				q.push(next);
			}
		}
	}
	return result.size();
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
			
	cin >> N;

	State start;
	start.board = ".........";

	for (ll i = 0; i < N; i++) {
		string row;
		cin >> row;
		for (ll j = 0; j < N; j++) {
			string block = row.substr(3 * j, 3);
			maze[i][j] = block;

			if (block == "BBB") {
				start.r = i;
				start.c= j; 
			}
		}
	}

	cout << get_winning(start) << "\n";


	return 0;
}
