#include <bits/stdc++.h>
#define MAXN 50010
using namespace std;

typedef long long ll;
struct Station {
    ll loc, cost;
};

ll N, G, B, D;
Station stations[MAXN];
ll next_cheaper[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "fuel";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
    cin >> N >> G >> B >> D;

    for (ll i = 0; i < N; i++) {
        cin >> stations[i].loc >> stations[i].cost;
    }

    sort(stations, stations + N, [](auto& a, auto& b) {
        return a.loc < b.loc;
    });

    stations[N].cost = 0;
    stations[N].loc = D;

    stack<ll> mono;

    for (ll i = 0; i <= N; i++) {
        while (!mono.empty() && stations[mono.top()].cost > stations[i].cost) {
            next_cheaper[mono.top()] = i;
            mono.pop();
        }
        mono.push(i);
    }

    /*for (ll i = 0; i < N; i++) {
        cout << next_cheaper[i] << "\n";
    }*/

    ll gas = B;
    ll ans = 0;
    ll curr_loc = 0;
    for (ll i = 0; i < N; i++) {
        ll dist = stations[i].loc - curr_loc;
        gas -= dist;
        if (gas < 0) {
            cout << "-1\n";
            return 0;
        }

        curr_loc = stations[i].loc;
        ll to_next = stations[next_cheaper[i]].loc - curr_loc;

        if (to_next > G) {
            ans += (G - gas) * stations[i].cost;
            gas = G;
        }
        else {
            ans += max(0ll, to_next - gas) * stations[i].cost;
            if (gas < to_next) gas = to_next;
        }
    }

    if (gas >= D - curr_loc)  {
        cout << ans << "\n";
    }
    else {
        cout << "-1\n";
    }
    
	return 0;
}