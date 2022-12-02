#include <bits/stdc++.h>
#define MAX 510
using namespace std;

typedef long long ll;
typedef tuple<ll, ll, ll> tll;

ll N, M;
string space[MAX];
bool visited_pos[MAX][MAX] = {false};
bool visited_neg[MAX][MAX] = {false};

bool visited(ll i, ll j, ll g) {
    if (g > 0) return visited_pos[i][j];
    else return visited_neg[i][j];
}

ll bfs(ll starti, ll startj, ll endi, ll endj) {
    deque<tll> q;
    q.push_back(tll({starti, startj, 0}));

    while (!q.empty()) {
        auto curr = q.front();
        q.pop_front();

        ll i, j, t;
        tie(i, j, t) = curr;
        ll g = pow(-1, t);

        if (g > 0) {
            if (visited_pos[i][j]) continue;
            visited_pos[i][j] = true;
        } 
        else {
            if (visited_neg[i][j]) continue;
            visited_neg[i][j] = true;
        }

        if (i == endi && j == endj) return t;
        
        bool in_range = i + g >= 0 && i + g < N;
        if (in_range) {
            cout << "b\n";
            if (space[i + g][j] == '#') {
                for (ll dj = -1; dj <= 1; dj += 2) {
                    bool v = visited(i, j, g);

                    if (0 <= j + dj && j + dj < M &&
                        space[i][j + dj] != '#' &&
                        !v) {
                        q.push_front(tll({i, j + dj, t}));
                    }
                }
                if (!visited(i, j, t + 1)) q.push_back(tll({i, j, t + 1}));
            }
            else {
                q.push_front(tll({i + g, j, t}));
            }   
        }
    }
    return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "toggle";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;

    ll starti, startj;
    ll endi, endj;

    for (ll i = 0; i < N; i++) {
        cin >> space[i];
        for (ll j = 0; j < M; j++) {
            if (space[i][j] == 'C') {
                starti = i;
                startj = j;
            }
            if (space[i][j] == 'D') {
                endi = i;
                endj = j;
            }
        }
    }

    ll ans = bfs(starti, startj, endi, endj);

    cout << ans << "\n";
	
	return 0;
}