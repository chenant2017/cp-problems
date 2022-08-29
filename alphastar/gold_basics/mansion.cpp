#include <bits/stdc++.h>
#define MAXW 80
#define MAXH 205
#define f first 
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll W, H;
string maze[MAXH];
vector<pll> exits;
ll exit1[MAXH][MAXW] = {{0}};
ll exit2[MAXH][MAXW] = {{0}};
ll di[4] = {0, 0, -1, 1};
ll dj[4] = {1, -1, 0, 0};

void bfs(ll i, ll j, ll exit[MAXH][MAXW]) {
    queue<tll> q;
    q.push(tll({i, j, 1}));

    while (!q.empty()) {
        ll a, b, c;
        tie(a, b, c) = q.front();
        q.pop();
        if (exit[a][b] != 0) continue;
        exit[a][b] = c;

        for (ll d = 0; d < 4; d++) {
            ll nexta = a + di[d];
            ll nextb = b + dj[d];
            ll nexta2 = a + 2 * di[d];
            ll nextb2 = b + 2 * dj[d];

            if (nexta2 >= 0 && nexta2 <= 2 * H &&
                nextb2 >= 0 && nextb2 <= 2 * W &&
                exit[nexta2][nextb2] == 0 && 
                maze[nexta][nextb] == ' ' &&
                maze[nexta2][nextb2] == ' ') {
                q.push(tll({nexta2, nextb2, c + 1}));
            }   
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "mansion";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> W >> H;

    string s;
    getline(cin, s);

    for (ll i = 0; i <= 2 * H; i++) {
        getline(cin, maze[i]);
    }

    for (ll i = 1; i <= 2 * W; i += 2) {
        if (maze[0][i] == ' ') {
            exits.push_back(pll({0, i}));
        }
        if (maze[2 * H][i] == ' ') {
            exits.push_back(pll({2 * H, i}));
        }
    }

    for (ll i = 1; i <= 2 * H; i += 2) {
        if (maze[i][0] == ' ') {
            exits.push_back(pll({i, 0}));
        }
        if (maze[i][2 * W] == ' ') {
            exits.push_back(pll({i, 2 * W}));
        }
    }

    for (ll e = 0; e < 2; e++) {
        for (ll d = 0; d < 4; d++) {
            ll starti = exits[e].f + di[d];
            ll startj = exits[e].s + dj[d];
            if (starti >= 0 && starti <= 2 * H &&
                startj >= 0 && startj <= 2 * W &&
                maze[starti][startj] == ' ') {

                if (e == 0) {
                    bfs(starti, startj, exit1);
                }
                else {
                    bfs(starti, startj, exit2);
                }

                break;
            }
        }
    }

    ll ans = 0;

    for (ll i = 0; i <= 2 * H; i++) {
        for (ll j = 0; j <= 2 * W; j++) {
            ll dist = min(exit1[i][j], exit2[i][j]);
            ans = max(dist, ans);
        }
    }
	
    cout << ans << "\n";

	return 0;
}