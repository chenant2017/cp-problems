#include <bits/stdc++.h>
#define MAXN 100010
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll L, N;
pll turns[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAA0801";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> L >> N;

    for (ll i = 0; i < N; i++) {
        ll t, s;
        cin >> t >> s;
        turns[i] = {t, s};
    }

    sort(turns, turns + N);

    ll ans = 1;
    ll speed = 1;
    ll pos = 0;

    for (ll i = 0; i < N; i++) {
        ll speed2 = speed + (turns[i].f - pos);
        if (speed2 <= turns[i].s) {
            ans = max(ans, speed2);
        } 
        else {
            speed2 = turns[i].s;
            ans = max(ans, 
                      (turns[i].s + speed + turns[i].f - pos) / 2);
        } 
        speed = speed2;
        pos = turns[i].f;
    }

    ans = max(ans, speed + L - pos);

    cout << ans << "\n";
	
	return 0;
}