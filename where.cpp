#include <bits/stdc++.h>
#define MAXN 25
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef tuple<ll, ll, ll, ll> tll;

ll N;
ll di[] = {0, 0, 1, -1};
ll dj[] = {1, -1, 0, 0};
string image[MAXN];
bool visited[MAXN][MAXN];
map<char, ll> regions;
set<tll> pcls;

ll dmini[] = {1, 0, 0, 0};
ll dmaxi[] = {0, -1, 0, 0};
ll dminj[] = {0, 0, 1, 0};
ll dmaxj[] = {0, 0, 0, -1};

void floodfill(ll i, ll j, ll mini, ll maxi, ll minj, ll maxj) {
    if (visited[i][j]) return;
    visited[i][j] = true;

    for (ll d = 0; d < 4; d++) {
        ll nexti = i + di[d];
        ll nextj = j + dj[d];

        if (mini <= nexti && nexti <= maxi &&
            minj <= nextj && nextj <= maxj &&
            image[nexti][nextj] == image[i][j] &&
            !visited[nexti][nextj]) {
            
            floodfill(nexti, nextj, mini, maxi, minj, maxj);
        } 
    }
}

bool is_pcl(ll mini, ll maxi, ll minj, ll maxj) {
    regions.clear();
    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            visited[i][j] = false;
        }
    }

    for (ll i = mini; i <= maxi; i++) {
        for (ll j = minj; j <= maxj; j++) {
            if (!visited[i][j]) {
                floodfill(i, j, mini, maxi, minj, maxj);
                regions[image[i][j]]++;
            }
        }
    }

    if (regions.size() > 2) return false;

    bool one = false;
    bool multiple = false;

    for (auto r: regions) {
        if (r.s == 1) {
            one = true;
        }
        else {
            multiple = true;
        }
    }
    return one && multiple;
}

void get_pcls(ll mini, ll maxi, ll minj, ll maxj) {
    queue<tll> q;
    q.push(tll({mini, maxi, minj, maxj}));

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        ll w, x, y, z;
        tie(w, x, y, z) = curr;

        bool necessary = true;

        for (auto p: pcls) {
            ll r, s, t, u;
            tie(r, s, t, u) = p;

            if (r <= w && x <= s &&
                t <= y && z <= u) {
                necessary = false;
                break;
            }
        }

        if (!necessary) continue;
        
        if (is_pcl(w, x, y, z)) {
            pcls.insert(tll({w, x, y, z}));
            continue;
        }

        for (ll d = 0; d < 4; d++) {
            ll nextmini = w + dmini[d];
            ll nextmaxi = x + dmaxi[d];
            ll nextminj = y + dminj[d];
            ll nextmaxj = z + dmaxj[d];

            if (nextmini <= nextmaxi &&
                nextminj <= nextmaxj) {
                q.push(tll({nextmini, nextmaxi, nextminj, nextmaxj}));
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "where";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) {
        cin >> image[i];
    }

    get_pcls(0, N - 1, 0, N - 1);

    cout << pcls.size() << "\n";
	
	return 0;
}