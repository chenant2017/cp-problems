#include <bits/stdc++.h>
#define MAX 1010

using namespace std;

typedef long long ll;

ll N, K;
ll barn[MAX][MAX] = {0};

void fill(ll x1, ll y1, ll x2, ll y2) {
    barn[x1][y1]++;
    barn[x2 + 1][y2 + 1]++;
    barn[x2 + 1][y1]--;
    barn[x1][y2 + 1]--;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "paintbarn";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> K;

    ll x1, y1, x2, y2;
    for (ll i = 0; i < N; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        fill(x1, y1, x2 - 1, y2 - 1);
    }

    for (ll i = 0; i < MAX; i++) {
        for (ll j = 1; j < MAX; j++) {
            barn[i][j] += barn[i][j - 1];
        }
    }

    for (ll j = 0; j < MAX; j++) {
        for (ll i = 1; i < MAX; i++) {
            barn[i][j] += barn[i - 1][j];
        }
    }

    ll ans = 0;

    for (ll i = 0; i < MAX; i++) {
        for (ll j = 0; j < MAX; j++) {
            if (barn[i][j] == K) {
                //cout << i << " " << j << "\n";                
                ans++;
            }
        }
    }

    cout << ans << "\n";
	
	return 0;
}