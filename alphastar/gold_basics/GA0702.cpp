#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;

typedef long long ll;

double adj[MAXN][MAXN];
double dists[MAXN];
bool visited[MAXN] = {false};
pair<ll, ll> points[MAXN];
ll N, M;

double prims() {
    double total = 0;

    for (ll i = 0; i < N; i++) {
        dists[i] = 2 * pow(10, 6);
    }
    dists[0] = 0;

    for (ll i = 0; i < N; i++) {
        ll curr = -1;
        for (ll j = 0; j < N; j++) {
            if (!visited[j] && (curr == -1 || dists[j] < dists[curr])) {
                curr = j;
            }
        }

        visited[curr] = true;
        total += dists[curr];
        //cout << dists[curr] << " hi\n";
        //cout << curr << "\n";
        dists[curr] = 0;

        for (ll j = 0; j < N; j++) {
            dists[j] = min(dists[j], dists[curr] + adj[curr][j]);
        }
    }

    return total;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GA0702";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;

    ll x, y;
    for (ll i = 0; i < N; i++) {
        cin >> x >> y;
        points[i].first = x;
        points[i].second = y;
    }

    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            adj[i][j] = sqrt(pow(points[i].first - points[j].first, 2) + 
                             pow(points[i].second - points[j].second, 2));
        }
    }

    ll a, b;
    for (ll i = 0; i < M; i++) {
        cin >> a >> b;
        adj[a - 1][b - 1] = 0;
        adj[b - 1][a - 1] = 0;
    }

    cout << fixed;
    cout << setprecision(2);
    cout << prims() << "\n";

	return 0;
}