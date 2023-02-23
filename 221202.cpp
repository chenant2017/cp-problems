#include <bits/stdc++.h>
#define MAXA 5000010
#define MAXP 1250010
using namespace std;

typedef long long ll;

bool is_prime[MAXA];
vector<ll> primes[4];
char winner[MAXA];
ll visits[MAXA];

ll T, N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "221202";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
    fill(is_prime, is_prime + MAXA, true);

    for (ll i = 2; i * i < MAXA; i++) {
        if (is_prime[i]) {
            //cout << i << " i\n";
            for (ll j = i * i; j < MAXA; j += i) {
                is_prime[j] = false;
            }
        }
    }

    for (ll i = 2; i < MAXA; i++) {
        if (is_prime[i]) {
            primes[i % 4].push_back(i);
        }
    }

    visits[0] = 1;
    visits[1] = 1;
    winner[0] = 'N';
    winner[1] = 'J';

    for (ll i = 2; i < MAXA; i++) {
        if (i % 4 == 0) {
            winner[i] = 'N';
            visits[i] = i / 4 + 1;
            continue;
        }
        
        winner[i] = 'J';

        if (i % 4 == 2) {
            visits[i] = visits[i - 2];
        }
        else {
            auto it = upper_bound(primes[i % 4].begin(), primes[i % 4].end(), i);
            it--;
            visits[i] = visits[i - *it];
        }
    }

    cin >> T;
    while (T--) {
        cin >> N;

        vector<ll> v;

        for (ll i = 0; i < N; i++) {
            ll a;
            cin >> a;
            v.push_back(a);
        }

        ll min = 1e18;
        ll ans = -1;

        for (auto a: v) {
            if (visits[a] < min) {
                min = visits[a];
                ans = a;
            }
        }

        if (winner[ans] == 'J') {
            cout << "Farmer John\n";
        }
        else {
            cout << "Farmer Nhoj\n";
        }
    }
	
	return 0;
}