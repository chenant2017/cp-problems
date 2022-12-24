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

ll dmini[] = {-1, 0, 0, 0};
ll dmaxi[] = {0, 1, 0, 0};
ll dminj[] = {0, 0, -1, 0};
ll dmaxj[] = {0, 0, 0, 1};

vector<tll> pcls;

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

    for (ll mini = 0; mini < N; mini++) {
        for (ll minj = 0; minj < N; minj++) {
            for (ll maxi = N - 1; maxi >= mini; maxi--) {
                for (ll maxj = N - 1; maxj >= minj; maxj--) {

                    if (is_pcl(mini, maxi, minj, maxj)) {   
                        pcls.push_back(tll{mini, maxi, minj, maxj});
                    }
                }
            }
        }
    }

    ll ans = 0;

    for (auto p: pcls) {
        ll a, b, c, d;
        tie(a, b, c, d) = p;

        bool valid = true;
        for (auto q: pcls) {
            if (p == q) continue;
            ll r, s, t, u;
            tie(r, s, t, u) = q;

            if (r <= a && b <= s &&
                t <= c && d <= u) {
                valid = false;
                break;
            }
        }

        if (valid) ans++;
    }

    cout << ans << "\n";
	
	return 0;
}