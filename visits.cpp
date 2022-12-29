#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

typedef long long ll;

ll a[MAXN];
ll v[MAXN];
bool visited[MAXN] = {false};
ll N;

void floodfill(ll i) {
    visited[i] = true;
    while (!visited[a[i]]) {
        i = a[i];
        visited[i] = true;
    }   
}

ll get_shortest(ll i) {
    ll p1 = i;
    ll p2 = a[i];

    while (p1 != p2) {
        p1 = a[p1];
        p2 = a[a[p2]];
    }

    ll shortest = v[p1];
    p2 = a[p1];
    //cout << p2 << " p2\n";
    while (p1 != p2) {
        shortest = min(shortest, v[p2]);
        p2 = a[p2];
        //cout << p2 << " p2\n";
    }

    return shortest;
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

    for (ll i = 1; i <= N; i++) {
        if (!visited[i]) {
            floodfill(i);
            total -= get_shortest(i);
        }
    }

    cout << total << "\n";

	return 0;
}