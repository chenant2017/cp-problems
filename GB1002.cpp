#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll L, N, M;
vector<ll> rocks;

bool works(ll d) {
    ll skipped = 0;

    ll last = 0;
    for (ll i = 1; i < rocks.size(); i++) {
        if (rocks[i] - rocks[last] < d) {
            skipped++;
        }
        else {
            last = i;
        }
    }

    return skipped <= M;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GB1002";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> L >> N >> M;

    rocks.push_back(0);
    rocks.push_back(L);

    for (ll i = 0; i < N; i++) {
        ll a;
        cin >> a;
        rocks.push_back(a);
    }

    sort(rocks.begin(), rocks.end());

    ll d = 0;
    ll jump = L / 2;

    while (jump > 0) {
        if (works(d + jump)) {
            d += jump;
        }
        else {
            jump /= 2;
        }
    }

    cout << d << "\n";
	
	return 0;
}