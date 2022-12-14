#include <bits/stdc++.h>
#define MAXN 200010
#define MAXM 5010
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N, M;
pll intervals[MAXN];
ll inv_prefix[2 * MAXM] = {0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "convoluted";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;

    ll ai, bi;
    for (ll i = 0; i < N; i++) {
        cin >> intervals[i].f >> intervals[i].s;
    }

    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            ll asum = intervals[i].f + intervals[j].f;
            ll bsum = intervals[i].s + intervals[j].s;
            inv_prefix[asum]++;
            inv_prefix[bsum + 1]--;
        }
    }

    ll prefix = 0;
    for (ll i = 0; i <= 2 * M; i++) {
        prefix += inv_prefix[i];
        cout << prefix << "\n";
    }
	
	return 0;
}