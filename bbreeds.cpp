#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;

string brands;
int N;

int ways[MAXN][MAXN] = {0};
int prefix[MAXN];

int get(int i, int g) {
	if (i < 0 || g < 0 ||
		i >= N || g >= N) return 0;
	return ways[i][g] % 2012;
}

int solve() {
	if (brands[0] == '(') {
		ways[0][1]++;
		ways[0][0]++;
	}

	for (int i = 1; i < N; i++) {
		for (int g = 0; g < N; g++) {
			if (brands[i] == '(') {
				ways[i][g] = get(i - 1, g - 1) + get(i - 1, g);
			}
			else {
				ways[i][g] = get(i - 1, g + 1);
				if (prefix[i] - g >= 0) {
					ways[i][g] += get(i - 1, g);
				}
			}
		}
	}
	return get(N - 1, 0);
}	

int main() {
    freopen("bbreeds.in", "r", stdin);
    freopen("bbreeds.out", "w", stdout);
	
	cin >> brands;
	N = brands.size();

	int sum = 0;
	for (int i = 0; i < N; i++) {
		if (brands[i] == '(') {
			sum++;
		}
		else {
			sum--;
		}
		prefix[i] = sum;
	}

	int ans = solve();
	cout << ans << "\n";
	
	return 0;
}