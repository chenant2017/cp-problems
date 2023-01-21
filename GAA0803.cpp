#include <bits/stdc++.h>
#define x first
#define h second 
#define MAXN 100010
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N, D;
pll cows[MAXN];
auto ch = [](const ll& a, const ll& b) {
    return cows[a].h < cows[b].h || (cows[a].h == cows[b].h && cows[a].x < cows[b].x);
};
set<ll, decltype(ch)> lh (ch);
set<ll, decltype(ch)> rh (ch);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAA0803";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> D;

    for (ll i = 0; i < N; i++) {
        cin >> cows[i].x >> cows[i].h;
    }

    sort(cows, cows + N);

    ll rp = 0;
    ll lp = 0;
    ll ans = 0;

    lh.insert(0);

    for (ll i = 0; i < N; i++) {
        while (lp < N && cows[lp].x < cows[i].x - D) {
            lh.erase(lp);
            lp++;
        }

        while (rp < N && cows[rp].x <= cows[i].x + D) {
            rh.insert(rp);
            rp++;
        }

        if (cows[*rh.rbegin()].h >= 2 * cows[i].h &&
            cows[*lh.rbegin()].h >= 2 * cows[i].h) {
            ans++;
        }

        rh.erase(i);
        lh.insert(i);
    }

    cout << ans << "\n";
	
	return 0;
}