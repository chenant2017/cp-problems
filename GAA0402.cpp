#include <bits/stdc++.h>
#define MAXN 75
using namespace std;

typedef long long ll;

ll N, A, B;
string farm[MAXN];
ll shortest[MAXN][MAXN];

ll dist(ll a1, ll b1, ll a2, ll b2) {
    if (farm[a1][b1] == farm[a2][b2]) {
        return A;
    }
    else {
        return B;
    }
}

ll test(ll a, ll b) {
    fill(shortest[0], shortest[0] + N * N, (ll)1e15);

    ll result = -1;

    for (ll i = a; i < N; i++) {
        for (ll j = b; j < N; j++) {
            if (i == a) {
                if (j == b) {
                    shortest[i][j] = 0;
                }
                else {
                    shortest[i][j] = shortest[i][j - 1] + dist(i, j - 1, i, j);
                }
            }
            else if (j == b) {
               shortest[i][j] = shortest[i - 1][j] + dist(i, j, i - 1, j);
            }
            else {
               shortest[i][j] = min(shortest[i][j - 1] + dist(i, j - 1, i, j), 
                                    shortest[i - 1][j] + dist(i, j, i - 1, j));
            }

            result = max(result, shortest[i][j]);
        }
    }

    return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAA0402";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> A >> B;

    for (ll i = 0; i < N; i++) {
        cin >> farm[i];
    }

    ll ans = -1;

    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            ans = max(ans, test(i, j));
        }
    }

    cout << ans << "\n";
	
	return 0;
}