#include <bits/stdc++.h>
#define MAX 55
using namespace std;

typedef long long ll;

ll apartment[MAX][MAX];
ll room[MAX][MAX] = {0};
ll M, N;
ll di[] = {0, -1, 0, 1};
ll dj[] = {-1, 0, 1, 0};
vector<ll> sizes (1);

void floodfill(ll i, ll j, ll r, ll& size) {
    if (room[i][j] != 0) return;
    room[i][j] = r;
    size++;

    for (ll d = 0; d < 4; d++) {
        ll nexti = i + di[d];
        ll nextj = j + dj[d];
        if ((apartment[i][j] & (1 << d)) == 0 &&
            0 <= nexti && nexti < N &&
            0 <= nextj && nextj < M) {
            floodfill(nexti, nextj, r, size);
        }
    }
}

ll biggest_remove() {
    ll result = 0;
    for (ll i = 0; i < N - 1; i++) { //bottom wall
        for (ll j = 0; j < M; j++) {
            if ((apartment[i][j] & (1 << 3)) != 0 &&
                room[i][j] != room[i + 1][j]) {
                ll size2 = sizes[room[i][j]] + sizes[room[i + 1][j]];
                result = max(result, size2);
            }
        }
    }

    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < M - 1; j++) {
            if ((apartment[i][j] & (1 << 2)) != 0 &&
                room[i][j] != room[i][j + 1]) {
                ll size2 = sizes[room[i][j]] + sizes[room[i][j + 1]];
                result = max(result, size2);
            }
        }
    }
    return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GA1003";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> M >> N;

    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < M; j++) {
            cin >> apartment[i][j];
        }
    }

    ll r = 0;
    ll biggest = 0;

    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < M; j++) {
            if (room[i][j] == 0) {
                r++;
                ll size = 0;
                floodfill(i, j, r, size);
                sizes.push_back(size);
                biggest = max(biggest, size);
            }
        }
    }

    cout << r << "\n";
    cout << biggest << "\n";
    cout << biggest_remove() << "\n";
	
	return 0;
}