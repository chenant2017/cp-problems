#include <bits/stdc++.h>
#define MAXN 160

using namespace std;

typedef long long ll;

struct Point {
    ll x, y;
};

ll N;
double shortest[MAXN][MAXN];
double longest[MAXN];
bool adj[MAXN][MAXN];
Point points[MAXN];
ll comps[MAXN] = {0};

double get_dist(ll a, ll b) {
    return sqrt(pow(points[a].x - points[b].x, 2) + pow(points[a].y - points[b].y, 2));
}

void dfs(ll start, ll comp) {
    if (comps[start] != 0) return;
    comps[start] = comp;
    for (ll i = 0; i < N; i++) {
        if (adj[start][i]) {
            cout << "asldfj " << comps[start] << "\n";
        }
        if (adj[start][i] && comps[start] == 0) {
            cout << "aasdf\n";
            dfs(i, comp);
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GA1101";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) {
        cin >> points[i].x >> points[i].y;
    }

    for (ll i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (ll j = 0; j < N; j++) {
            adj[i][j] = (s[j] == '1') ? true : false;
            shortest[i][j] = get_dist(i, j);
        }
    }

    ll comp = 0;
    for (ll i = 0; i < N; i++) {
        if (comps[i] == 0) {
            comp++;
            dfs(i, comp);
        }
    }

    for (ll i = 0; i < N; i++) {
        cout << comps[i] << " ";
    }
    cout << "\n";

    for (ll k = 0; k < N; k++) {
        for (ll i = 0; i < N; i++) {
            for (ll j = 0; j < N; j++) {
                shortest[i][j] = min(shortest[i][k] + shortest[k][j], shortest[i][j]);
            }
        }
    }

    for (ll i = 0; i < N; i++) {
        double longest2 = 0;
        for (ll j = 0; j < N; j++) {
            if (comps[i] == comps[j]) {
                longest2 = max(longest2, shortest[i][j]);
            } 
        }
        longest[i] = longest2;
    }

    double ans = -1;

    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            if (comps[i] != comps[j]) {
                double diameter = shortest[i][j] + longest[i] + longest[j];
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