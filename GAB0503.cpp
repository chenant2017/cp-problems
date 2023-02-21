#include <bits/stdc++.h>
#define MAX 1000010
#define MOD ((ll) 1e9 + 7)
using namespace std;

typedef long long ll;

ll N, M, K;
ll dp[MAX];
ll pf[MAX];

ll mod_pow(ll a, ll b) {
    vector<ll> v (ceil(log2(b)) + 1);

    v[0] = a;

    for (ll i = 1; i <= floor(log2(b)); i++) {
        v[i] = (ll) pow(v[i - 1], 2) % MOD;
    }

    ll result = 1;

    cout << b << "\n";

    while (b > 0) {
        ll p = floor(log2(b));
        cout << b << " " << p << "\n";
        result *= v[p];
        result %= MOD;
        b -= (1 << p);
    }

    return result % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAB0503";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M >> K;

    cout << mod_pow(M, N) << "\n";
    
    for (ll i = 1; i < K; i++) {
        dp[i] = mod_pow(M, i);
        pf[i] = (dp[i] + pf[i - 1]) % MOD;
    }

    for (ll i = K; i <= N; i++) {
        dp[i] = ((pf[i - 1] - pf[i - K] + MOD) * (M - 1)) % MOD;
        //cout << i << " " << dp[i] << "\n";
        pf[i] = (dp[i] + pf[i - 1]) % MOD;
    }

    cout << (mod_pow(M, N) - dp[N] + MOD) % MOD << "\n";
	
	return 0;
}