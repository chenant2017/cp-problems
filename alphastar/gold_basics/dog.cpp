#include <bits/stdc++.h>
#define MAXN 50010
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pdl;

ll N;
map<ll, ll> breed_ind;
set<ll> inds;
set<ll> breeds;
pdl dogs[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "dog";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) {
        ll x, b;
        cin >> x >> b;
        breeds.insert(b);
        dogs[i] = pdl({x, b});
    }

    sort(dogs, dogs + N);

    ll ans = pow(10, 10);

    for (ll i = 0; i < N; i++) {
        //cout << dogs[i].f << " " << dogs[i].s << "\n";
        
        if (breed_ind.find(dogs[i].s) != breed_ind.end()) {
            inds.erase(breed_ind[dogs[i].s]);
        }

        breed_ind[dogs[i].s] = dogs[i].f;
        inds.insert(dogs[i].f);
        
        if (breeds.size() == inds.size()) {
            ll cost = *inds.rbegin() - *inds.begin();
            ans = min(ans, cost);
        }       
    }

    cout << ans << "\n";
	
	return 0;
}