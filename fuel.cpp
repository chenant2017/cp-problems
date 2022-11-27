#include <bits/stdc++.h>
#define MAXN 50010
using namespace std;

typedef long long ll;

struct Station {
    ll x, y;
};

ll N, G, B, D;
Station stations[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "fuel";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> G >> B >> D;

    for (ll i = 0; i < N; i++) {
        Station s;
        cin >> s.x >> s.y;
        stations[i] = s;
    }

    sort(stations, stations + N, [](auto& a, auto& b) {
        return a.x < b.x;
    });

    stack<ll> mono;
    ll ans = 0;
    ll gas = B;

    for (ll i = 0; i < N; i++) {
        while (!mono.empty()) {
            if (stations[mono.top()].y > stations[i].y) {
                ll dist = stations[i].x - stations[mono.top()].x;
                if (dist > G) {
                    ans += (G - gas) * stations[mono.top()].y;
                    gas = G;
                }
                else {
                    ans += max(0ll, dist - gas) * stations[mono.top()].y;
                }
                mono.pop();
            }
        }
        mono.push(i);
    }

    cout << ans << "\n";
	
	return 0;
}