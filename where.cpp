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
bool tested[MAXN][MAXN][MAXN][MAXN] = {false};

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

void get_pcls(ll mini, ll maxi, ll minj, ll maxj, set<tll>& pcls) {
    if (tested[mini][maxi][minj][maxj]) return;
    tested[mini][maxi][minj][maxj] = true;
    if (is_pcl(mini, maxi, minj, maxj)) {
        pcls.insert(tll({mini, maxi, minj, maxj}));
        return;
    }

    for (ll d = 0; d < 4; d++) {
        ll nextmini = mini + dmini[d];
        ll nextmaxi = maxi + dmaxi[d];
        ll nextminj = minj + dminj[d];
        ll nextmaxj = maxj + dmaxj[d];

        if (nextmini <= nextmaxi &&
            nextminj <= nextmaxj) {
            get_pcls(nextmini, nextmaxi, nextminj, nextmaxj, pcls);
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

    set<tll> pcls;

    get_pcls(0, N - 1, 0, N - 1, pcls);

    set<tll> new_pcls;

    for (auto i: pcls) {
        ll a, b, c, d;
        tie(a, b, c, d) = i;

        bool valid = true;
        for (auto j: pcls) {
            if (i == j) continue;
            ll e, f, g, h;
            tie(e, f, g, h) = j;

            if (e <= a && b <= f &&
                g <= c && d <= h) {
                valid = false;
                break;
            }
        }

        if (valid) {
            new_pcls.insert(i);
        }
    }

    cout << new_pcls.size() << "\n";
	
	return 0;
}