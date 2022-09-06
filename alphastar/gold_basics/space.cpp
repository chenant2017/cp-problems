#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef tuple<ll, ll, ll> tll;

ll A;
ll di[] = {-1, 1, 0, 0};
ll dj[] = {0, 0, 1, -1};
ll field[310][310];
bool visited[310][310] = {false};

ll bfs() {
    queue<tll> q;
    q.push({0, 0, 0});

    while (!q.empty()) {
        ll i, j, t;
        tie(i, j, t) = q.front();
        q.pop();

        if (visited[i][j] || t >= field[i][j]) continue;
        visited[i][j] = true;

        //cout << i << " " << j << " " << t << "\n";

        if (field[i][j] == 1010) {
            return t;
        }

        for (ll d = 0; d < 4; d++) {
            ll nexti = i + di[d];
            ll nextj = j + dj[d];

            if (nexti >= 0 && nextj >= 0 && 
                t + 1 < field[nexti][nextj]) {
                q.push(tll({nexti, nextj, t + 1}));
            }
        }
    }
    return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "space";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> A;

    for (ll i = 0; i < 310; i++) {
        for (ll j = 0; j < 310; j++) {
            field[i][j] = 1010;
        }
    }

    for (ll i = 0; i < A; i++) {
        ll x, y, t;
        cin >> x >> y >> t;
        field[x][y] = t;
        for (ll d = 0; d < 4; d++) {
            ll nexti = x + di[d];
            ll nextj = y + dj[d];
            if (nexti >= 0 && nextj >= 0) {
                field[nexti][nextj] = min(t, field[nexti][nextj]);
            }
        }
    }

    cout << bfs() << "\n";
	
	return 0;
}