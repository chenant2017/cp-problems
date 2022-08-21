#include <bits/stdc++.h>
#define MAXM 10010
using namespace std;

typedef long long ll;

ll N, M;
vector<int> acounts (MAXM, 0);
vector<int> bcounts (MAXM, 0);
vector<ll> prefix (MAXM, 0);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "convoluted";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;

    for (ll i = 0; i < N; i++) {
        ll a, b;
        cin >> a >> b;
        acounts[a]++;
        bcounts[b]++;
    }

    for (ll i = 0; i <= M; i++) {
        for (ll j = 0; j <= M; j++) {
            prefix[i + j] += acounts[i] * acounts[j];
        }
    }

    for (ll i = 0; i <= M; i++) {
        for (ll j = 0; j <= M; j++) {
            prefix[i + j + 1] -= bcounts[i] * bcounts[j];
        }
    }

    cout << prefix[0] << "\n";
    for (ll i = 1; i <= 2 * M; i++) {
        prefix[i] += prefix[i - 1];
        cout << prefix[i] << "\n";
    }
	
	return 0;
}