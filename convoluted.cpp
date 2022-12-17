//Silver 2021 December #3

#include <bits/stdc++.h>
#define MAXN 200010
#define MAXM 5010
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N, M;
ll a[MAXM] = {0};
ll b[MAXM] = {0};
ll inv_prefix[2 * MAXM] = {0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "convoluted";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;

    ll start, end;
    for (ll i = 0; i < N; i++) {
        cin >> start >> end;
        a[start]++;
        b[end]++;
    }

    for (ll i = 0; i <= M; i++) {
        for (ll j = 0; j <= M; j++) {
            inv_prefix[i + j] += a[i] * a[j];
            inv_prefix[i + j + 1] -= b[i] * b[j];
        }
    }

    ll prefix = 0;
    for (ll i = 0; i <= 2 * M; i++) {
        prefix += inv_prefix[i];
        cout << prefix << "\n";
    }
	
	return 0;
}