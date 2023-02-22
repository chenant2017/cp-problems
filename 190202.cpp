#include <bits/stdc++.h>
#define MAX 1010
using namespace std;

typedef long long ll;

ll N, K;
ll wall[MAX][MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "paintbarn";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> K;

    for (ll i = 0; i < N; i++) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        x2--; y2--;

        wall[x1][y1]++;
        wall[x2 + 1][y2 + 1]++;
        wall[x1][y2 + 1]--;
        wall[x2 + 1][y1]--;
    }

    /*for (ll i = 0; i <= 10; i++) {
        for (ll j = 0; j <= 10; j++) {
            cout << wall[i][j] << " ";
        }
        cout << "\n";
    }*/

    for (ll i = 0; i <= 1000; i++) {
        for (ll j = 1; j <= 1000; j++) {
            wall[i][j] += wall[i][j - 1];
        }
    }

    ll ans = 0;

    for (ll i = 1; i <= 1000; i++) {
        for (ll j = 0; j <= 1000; j++) {
            wall[i][j] += wall[i - 1][j];
            if (wall[i][j] == K) {
                ans++;
            }
        }
    }

    cout << ans << "\n";

	return 0;
}