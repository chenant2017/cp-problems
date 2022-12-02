#include <bits/stdc++.h>
#define MAXW 80
#define MAXH 205
#define f first 
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pdl;
typedef tuple<ll, ll, ll> tll;

ll W, H;
string maze[MAXH];
vector<pdl> distss;
ll dists[MAXH][MAXW] = {{0}};
ll di[4] = {0, 0, -1, 1};
ll dj[4] = {1, -1, 0, 0};
vector<ll> starts;

void bfs() {
    queue<tll> q;
    q.push(tll({starts[0], starts[1], 1}));
    q.push(tll({starts[2], starts[3], 1}));

    while (!q.empty()) {
        ll a, b, c;
        tie(a, b, c) = q.front();
        q.pop();
        if (dists[a][b] != 0) continue;
        dists[a][b] = c;

        for (ll d = 0; d < 4; d++) {
            ll nexta = a + di[d];
            ll nextb = b + dj[d];
            ll nexta2 = a + 2 * di[d];
            ll nextb2 = b + 2 * dj[d];

            if (nexta2 >= 0 && nexta2 <= 2 * H &&
                nextb2 >= 0 && nextb2 <= 2 * W &&
                dists[nexta2][nextb2] == 0 && 
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
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> W >> H;

    string s;
    getline(cin, s);

    for (ll i = 0; i <= 2 * H; i++) {
        getline(cin, maze[i]);
    }

    for (ll i = 1; i <= 2 * W; i += 2) {
        if (maze[0][i] == ' ') {
            distss.push_back(pll({0, i}));
        }
        if (maze[2 * H][i] == ' ') {
            distss.push_back(pll({2 * H, i}));
        }
    }

    for (ll i = 1; i <= 2 * H; i += 2) {
        if (maze[i][0] == ' ') {
            distss.push_back(pll({i, 0}));
        }
        if (maze[i][2 * W] == ' ') {
            distss.push_back(pll({i, 2 * W}));
        }
    }

    for (ll e = 0; e < 2; e++) {
        for (ll d = 0; d < 4; d++) {
            ll starti = distss[e].f + di[d];
            ll startj = distss[e].s + dj[d];
            if (starti >= 0 && starti <= 2 * H &&
                startj >= 0 && startj <= 2 * W &&
                maze[starti][startj] == ' ') {

                starts.push_back(starti);
                starts.push_back(startj);

                break;
            }
        }
    }

    bfs();

    ll ans = 0;

    for (ll i = 0; i <= 2 * H; i++) {
        for (ll j = 0; j <= 2 * W; j++) {
            ans = max(dists[i][j], ans);
        }
    }
	
    cout << ans << "\n";

	return 0;
}