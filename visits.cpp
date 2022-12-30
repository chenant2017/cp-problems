#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

typedef long long ll;

ll a[MAXN];
ll v[MAXN];
ll visited[MAXN] = {0};
bool taken[MAXN] = {false};
ll N;

bool floodfill(ll i, ll comp) {
    visited[i] = comp;
    while (visited[a[i]] == 0) {
        i = a[i];
        visited[i] = comp;
    }   
    if (visited[a[i]] != comp) return false;
    return true;
}

ll get_shortest(ll i) {
    ll result;

    ll p1 = i;
    ll p2 = a[i];

    while (p1 != p2) {
        p1 = a[p1];
        p2 = a[a[p2]];
    }

    ll shortest = v[p1];
    result = p1;
    p2 = a[p1];
    //cout << p2 << " p2\n";
    while (p1 != p2) {
        if (v[p2] < shortest) {
            shortest = v[p2];
            result = p2;
        }
        p2 = a[p2];
        //cout << p2 << " p2\n";
    }

    return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "visits";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    ll total = 0;

    for (ll i = 1; i <= N; i++) {
        cin >> a[i] >> v[i];
        total += v[i];
    }

    ll comp = 0;

    for (ll i = 1; i <= N; i++) {
        if (!visited[i]) {
            comp++;
            bool ff = floodfill(i, comp);
            if (ff) {
                total -= v[get_shortest(i)];
            }
            //ll take = get_shortest(i);
            //taken[take] = true;
        }
    }

    /*for (ll i = 1; i <= N; i++) {
        if (taken[i]) total -= v[i];
    }*/

    cout << total << "\n";

	return 0;
}