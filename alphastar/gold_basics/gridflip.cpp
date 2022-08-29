#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll M, N;

vector<vector<ll>> grid;

ll di[4] = {0, 0, 1, -1};
ll dj[4] = {-1, 1, 0, 0};

void toggle(ll i, ll j, vector<vector<ll>>& grid2) {
    grid2[i][j] = 1 - grid2[i][j];
    for (ll d = 0; d < 4; d++) {
        ll i2 = i + di[d];
        ll j2 = j + dj[d];

        if (0 <= i2 && i2 < M &&
            0 <= j2 && j2 < N) {
            grid2[i2][j2] = 1 - grid[i2][j2];
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "gridflip";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
    cin >> M >> N;
	
    for (ll i = 0; i < M; i++) {
        vector<ll> v;
        for (ll j = 0; j < N; j++) {
            ll a;
            cin >> a;
            v.push_back(a);
        }
        grid.push_back(v);
    }

    bool found = false;

    for (ll combo = 0; combo < 1 << N; combo++) {
        vector<vector<ll>> grid2 = grid;
        vector<vector<ll>> ans (M);

        for (ll i = 0; i < M; i++) {
            for (ll j = 0; j < N; j++) {
                ans[i].push_back(0);
            }
        }

        for (ll i = 0; i < N; i++) {
            if ((combo & (1 << (N - 1 - i))) > 0) { //must put parentheses around bit operation
                ans[0][i]++;
                toggle(0, i, grid2);
            }
        }

        for (ll i = 1; i < M; i++) {
            for (ll j = 0; j < N; j++) {
                if (grid2[i - 1][j] == 1) {
                    ans[i][j]++;
                    toggle(i, j, grid2);
                }
            }
        }

        ll total = 0;
        for (ll i = 0; i < N; i++) {
            total += grid2[M - 1][i];
        }

        if (total == 0) {
            found = true;
            for (ll i = 0; i < M; i++) {
                for (ll j = 0; j < N; j++) {
                    cout << ans[i][j] << " ";
                }
                cout << "\n";
            }
        
            break;
        }
    }

    if (!found) {
        cout << "IMPOSSIBLE\n";
    }

	return 0;
}