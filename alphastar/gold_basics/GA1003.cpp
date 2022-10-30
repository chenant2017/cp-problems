#include <bits/stdc++.h>
#define MAXN 55
#define MAXM 55
using namespace std;

typedef long long ll;

ll M, N;
ll plan[MAXN][MAXM];
ll rooms[MAXN][MAXM] = {{0}};
ll sizes[MAXN * MAXM] = {0};

ll di[4] = {0, -1, 0, 1};
ll dj[4] = {-1, 0, 1, 0};

void floodfill(ll i, ll j, ll room) {
    rooms[i][j] = room;
    sizes[room]++;
    for (ll d = 0; d < 4; d++) {
        ll nexti = i + di[d];
        ll nextj = j + dj[d];

        if (0 <= nexti && nexti < N &&
            0 <= nextj && nextj < M) {
            if ((plan[i][j] & (1 << d)) == 0 &&
                rooms[nexti][nextj] == 0) {
                floodfill(nexti, nextj, room);
            }
        }
    }
}       

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "apartment";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> M >> N;

    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < M; j++) {
            cin >> plan[i][j];
        }
    }

    ll room = 0;

    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < M; j++) {
            if (rooms[i][j] == 0) {
                room++;
                floodfill(i, j, room);
            }
           
        }
    }

    ll largest = 0;

    for (ll i = 1; i <= room; i++) {
        largest = max(sizes[i], largest);
    }

    ll max_poss = 0;

    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < M - 1; j++) {
            if ((plan[i][j] & (1 << 2)) != 0) {
                ll room1 = rooms[i][j];
                ll room2 = rooms[i][j + 1];
                if (room1 != room2) {
                    max_poss = max(max_poss, sizes[room1] + sizes[room2]);
                }
            }
        }
    }

    for (ll i = 0; i < N - 1; i++) {
        for (ll j = 0; j < M; j++) {
            if ((plan[i][j] & (1 << 3)) != 0) {
                ll room1 = rooms[i][j];
                ll room2 = rooms[i + 1][j];
                if (room1 != room2) {
                    max_poss = max(max_poss, sizes[room1] + sizes[room2]);
                }
            }
        }
    }

    cout << room << "\n";
    cout << largest << "\n";
    cout << max_poss << "\n";
	
	return 0;
}