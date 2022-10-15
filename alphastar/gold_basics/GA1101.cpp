#include <bits/stdc++.h>
#define f first 
#define s second
#define MAXN 160
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

pll points[MAXN];
ll comps[MAXN] = {0};
bool adj[MAXN][MAXN];
ll N;
double shortest[MAXN][MAXN];
double max_shortest[MAXN] = {0};

void dfs(ll p, ll comp) {
    if (comps[p] != 0) return;
    comps[p] = comp;

    for (ll i = 0; i < N; i++) {
        if (adj[p][i] && comps[i] == 0) {
            dfs(i, comp);
        }
    } 
}

double get_dist(ll p1, ll p2) {
    return sqrt(pow(points[p1].f - points[p2].f, 2) + pow(points[p1].s - points[p2].s, 2));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "town";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) {
        cin >> points[i].f >> points[i].s;
    }

    for (ll i = 0; i < N; i++) {
        string adjs;
        cin >> adjs;
        for (ll j = 0; j < N; j++) {
            if (adjs[j] == '1') {
                adj[i][j] = true;
            }
            else {
                adj[i][j] = false;
            }
        }
    }

    ll comp = 1;
    for (ll i = 0; i < N; i++) {
        if (comps[i] == 0) {
            dfs(i, comp);
            comp++;
        }
    }


    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            if (i == j) shortest[i][j] = 0;
            else if (adj[i][j]) shortest[i][j] = get_dist(i, j);
            else shortest[i][j] = -1;
        }
    }
	
    for (ll k = 0; k < N; k++) {
        for (ll i = 0; i < N; i++) {
            for (ll j = 0; j < N; j++) {
                if (shortest[i][k] >= 0 && shortest[k][j] >= 0) {
                    double dist = shortest[i][k] + shortest[k][j];
                    if (shortest[i][j] == -1 || dist < shortest[i][j]) {
                        shortest[i][j] = dist;
                    }
                }   
            }
        }
    }

    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            if (comps[i] == comps[j]) {
                max_shortest[i] = max(max_shortest[i], shortest[i][j]);
            }
        }
    }

    double ans = -1;

    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            if (comps[i] != comps[j]) {
                double diameter = get_dist(i, j) + max_shortest[i] + max_shortest[j];
                if (ans == -1 || diameter < ans) {
                    ans = diameter;
                }
            }
        }
    }

    cout << fixed;
    cout << setprecision(6);
    cout << ans << "\n";


	return 0;
}