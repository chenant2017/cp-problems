#include <bits/stdc++.h>
#define f first 
#define s second
#define MAXN 50010
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

map<ll, ll> breed_counts;
set<ll> dist_breeds;
pll breeds[MAXN];

ll N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "dog";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) {
        ll x, id;
        cin >> x >> id;

        dist_breeds.insert(id);
        breeds[i] = pll({x, id});
    }

    sort(breeds, breeds + N);

    for (ll i = 0; i < N; i++) {
        //cout << breeds[i].f << " " << breeds[i].s << "\n";
    }

    ll ans = pow(10, 9);
    ll start = 0;
    ll end = 0;

    for (ll i = 0; i < N; i++) {
        breed_counts[breeds[i].s]++;
        end = i;

        while (breed_counts[breeds[start].s] > 1) {
            breed_counts[breeds[start].s]--;
            start++;
        }
        
        //cout << breed_counts.size() << " " << dist_breeds.size() << "\n";

        if (breed_counts.size() == dist_breeds.size()) {
            ans = min(ans, breeds[end].f - breeds[start].f);
        }
    }

    cout << ans << "\n";
	
	return 0;
}