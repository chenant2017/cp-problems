#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N;
vector<ll> original;
vector<ll> modified;
vector<ll> tested;
vector<ll> best;
vector<ll> ans;

ll get_diff(vector<ll>& v1, vector<ll>& v2) {
    ll result = 0;
    for (ll i = 0; i < N; i++) {
        if (v1[i] != v2[i]) result++;
    }

    return result;
}

void solve() {
    ans.push_back(get_diff(original, modified));

    for (ll i = 1; i < N; i++) {
        ll best_diff = -1;

        for (ll j = 0; j < N; j++) {
            if (modified[j] == 0) continue;

            tested = modified;
            
            ll k = j;
            while (k < N && modified[k] != 0) {
                tested[k] = k - j;
                k++;
            }

            ll diff = get_diff(original, tested);

            if (best_diff == -1 || diff < best_diff) {
                best_diff = diff;
                best = tested;
            }
        }
        
        ans.push_back(best_diff);
        modified = best;
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GB0703";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) {
        ll a; 
        cin >> a;
        original.push_back(a);
        modified.push_back(i);
    }

    solve();

    for (auto i: ans) {
        cout << i << "\n";
    }
	
	return 0;
}