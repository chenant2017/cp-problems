#include <bits/stdc++.h>
#define MAX 1010
#define f first  
#define s second  

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N;
string cows[MAX];

bool unsolvable(ll i, ll j) {
    ll rcount = 0;
    ll lcount = 0;

    for (ll di = 0; di < 2; di++) {
        for (ll dj = 0; dj < 2; dj++) {
            ll curri = i + di;
            ll currj = j + dj;

            if (cows[curri][currj] == 'R') {
                rcount++;
            }
            else {
                lcount++;
            }
        }
    }
    return rcount == 1 || lcount == 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "leftout";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) {
        cin >> cows[i];
    }

    pll ans = pll({-1, -1});
    ll unsolvables = 0;

    for (ll i = 0; i < N - 1; i++) {
        for (ll j = 0; j < N - 1; j++) {
            if (unsolvable(i, j)) {
                if (ans == pll({-1, -1})) {
                    ans = pll({i, j});
                }
                unsolvables++;
            }
        }
    }

    if (unsolvables == 1) {
        cout << ans.f + 1 << " " << ans.s + 1 << "\n";
    }
    else  {
        cout << "-1\n";
    }
	
	return 0;
}