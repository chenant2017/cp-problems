#include <bits/stdc++.h>
#define MAX 510
using namespace std;

typedef long long ll;

ll N;
ll elev[MAX][MAX];
bool visited[MAX][MAX];
ll di[] = {0, 0, -1, 1};
ll dj[] = {1, -1, 0, 0};

ll floodfill(ll i, ll j, ll d) {
    ll result = 0;
    if (visited[i][j]) return result;
    visited[i][j] = true;
    result++;

    for (ll dd = 0; dd < 4; dd++) {
        ll ni = i + di[dd];
        ll nj = j + dj[dd];

        if (0 <= ni && ni < N &&
            0 <= nj && nj < N &&
            abs(elev[ni][nj] - elev[i][j]) <= d) {
            result += floodfill(ni, nj, d);
        }
    }

    return result;
}

bool works(ll d) {
    ll most = 0;

    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            visited[i][j] = false;
        }
    }

    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            if (!visited[i][j]) {
                ll ff = floodfill(i, j, d);
                //cout << ff << " ff\n";
                most = max(ff, most);
            }
        }
    }

   // cout << d << " " << most << "\n";

    if (N % 2 == 0) {
        return most >= pow(N, 2) / 2;
    }
    else {
        return most >= pow(N, 2) / 2 + 1;
    }
}

int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	
	string fname = "GAA0503";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            cin >> elev[i][j];
        }
    }

    ll d = 1e6 + 10;
    ll jump = (1e6) / 2;

    while (jump > 0) {
        //cout << d << " d\n";
        if (works(d - jump)) {
            d -= jump;
        }
        else {
            jump /= 2;
        }
    }

    cout << d << "\n";
	
	return 0;
}
