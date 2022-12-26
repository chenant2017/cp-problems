#include <bits/stdc++.h>
#define MAXN 1010

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<pll, pll> ppll;

map<pll, ll> counts;

ll N;

ll original[MAXN];
ll sorted[MAXN];
ppll complements[] = {{{1, 2}, {2, 1}}, {{2, 3}, {3, 2}}, {{1, 3}, {3, 1}}};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GB0802";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) {
        ll a;
        cin >> a;
        original[i] = a;
        sorted[i] = a;
    }

    sort(sorted, sorted + N);

    for (ll i = 0; i < N; i++) {
        //cout << original[i] << " " << sorted[i] << "\n";
        if (original[i] != sorted[i]) {
            counts[pll({original[i], sorted[i]})]++;
        }
    }

    ll ans = 0;
    ll total = 0;

    for (auto i: complements) {
        ll min_count = min(counts[i.first], counts[i.second]);
        counts[i.first] -= min_count;
        counts[i.second] -= min_count;
        ans += min_count;
        total += counts[i.first] + counts[i.second];
    }

    //cout << total << "\n";

    ans += ((double)2/3) * total;

    cout << ans << "\n";
    
	
	return 0;
}