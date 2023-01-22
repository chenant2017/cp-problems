#include <bits/stdc++.h>
#define MAXN 100010
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N, G, B, D;
pll stats[MAXN];
ll nexts[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAA0904";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> G >> B >> D;

    for (ll i = 0; i < N; i++) {
        cin >> stats[i].f >> stats[i].s;
    }

    stats[N] = {D, 0};

    sort(stats, stats + N + 1);

    stack<ll> ms;

    for (ll i = 0; i <= N; i++) {
        while (!ms.empty() && stats[ms.top()].s > stats[i].s) {
            nexts[ms.top()] = i;
            ms.pop();
        }
        ms.push(i);
    }

    ll ans = 0;
    ll fuel = B;
    ll pos = 0;
    ll st = 0;

    while (true) {
        ll dist = stats[st].f - pos;
        fuel -= dist;
        pos += dist;

        if (fuel < 0) {
            cout << "-1\n";
            return 0;
        }

        if (st == N) break;
        
        ll dist2 = stats[nexts[st]].f - pos;
        //cout << dist2 << " " << D << " dist2\n";
        if (dist2 <= G) {
            if (fuel < dist2) {
                ans += (dist2 - fuel) * stats[st].s;
                //cout << (dist2 - fuel) * stats[st].s << " added1\n";
                fuel = dist2;
            }
            st = nexts[st];
        }
        else {
            //cout << (G - fuel) * stats[st].s << " added2\n";
            ans += (G - fuel) * stats[st].s;
            fuel = G;
            st++;
        }
    }

    cout << ans << "\n";
	
	return 0;
}