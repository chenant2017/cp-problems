#include <bits/stdc++.h>
#define MAX 1010
#define f first  
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N;
ll cows[MAX][MAX];

void rflip(ll r) {
    for (ll i = 0; i < N; i++) {
        cows[r][i] = 1 - cows[r][i];
    }
}

void cflip(ll c) {
    for (ll i = 0; i < N; i++) {
        cows[i][c] = 1 - cows[i][c];
    }
}

ll rsum(ll r) {
    ll result = 0;
    for (ll i = 0; i < N; i++) {
        result += cows[r][i];
    }
    return result;
}

ll csum(ll c) {
    ll result = 0;
    for (ll i = 0; i < N; i++) {
        result += cows[i][c];
    }
    return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "leftout";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (ll j = 0; j < N; j++) {
            cows[i][j] = s[j] == 'R';
        }
    }

    for (ll i = 1; i < N; i++) {
        if (cows[i][0] != cows[0][0]) {
            rflip(i);
        }
        if (cows[0][i] != cows[0][0]) {
            cflip(i);
        }
    }

    if (cows[0][0] == 1) {
        for (ll i = 0; i < N; i++) {
            rflip(i);
        }
    }

    ll total = 0;
    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            total += cows[i][j];
        }
    }
    if (total == pow(N - 1, 2)) {
        cout << "1 1" << "\n";
        return 0;
    }

    pll ans = pll({-1, -1});
    
    for (ll i = 1; i < N; i++) {
        if (rsum(i) == N - 1) {
            if (ans == pll({-1, -1})) {
                ans = pll({i, 0});
            }
            else {
                cout << "-1\n";
                return 0;
            }
        }
        if (csum(i) == N - 1) {
            if (ans == pll({-1, -1})) {
                ans = pll({0, i});
            }
            else {
                cout << "-1\n";
                return 0;
            }
        }
    }

    if (ans != pll({-1, -1})) {
        cout << ans.f + 1 << " " << ans.s + 1 << "\n";
        return 0;
    }

    for (ll i = 1; i < N; i++) {
        for (ll j = 1; j < N; j++) {
            if (cows[i][j] == 1) {
                if (ans == pll({-1, -1})) {
                    ans = pll(i, j);
                }
                else {
                    cout << "-1\n";
                    return 0;
                }
            }
        }
    }

    if (ans == pll({-1, -1})) {
        cout << "-1\n";
    }
    else {
        cout << ans.f + 1 << " " << ans.s + 1 << "\n";
    }
	
	return 0;
}