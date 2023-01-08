#include <bits/stdc++.h>
#define MAXA 5000010
using namespace std;

typedef long long ll;

ll N, T;
ll turns[MAXA];
int who[MAXA];
bool is_prime[MAXA];
vector<ll> primes[4];

void sieve() {
    fill(is_prime, is_prime + MAXA, true);
    is_prime[0] = false;
    for (ll i = 2; i <= sqrt(MAXA); i++) {
        if (is_prime[i]) {
            for (ll j = i*i; j < MAXA; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "221202";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);

    sieve();

    for (ll i = 1; i < MAXA; i++) {
        if (is_prime[i]) {
            primes[i % 4].push_back(i);
            turns[i] = 1;
            who[i] = 1;
        }
        else if (i % 4 == 0) {
            turns[i] = i / 4 + 1;
            who[i] = 2;
        }
        else {
            who[i] = 1;
            turns[i] = turns[i - *primes[i % 4].rbegin()];
        }
    }
	
	cin >> T;

    while (T--) {
        cin >> N;
        ll min_turns = 2 * 1e6;
        int winner;
        for (ll i = 0; i < N; i++) {
            ll a;
            cin >> a;
            if (turns[a] < min_turns) {
                min_turns = turns[a];
                winner = who[a];
            }
        }

        if (winner == 1) {
            cout << "Farmer John\n";
        }
        else {
            cout << "Farmer Nhoj\n";
        }
    }
	
	return 0;
}