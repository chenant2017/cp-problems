#include <bits/stdc++.h>
#define MAXN 50010
using namespace std;

typedef long long ll;

ll x[MAXN];
ll y[MAXN];
ll x2[MAXN];
ll y2[MAXN];
ll ind[MAXN];
ll nexts[MAXN]; //next cheaper
ll N, G, B, D;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "fuel";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
    cin >> N >> G >> B >> D;

    stack<ll> mono;

    for (ll i = 0; i < N; i++) {
        cin >> x2[i] >> y2[i];
        ind[i] = i;
    }
    ind[N] = N;
    x2[N] = D;
    y2[N] = 0;


    sort(ind, ind + N + 1, [](auto a, auto b) {
        return x2[a] < x2[b];
    });

    for (ll i = 0; i <= N; i++) {
        x[i] = x2[ind[i]];
        y[i] = y2[ind[i]];
    }

    for (ll i = 0; i < N; i++) {
        assert(x[i] <= x[i + 1]);
    }

    for (ll i = 0; i <= N; i++) {
        while (!mono.empty() && y[mono.top()] >= y[i]) {
            nexts[mono.top()] = i;
            mono.pop();
        }
        mono.push(i);
    }

    ll fuel = B - x[0];
    ll ans = 0;
    ll ptr = 0;

    while(ptr < N) {
        if (fuel < 0) {
            cout << "-1\n";
            return 0;
        }

        //cout << ptr << " " << fuel << "\n";

        ll need = x[nexts[ptr]] - x[ptr];
        if (need > G) {  // fill up at current ??
            ans += (G - fuel) * y[ptr];
            fuel = G - (x[ptr + 1] - x[ptr]);
            ptr++;
        }
        else {
            if (fuel < need) {
                ans += (need - fuel) * y[ptr];
                fuel = 0;
            }
            else {
                fuel -= need;
            }
            ptr = nexts[ptr];
        }
    }

    if (fuel < 0) {
        cout << "-1\n";
        return 0;
    }

    cout << ans << "\n";
	
	return 0;
}