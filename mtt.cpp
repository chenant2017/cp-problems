#include <bits/stdc++.h>
#define MAXN 30
#define MAXB 20000
using namespace std;

typedef long long ll;

ll N;

bool visited[MAXB][MAXN][MAXN];
string maze[MAXN][MAXN];
set<ll> winning;
ll di[] = {0, 0, 1, -1};
ll dj[] = {1, -1, 0, 0};

bool good(ll a, ll b, ll c) {
    return (a == 1 && b == 2 && c == 2) ||
           (a == 2 && b == 2 && c == 1);
}

vector<ll> to_v(ll board) {
    vector<ll> v;
    
    for (ll i = 8; i >= 0; i--) {
        ll digit = board / ((ll) pow(3, i));
        cout << digit << endl;
        v.push_back(digit);
        board -= digit * pow(3, i);
    }
    assert(v.size()==9);
    reverse(v.begin(), v.end());

    return v;
}

bool wins(ll board) {
    vector<ll> v = to_v(board);

    bool result = false;
    for (ll i = 0; i < 3; i++) {
        result = result || good(v[i], v[i + 3], v[i + 6]); //columns
        result = result || good(v[3 * i], v[3 * i + 1], v[3 * i + 2]); //row;
    }

    result = result || good(v[0], v[4], v[8]) || good(v[2], v[4], v[6]);

    return result;   
}

ll move(ll board, string& s) {
    ll index = 3 * (s[1] - '1') + s[2] - '1';

    vector<ll> v = to_v(board);
    if (index <9 && v[index] != 0) return board;
    
    if (s[0] == 'M') {
        board += pow(3, index) * 1;
    }
    else {
        board += pow(3, index) * 2;
    }

    return board;
}

void dfs(ll board, ll i, ll j) {
    if (visited[board][i][j]) return;
    visited[board][i][j] = true;

    if (maze[i][j][0] == 'M' || maze[i][j][0] == 'O') {
        board = move(board, maze[i][j]);
    }

    if (wins(board)) {
        winning.insert(board);
        return;
    }

    for (ll d = 0; d < 4; d++) {
        ll ni = i + di[d];
        ll nj = j + dj[d];

        if (0 < ni && ni < N - 1 &&
            0 < nj && nj < N - 1 &&
            maze[ni][nj] != "###") {
            dfs(board, ni, nj);
        }
    }
}


int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	
	string fname = "mtt";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
    cin >> N;

    ll si, sj; // start;

    for (ll i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (ll j = 0; j < N; j++) {
            maze[i][j] = s.substr(3 * j, 3);
            if (maze[i][j] == "BBB") {
                si = i;
                sj = j;
            }
        }
    }

    dfs(0, si, sj);

    cout << winning.size() << "\n";

	return 0;
}