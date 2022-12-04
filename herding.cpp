//Silver 2019 Feb #1

#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

typedef long long ll;

ll N;
ll cows[MAXN];

map<ll, ll> prefix;

void adjust(ll low, ll high, ll& min_occupied, ll& max_occupied) {
    if (high <= cows[N - 1]) {
        auto low_ptr = prefix.lower_bound(low);
        auto high_ptr = prefix.upper_bound(high);
        high_ptr--;

        ll occupied = high_ptr->second - low_ptr->second + 1;
        //cout << occupied << "a\n";

        min_occupied = min(min_occupied, occupied);
        max_occupied = max(max_occupied, occupied);
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "herding";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) {
        cin >> cows[i];
    }

    sort(cows, cows + N);
    
    cows[N] = pow(10, 10);

    for (ll i = 0; i < N; i++) {
        prefix[cows[i]] = i + 1;
    }

    ll min_occupied = N;
    ll max_occupied = 0;

    //cout << N << "\n";

    for (ll i = 0; i < N; i++) {
        ll high = cows[i] + N - 1;
        adjust(cows[i], high, min_occupied, max_occupied);
        adjust(cows[i] + 1, high + 1, min_occupied, max_occupied);
    }

    cout << N - max_occupied << "\n";
    cout << N - min_occupied << "\n";
	
	return 0;
}