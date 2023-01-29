#include <bits/stdc++.h>
#define MAX 60
using namespace std;

typedef long long ll;

ll T;
ll N, M;
string grid[MAX];
bool visited[MAX][MAX];
bool included[MAX][MAX];
ll di[] = {0, 0, 1, 1};
ll dj[] = {0, 1, 0, 1};

bool Lshape(ll i, ll j) { // top left corner
    ll count = 0;

    for (ll d = 0; d < 4; d++) {
        ll ni = i + di[d];
        ll nj = j + dj[d];
        if (grid[ni][nj] == '*') {
            count++;
        }
    }

    return count == 3;
}

bool valid(ll i, ll j) {
    for (ll d = 0; d < 4; d++) {
        ll ni = i + di[d];
        ll nj = j + dj[d];
        if (visited[ni][nj]) return false;
    }

    return true;
}

bool solve() {
    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < M; j++) {
            visited[i][j] = false;
            included[i][j] = false;
        }
    }

    for (ll i = 0; i < N - 1; i++) {
        for (ll j = 0; j < M - 1; j++) {

            if (!valid(i, j)) continue;

            if (Lshape(i, j)) {
                for (ll ni = i - 1; ni <= i + 2; ni++) {
                    if (ni < 0 || ni >= N) continue;
                    for (ll nj = j - 1; nj <= j + 2; nj++) {
                        if (nj < 0 || nj >= M) continue;
                        visited[ni][nj] = true;
                    }
                }

                for (ll d = 0; d < 4; d++) {
                    ll ni = i + di[d];
                    ll nj = j + dj[d];
                    if (grid[ni][nj] == '*') {
                        included[ni][nj] = true;
                    }
                }
            }
        }
    }

    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < M; j++) {
            if (grid[i][j] == '*' && !included[i][j]) return false;
        }
    }

    return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "1722F";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> T;

    while (T--) {
        cin >> N >> M;

        for (ll i = 0; i < N; i++) {
            cin >> grid[i];
        }

        if (solve()) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
	
	return 0;
}