#include <bits/stdc++.h>
#define f first 
#define s second
#define MAXN 110
#define MAXM 10010

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N, M;
ll a[MAXM];
ll shortest[MAXN][MAXN];

void fw() {
    for (ll k = 1; k <= N; k++) {
        for (ll i = 1; i <= N; i++) {
            for (ll j = 1; j <= N; j++) {
                shortest[i][j] = min(shortest[i][j], shortest[i][k] + shortest[k][j]);
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "video";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;

    for (ll i = 0; i < M; i++) {
        cin >> a[i];
    }

    for (ll i = 1; i <= N; i++) {
        for (ll j = 1; j <= N; j++) {
            cin >> shortest[i][j];
        }
    }

    fw();

    ll ans = 0;

    for (ll i = 1; i < M; i++) {
        ans += shortest[a[i - 1]][a[i]];
    }

    cout << ans << "\n";
	
	return 0;
}