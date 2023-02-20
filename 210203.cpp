#include <bits/stdc++.h>
#define MAXN 510
using namespace std;

typedef long long ll;

ll N;
ll past[MAXN][MAXN];
bool space[MAXN][MAXN];
ll prefix[MAXN][MAXN];

void get_prefix() {
    for (ll i = 1; i <= N; i++) {
        for (ll j = 1; j <= N; j++) {
            prefix[i][j] = space[i][j] + prefix[i - 1][j];
        }
    }
}

ll get_subs() {
    ll result = 0;

    for (ll i1 = 1; i1 <= N; i1++) {
        for (ll i2 = i1; i2 <= N; i2++) {

            ll streak = 0;
            for (ll j = 1; j <= N; j++) {
                if (prefix[i2][j] - prefix[i1 - 1][j] == 0) {
                    streak++;
                }
                else {
                    result += ((streak) * (streak + 1)) / 2;
                    streak = 0;
                }
            }
            result += ((streak) * (streak + 1)) / 2;
        }
    }

    return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "210203";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 1; i <= N; i++) {
        for (ll j = 1; j <= N; j++) {
            cin >> past[i][j];
            if (past[i][j] < 100)  {
                space[i][j] = true;
            }
        }
    }

    get_prefix();
    ll ans = get_subs();
    
    for (ll i = 1; i <= N; i++) {
        for (ll j = 1; j <= N; j++) {
            if (past[i][j] == 100) {
                space[i][j] = true;
            }
        }
    }

    get_prefix();
    ans -= get_subs();

    cout << ans << "\n";
	
	return 0;
}