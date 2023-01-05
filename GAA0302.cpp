#include <bits/stdc++.h>
#define MAXN 1010
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N, M, K;
ll dest[MAXN][35];
pll adj[MAXN];
string dirs;

ll one_cycle(ll i) {
    for (auto c: dirs) {
        if (c == 'L') {
            i = adj[i].f;
        }
        else {
            i = adj[i].s;
        }
    }
    return i;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAA0302";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M >> K;

	for (ll i = 1; i <= N; i++) {
        cin >> adj[i].f >> adj[i].s;
	}

    for (ll i = 0; i < M; i++) {
        char c; cin >> c;
        dirs += c;
    }

    for (ll i = 1; i <= N; i++) {
        dest[i][0] = one_cycle(i);
        //cout << dest[i][0] << "\n";
    }

    for (ll i = 1; i <= log2(K); i++) {
        for (ll j = 1; j <= N; j++) {
            dest[j][i] = dest[dest[j][i - 1]][i - 1];
        }
    }

    ll k = 0;
    ll ans = 1;
    ll jump = pow(2, floor(log2(K)));

    while (jump > 0) {
        if (k + jump <= K) {
            ans = dest[ans][(ll) log2(jump)];
            k += jump;
        }
        else {
            jump /= 2;
        }
    }

    cout << ans << "\n";

	
	return 0;
}