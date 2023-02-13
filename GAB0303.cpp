#include <bits/stdc++.h>
#define MAXN 25
using namespace std;

typedef long long ll;

struct State {
    ll x1, y1;
    ll x2, y2;
    ll d1, d2;
    ll s;

    State(ll a, ll b, ll c, ll d, ll e, ll f, ll g) {
        x1 = a;
        y1 = b;
        x2 = c;
        y2 = d;
        d1 = e;
        d2 = f;
        s = g;
    }
};

ll N;
ll dx[] = {-1, 0, 1, 0};
ll dy[] = {0, 1, 0, -1};
string barn [MAXN];
bool visited[MAXN][MAXN][MAXN][MAXN][4][4];

bool in_bounds(ll x, ll y) {
    return (0 <= x && x < N && 0 <= y && y < N && barn[x][y] == 'E');
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAB0303";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) {
        cin >> barn[i];
    }

    queue<State> q;

    q.push(State(N - 1, 0, N - 1, 0, 0, 1, 0));

    while (!q.empty()) {
        State c = q.front();
        q.pop();

        bool& v = visited[c.x1][c.y1][c.x2][c.y2][c.d1][c.d2];
        if (v) {
            continue;
        }

        if (c.x1 == c.x2 && c.x2 == 0 && c.y1 == c.y2 && c.y2 == N - 1) {
            cout << c.s << " a\n";
            break;
        }

        cout << q.size() << "\n";

        v = true;

        // forward
        ll nx1 = c.x1, ny1 = c.y1, nx2 = c.x2, ny2 = c.y2;
        if (in_bounds(c.x1 + dx[c.d1], c.y1 + dy[c.d1])) {
            nx1 = c.x1 + dx[c.d1];
            ny1 = c.y1 + dy[c.d1];
        }
        if (in_bounds(c.x2 + dx[c.d2], c.y2 + dy[c.d2])) {
            nx2 = c.x2 + dx[c.d2];
            ny2 = c.y2 + dy[c.d2];
        }
        q.push(State(nx1, ny1, nx2, ny2, c.d1, c.d2, c.s + 1));

        for (ll r = -1; r <= 1; r++) {
            ll nd1 = (4 + c.d1 + r) % 4;
            ll nd2 = (4 + c.d2 + r) % 4;

            State nc = c;
            nc.d1 = nd1;
            nc.d2 = nd2;
            nc.s++;

            q.push(nc);
        }
    }
    
	
	return 0;
}