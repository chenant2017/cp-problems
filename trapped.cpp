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
	//freopen((fname + ".out").c_str(), "w", stdout);
	
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

    for (ll i = 0; i < N; i++) {
        cout << bales[i].f << " " << bales[i].s << "\n";
    }

    ll b2 = 1;
    for (; b2 < N; b2++) {
        //cout << "b1 " << b1 << "\n";
        if (B < bales[b2].s) {
            cout << "first b2 is " << b2 << "\n";
            break;
        }
    }

    ll b1 = b2 - 1;

    cout << b1 << " " << b2 << "\n";

    ll ans = -1;

    while (b1 >= 0 && b2 < N) {
        cout << b1 << " " << b2 << "\n";
        ll d = bales[b2].s - bales[b1].s;
        if (d > bales[b1].f) {
            if (d > bales[b2].f) {
                b1--;
                b2++;
            }
            else {
                ll needed = d - bales[b1].f;
                if (ans == -1 || needed < ans) {
                    ans = needed;
                }
                b1--;
            }
        }
        else {
            if (d > bales[b2].f) {
                ll needed = d - bales[b2].f;
                if (ans == -1 || needed < ans) {
                    ans = needed;
                }
                b2++;
            }
            else {
                cout << "0\n";
                return 0;
            }
        }
    }

    cout << ans << "\n";
	
	return 0;
}