#include <bits/stdc++.h>
#include <cmath>

#define ll long long
#define MAX_N 1010

using namespace std;

ll N;
ll cows[MAX_N][MAX_N];

void flip_row(ll row) {
	for (ll i = 0; i < N; i++) {
		cows[row][i] *= -1;
	}
}

void flip_col(ll col) {
	for (ll i = 0; i < N; i++) {
		cows[i][col] *= -1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "leftout";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;
	
	for (ll i = 0; i < N; i++) {
		string row;
		cin >> row;
		for (ll j = 0; j < N; j++) {
			if (row[j] == 'L') {
				cows[i][j] = -1;
			}
			else {
				cows[i][j] = 1;
			}
		}
	}
	
	if (cows[0][0] == -1) {
		flip_row(0);
	}
	
	for (ll i = 1; i < N; i++) {
		if (cows[0][i] == -1) {
			flip_col(i);
		}
		if (cows[i][0] == -1) {
			flip_row(i);
		}
	}
	
	set<ll> rowsL, rowsR, colsL, colsR; 
	
	for (ll i = 1; i < N; i++) {
		for (ll j = 1; j < N; j++) {
			if (cows[i][j] == -1) {
				rowsL.insert(i);
				colsL.insert(j);
			}
			else {
				rowsR.insert(i);
				colsR.insert(j);
			}
		}
	}
	
	if (rowsR.size() == 0) {
		cout << "1 1\n";
		return 0;
	}
	
	if ((rowsL.size() == 1 && colsL.size() == N - 1)) {
		cout << *rowsL.begin() + 1 << " 1\n";
		return 0;
	}
	
	if ((colsL.size() == 1 && rowsL.size() == N - 1)) {
		cout << "1 " << *colsL.begin() + 1 << "\n";
		return 0;
	}
	
	if ((rowsL.size() == 1 && colsL.size() == 1)) {
		cout << *rowsL.begin() + 1 << " " << *colsL.begin() + 1 << "\n";
		return 0;
	}
	
	cout << "-1\n";
	return 0;
}