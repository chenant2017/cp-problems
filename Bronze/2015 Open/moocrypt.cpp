#include <bits/stdc++.h>
#include <cmath>

#define ll long long
#define MAX 50

using namespace std;

void get_maps(char puzzle[][MAX], int N, int M, int maps[][26]) {
	char m, o;
	
	//rows
	for (int i = 0; i < N; i++) {
		for (int j = 2; j < M; j++) {
			if (puzzle[i][j] == puzzle[i][j - 1] && puzzle[i][j] != puzzle[i][j - 2]) {
				m = puzzle[i][j - 2];
				o = puzzle[i][j];
				
				maps[m - 'A'][o - 'A']++;
			}
		}
		
		for (int j = M - 3; j > -1; j--) {
			if (puzzle[i][j] == puzzle[i][j + 1] && puzzle[i][j] != puzzle[i][j + 2]) {
				m = puzzle[i][j + 2];
				o = puzzle[i][j];
				
				maps[m - 'A'][o - 'A']++;
			}
		} 
	}
	
	//columns
	for (int j = 0; j < M; j++) {
		for (int i = 2; i < N; i++) {
			if (puzzle[i][j] == puzzle[i - 1][j] && puzzle[i][j] != puzzle[i - 2][j]) {
				m = puzzle[i - 2][j];
				o = puzzle[i][j];
				
				maps[m - 'A'][o - 'A']++;
			}
		}
		
		for (int i = N - 3; i > -1; i--) {
			if (puzzle[i][j] == puzzle[i + 1][j] && puzzle[i][j] != puzzle[i + 2][j]) {
				m = puzzle[i + 2][j];
				o = puzzle[i][j];
				
				maps[m - 'A'][o - 'A']++;
			}
		}
	}
	
	//diagonals
	for (int i = 2; i < N; i++) {
		for (int j = 0; j < M - 2; j++) {
			if (puzzle[i][j] == puzzle[i - 1][j + 1] && puzzle[i][j] != puzzle[i - 2][j + 2]) {
				m = puzzle[i - 2][j + 2];
				o = puzzle[i][j];
				
				maps[m - 'A'][o - 'A']++;
			}
		}
	}
	
	for (int i = 0; i < N - 2; i++) {
		for (int j = 2; j < M; j++) {
			if (puzzle[i][j] == puzzle[i + 1][j - 1] && puzzle[i][j] != puzzle[i + 2][j - 2]) {
				m = puzzle[i + 2][j - 2];
				o = puzzle[i][j];
				
				maps[m - 'A'][o - 'A']++;
			}
		}
	}
	
	for (int i = 2; i < N; i++) {
		for (int j = 2; j < M; j++) {
			if (puzzle[i][j] == puzzle[i - 1][j - 1] && puzzle[i][j] != puzzle[i - 2][j - 2]) {
				m = puzzle[i - 2][j - 2];
				o = puzzle[i][j];
				
				maps[m - 'A'][o - 'A']++;
			}
		}
	}
	
	for (int i = 0; i < N - 2; i++) {
		for (int j = 0; j < M - 2; j++) {
			if (puzzle[i][j] == puzzle[i + 1][j + 1] && puzzle[i][j] != puzzle[i + 2][j + 2]) {
				m = puzzle[i + 2][j + 2];
				o = puzzle[i][j];
				
				maps[m - 'A'][o - 'A']++;
			}
		}
	}
}

int get_max(int matrix[][26], int size) {
	int ans = 0;
	
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < size; j++) {
			if (matrix[i][j] > ans) {
				ans = matrix[i][j];
			}
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s = "moocrypt";
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
	
	int N, M;
	char puzzle[MAX][MAX];
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> puzzle[i];
	}

	if (N < 3) {
		cout << "0\n";
		return 0;
	}
		
	int maps[26][26] = {0};
	get_maps(puzzle, N, M, maps);
	auto ans = get_max(maps, 26);
	
	cout << ans << "\n";
	
	return 0;
}