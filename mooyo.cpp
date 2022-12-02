//2018 December Silver #3

#include <bits/stdc++.h>
#define MAXN 110
#define M 10
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N, K;
ll board[M][MAXN];
ll di[] = {-1, 1, 0, 0};
ll dj[] = {0, 0, -1, 1};

set<pll> floodfill(ll starti, ll startj) { //what if board[starti][startj] = -0
    set<pll> visited;
    ll size = 0;
    queue<pll> q;
    q.push(pll({starti, startj}));
    
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        if (visited.find(curr) != visited.end()) continue;
        size++;
        visited.insert(curr);

        for (ll d = 0; d < 4; d++) {
            pll next = pll({curr.f + di[d], curr.s + dj[d]});

            if (next.f >= 0 && next.f < M &&
                next.s >= 0 && next.s < N &&
                board[next.f][next.s] == board[starti][startj] &&
                visited.find(next) == visited.end()) {
                q.push(next);
            }
        }
    }

    if (size < K) {
        visited.clear();
    }
    return visited;
}

void gravity() {
    for (ll i = 0; i < M; i++) {

        for (ll ptr1 = 0; ptr1 < N; ptr1++) {
            if (board[i][ptr1] == 0) {
                for (ll ptr2 = ptr1; ptr2 < N; ptr2++) {
                    if (board[i][ptr2] != 0) {
                        swap(board[i][ptr1], board[i][ptr2]);
                        break;
                    }
                }
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "mooyomooyo";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> K;
	
    for (ll j = N - 1; j >= 0; j--) {
        string s;
        cin >> s;
        for (ll i = 0; i < M; i++) {
            board[i][j] = s[i] - '0';
        }
    }

    /*for (ll i = 0; i < M; i++) {
        for (ll j = 0; j < N; j++) {
            cout << board[i][j];
        }
        cout << "\n";
    }
    cout << "\n";*/

    bool done = false;
    while (!done) {
        ll comps = 0;
        for (ll i = 0; i < M; i++) {
            for (ll j = 0; j < N; j++) {
                if (board[i][j] != 0) {
                    set<pll> to_remove = floodfill(i, j);
                    for (auto tr: to_remove) {
                        board[tr.f][tr.s] = 0;
                    }
                    //cout << i << " " << j << " " << to_remove.size() << "\n";
                    if (to_remove.size() > 0) comps++;
                }
            }
        }
        gravity();
        if (comps == 0) done = true;
    }

    for (ll j = N - 1; j >= 0; j--) {
        for (ll i = 0; i < M; i++) {
            cout << board[i][j];
        }
        cout << "\n";
    }

	return 0;
}