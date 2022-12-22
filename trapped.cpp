#include <bits/stdc++.h>
#define f first 
#define s second
#define MAXN 100010
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N, B;
pll bales[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "trapped";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> B;

    for (ll i = 0; i < N; i++) {
        cin >> bales[i].f >> bales[i].s; //size, position
    }

    sort(bales, bales + N, [](auto& a, auto& b) {
        return a.s < b.s;
    });

    if (B < bales[0].s || B > bales[N - 1].s) {
        cout << "-1\n";
        return 0;
    }

    ll b2 = 1;
    for (; b2 < N; b2++) {
        //cout << "b1 " << b1 << "\n";
        if (B < bales[b2].s) {
            //cout << "first b2 is " << b2 << "\n";
            break;
        }
    }

    ll ans = -1;

    ll b1 = b2 - 1;

    ll p1 = b1, p2 = b2;
    while (p1 >= 0) {
        while (p2 < N && bales[p2].s - bales[p1].s > bales[p2].f) {
            p2++;
        }
        if (p2 == N) break;
        ll needed = max(0ll, bales[p2].s - bales[p1].s - bales[p1].f);
        if (ans == -1 || needed < ans) ans = needed;
        p1--;
    }

    p1 = b1, p2 = b2;
    while (p2 < N) {
        while (p1 >= 0 && bales[p2].s - bales[p1].s > bales[p1].f) {
            p1--;
        }
        if (p1 == -1) break;
        ll needed = max(0ll, bales[p2].s - bales[p1].s - bales[p2].f);
        if (ans == -1 || needed < ans) ans = needed;
        p2++;
    }


    cout << ans << "\n";
	
	return 0;
}