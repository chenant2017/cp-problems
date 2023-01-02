#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N;
map<ll, vector<ll>> ind; 
vector<ll> ids;

bool cmp(const ll& a, const ll& b) {
    ll count = 0;
    for (ll i = 0; i < 5; i++) {
        if (ind[a][i] < ind[b][i]) {
            count++;
        }
    }
    return count >= 3;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAA0102";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
    cin >> N;

    for (ll i = 0; i < 5; i++) {
        for (ll j = 0; j < N; j++) {
            ll id;
            cin >> id;
            ind[id].push_back(j);
        }
    }

    for (auto& i: ind) {
        ids.push_back(i.first);
    }

    sort(ids.begin(), ids.end(), cmp);

    for (auto i: ids) {
        cout << i << "\n";
    }
	
	return 0;
}