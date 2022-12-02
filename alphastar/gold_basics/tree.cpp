#include <bits/stdc++.h>
#define MAXN 10010
#define f first 
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pdl;

ll N, I, H, R;
set<pdl> intervals;
ll prefix[MAXN] = {0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "tree";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> I >> H >> R;

    for (ll i = 0; i < R; i++) {
        ll a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        intervals.insert(pll({a, b}));
    }

    for (auto& i: intervals) {
        prefix[i.f + 1]++; 
        prefix[i.s]--;
    }

    for (ll i = 2; i <= N; i++) {
        prefix[i] += prefix[i - 1];
        //cout << i << " " << prefix[i] << "\n";
    }
    //cout << "\n";*/

    for (ll i = 1; i <= N; i++) {
        cout << H - prefix[i] << "\n";
    }
	
	return 0;
}