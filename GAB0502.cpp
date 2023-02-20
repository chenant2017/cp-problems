#include <bits/stdc++.h>
#define MAX 210
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N, M;
string land[MAX];
ll prefix[MAX][MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAB0502";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;

    for (ll i = 1; i <= N; i++) {
        cin >> land[i];
        land[i] = ' ' + land[i];
    }
	
    for (ll i = 1; i <= N; i++) {
        for (ll j = 1; j <= M; j++) {
            prefix[i][j] = (land[i][j] == 'X') + prefix[i - 1][j];
        }
    }

    ll ans = 0;

    for (ll i1 = 1; i1 <= N; i1++) {
        for (ll i2 = i1; i2 <= N; i2++) {
            
            vector<ll> cols = {0};
            for (ll j = 1; j <= N; j++) {
                if (land[i1][j] == 'X' || land[i2][j] == 'X') {
                    cols.push_back(j);
                }
            }
            cols.push_back(M + 1);

            for (ll j = 0; j < cols.size() - 1; j++) {
                ll first = -1, last = -1;

                for (ll k = cols[j] + 1; k < cols[j + 1]; k++) {
                    if (prefix[i2][k] - prefix[i1 - 1][k] == 0) {
                        first = k;
                        break;
                    }
                }

                for (ll k = cols[j + 1] - 1; k > cols[j]; k--) {
                    if (prefix[i2][k] - prefix[i1 - 1][k] == 0) {
                        last = k;
                        break;
                    }
                }

                if (first != -1) {
                    ans = max(ans, (last - first + 1) * (i2 - i1 + 1));
                }
            }
        }
    }

    cout << ans << "\n";

	return 0;
}