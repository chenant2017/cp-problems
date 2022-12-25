#include <bits/stdc++.h>
#define MAXN 260
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N;
ll grid[MAXN][MAXN];
map<ll, ll> team_counts;
map<pll, ll> one_sizes;
map<pll, set<pll>> comp_adj;
pll comps[MAXN][MAXN];
ll di[] = {0, 0, 1, -1};
ll dj[] = {1, -1, 0, 0};

void floodfill(ll i, ll j, pll comp, ll& size) {
    if (comps[i][j] != pll({-1, -1})) return;
    comps[i][j] = comp;
    size++;

    for (ll d = 0; d < 4; d++) {
        ll nexti = i + di[d];
        ll nextj = j + dj[d];

        if (0 <= nexti && nexti < N &&
            0 <= nextj && nextj < N) {
            if (grid[nexti][nextj] == grid[i][j]) {
                floodfill(nexti, nextj, comp, size);
            }
            else {
                if (comps[nexti][nextj] != pll({-1, -1})) {
                    comp_adj[comps[nexti][nextj]].insert(comp);
                    comp_adj[comp].insert(comps[nexti][nextj]);
                }
            }
        }
    }
}

ll get_two_size(pll comp, ll team1, ll team2) {
    ll result = 0;
    set<pll> visited;
    queue<pll> q;
    q.push(comp);

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        if (visited.find(curr) != visited.end()) continue;
        visited.insert(curr);

        result += one_sizes[curr];

        for (auto i: comp_adj[curr]) {
            if (visited.find(i) == visited.end() && (i.first == team1 || i.first == team2)) {
                q.push(i);
            }
        }
    }

    return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "multimoo";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            comps[i][j] = pll({-1, -1});
        }
    }

    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }
    
    ll one_ans = 0;

    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {

            if (comps[i][j] == pll({-1, -1})) {
                ll team = grid[i][j];
                team_counts[team]++;
                ll size = 0;
                pll comp = pll({team, team_counts[team]});
                floodfill(i, j, comp, size);
                one_sizes[comp] = size;
                one_ans = max(one_ans, size);
            }
        }
    }

    ll two_ans = 0;

    for (auto i: comp_adj) {
        for (auto j: i.second) {
            ll two_size = get_two_size(i.first, i.first.first, j.first);
            two_ans = max(two_ans, two_size);
        }
    }

    cout << one_ans << "\n";
    cout << two_ans << "\n";


	return 0;
}