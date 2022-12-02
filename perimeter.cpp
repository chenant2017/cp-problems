#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;

typedef long long ll;
ll N;
string output[MAXN];
ll di[] = {0, 0, 1, -1};
ll dj[] = {1, -1, 0, 0};
bool visited[MAXN][MAXN] = {false};

void dfs(ll i, ll j, ll& size, ll& perimeter) {
    if (visited[i][j]) return;
    visited[i][j] = true;
    size++;

    for (ll d = 0; d < 4; d++) {
        ll nexti = i + di[d];
        ll nextj = j + dj[d];

        bool in_range = (0 <= nexti && nexti < N &&
                        0 <= nextj && nextj < N);
        if (in_range) {
            if (output[nexti][nextj] == '.') {
                perimeter++;
            }
            else {
                dfs(nexti, nextj, size, perimeter);
            }
        }
        else {
            perimeter++;
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

    pair<ll, ll> ans = pair<ll, ll>({0, 0});

    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            if (output[i][j] == '#' && !visited[i][j]) {
                ll size = 0;
                ll perimeter = 0;
                dfs(i, j, size, perimeter);
                pair<ll, ll> poss = pair<ll, ll>({size, -perimeter});
                ans = max(ans, poss);
            }
        }
    }
	
    cout << ans.first << " " << -ans.second << "\n";

	return 0;
}