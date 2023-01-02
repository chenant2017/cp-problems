#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

typedef long long ll;

ll N, B;
multiset<ll> diffs;
set<ll> curr;
map<ll, vector<ll>> ind;
map<ll, ll> min_d;
ll depths[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAA0104";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> B;

    for (ll i = 0; i < N; i++) {
        ll f; cin >> f;
        depths[i] = f;
        ind[f].push_back(i);
    }

    curr.insert(ind[0][0]);
    for (ll i = 1; i < ind[0].size(); i++) {
        diffs.insert(ind[0][i] - ind[0][i - 1]);
        curr.insert(ind[0][i]);
    }

    min_d[0] = *diffs.rbegin();

    for (auto i = next(ind.begin(), 1); i != ind.end(); i++) {
        for (auto j: i->second) {
            auto it2 = curr.upper_bound(j);
            auto it1 = it2; it1--;
            diffs.erase(diffs.find(*it2 - *it1));
            diffs.insert(j - *it1);
            diffs.insert(*it2 - j);
            curr.insert(j);
        }

        min_d[i->first] = *diffs.rbegin();
    }

    for (ll i = 0; i < B; i++) {
        ll s, d;
        cin >> s >> d;

        auto it = min_d.upper_bound(s); it--;
        if (d >= it->second) {
            cout << 1;
        } 
        else {
            cout << 0;
        }
        cout << "\n";
    }
	
	return 0;
}