#include <bits/stdc++.h>
#define MAXN 160
using namespace std;

typedef long long ll;

struct Point {
    ll x, y;
};

Point points[MAXN];
double shortest[MAXN][MAXN];
double farthest[MAXN];
ll N;

double get_dist(ll i, ll j) {
    return sqrt(pow(points[i].x - points[j].x, 2) + 
                pow(points[i].y - points[j].y, 2));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GA1101";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) {
        Point p;
        cin >> p.x >> p.y;

        points[i] = p;
    }

    for (ll i = 0; i < N; i++) {
        string a;
        cin >> a;
        for (ll j = 0; j < N; j++) {
            shortest[i][j] = -1;
            if (a[j] == '1') {
                shortest[i][j] = get_dist(i, j);
            }
            if (i == j) shortest[i][j] = 0;
        }
    }

    for (ll k = 0; k < N; k++) {
        for (ll i = 0; i < N; i++) {
            for (ll j = 0; j < N; j++) {
                double newdist = shortest[i][k] + shortest[k][j];
                if (shortest[i][k] != -1 && shortest[k][j] != -1) {
                    if (shortest[i][j] == -1 || newdist < shortest[i][j]) {
                        shortest[i][j] = newdist;
                    }
                }
            }
        }
    }

    for (ll i = 0; i < N; i++) {
        double max_dist = -1;
        for (ll j = 0; j < N; j++) {
            max_dist = max(max_dist, shortest[i][j]);
        }
        farthest[i] = max_dist;
    }

    double ans = -1;

    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            if (shortest[i][j] == - 1) {
                double dist = get_dist(i, j) + farthest[i] + farthest[j];
                if (ans == -1 || dist < ans) {
                    ans = dist;
                }
            }
        }
    }
	
    cout << fixed;
    cout << setprecision(6);
    cout << ans << "\n";

	return 0;
}