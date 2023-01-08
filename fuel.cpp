#include <bits/stdc++.h>
#define MAXN 50010
using namespace std;

typedef long long ll;

ll x[MAXN];
ll y[MAXN];
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
        cin >> x[i] >> y[i];
        ind[i] = i;
    }
    ind[N] = N;
    x[N] = D;
    y[N] = 0;


    sort(ind, ind + N + 1, [](auto a, auto b) {
        return x[a] < x[b];
    });

    for (ll i = 0; i <= N; i++) {
        if (ind[i] < i) {
            swap(x[i], x[ind[i]]);
            swap(y[i], y[ind[i]]);
        }
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
        if (need > G) {
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