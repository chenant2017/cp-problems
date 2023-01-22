#include <bits/stdc++.h>
#define MAX 1010
#define f first 
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef tuple<ll, bool, ll, ll> tp;

ll N, M;
ll sol[MAX][MAX][2]; // i, j, orange
bool v[MAX][MAX][2];
ll maze[MAX][MAX]; 
ll di[] = {0, 0, -1, 1};
ll dj[] = {1, -1, 0, 0};

pair<bool, tp> slide(ll d, ll i, ll j, ll did, ll djd) {
    while (0 <= i && i < N &&
           0 <= j && j < M &&
           maze[i][j] == 4) {
        d++;
        i += did;
        j += djd;
    }

    //cout << "slide " << i << " " << j << "\n";

    if (0 <= i && i < N &&
        0 <= j && j < M) {
        return {true, tp({d, false, i, j})};
    }
    else {
        return {false, tp({0, 0, 0, 0})};
    }
}

bool valid(tp& n) {
    ll d, o, i, j;
    tie(d, o, i, j) = n;
    switch (maze[i][j]) {
        case 0:
            return false;
        case 3:
            if (!o) {
                return false;
            }
        case 1: 
            if (d < sol[i][j][o]) {
                sol[i][j][o] = d;
                return true;
            }
            return false;
        case 2:
            n = {d, true, i, j};
            if (d < sol[i][j][true]) {
                sol[i][j][true] = d;
                return true;
            }
            return false;
    }
    return false;
}

void bfs() {
    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < M; j++) {
            for (ll k = 0; k < 2; k++) {
                sol[i][j][k] = 1e18;
            }
        }
    }

    priority_queue<tp, vector<tp>, greater<tp>> pq;
    if (maze[0][0] == 1) {
        sol[0][0][false] = 0;
        pq.push({0, false, 0, 0});
    }
    else if (maze[0][0] == 2) {
        sol[0][0][true] = 0;
        pq.push({0, true, 0, 0});
    }
    else {
        return;
    }

    while (!pq.empty()) {
        auto c = pq.top();
        pq.pop();
        ll d, i, j;
        bool o;
        tie(d, o, i, j) = c;

        if (v[i][j][o]) continue;
        v[i][j][o] = true;

        //cout << d << " " << o << " " << i << " " << j << " here\n";

        for (ll dd = 0; dd < 4; dd++) {
            ll ni = i + di[dd];
            ll nj = j + dj[dd];

            if (0 <= ni && ni < N &&
                0 <= nj && nj < M) {

                if (maze[ni][nj] == 4) {
                    auto sl = slide(d + 1, ni, nj, di[dd], dj[dd]);
                    if (sl.f) {
                        if (valid(sl.s)) {
                            pq.push(sl.s);
                            //cout << "aasdfsdaf\n";
                            //cout << "pushed\n";
                        }
                    }
                    else {
                        break;
                    }
                }
                else {
                    //cout << d + 1 << " " << o << " " << ni << " " << nj << "\n";
                    tp n = {d + 1, o, ni, nj};
                    if (valid(n)) {
                        pq.push(n);
                        //cout << d + 1 << " " << o << " " << ni << " " << nj << "\n";
                        //cout << "pushed\n";
                    }
                }
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAA1001";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;

    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < M; j++) {
            cin >> maze[i][j];
        }
    }

    bfs();

    ll ans = min(sol[N - 1][M - 1][false], sol[N - 1][M - 1][true]);

    if (ans == 1e18) {
        cout << "-1\n";
    }
    else {
        cout << ans << "\n";
    }
	
	return 0;
}