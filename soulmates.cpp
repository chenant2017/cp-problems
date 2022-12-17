#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N;

vector<ll> get_va(ll a) {
    vector<ll> result;

    result.push_back(a);
    while (a > 1) {
        if (a % 2 == 0) {
            a /= 2;
        }
        else {
            a++;
        }
        result.push_back(a);
    }
    /*for (auto i: result) {
        cout << i << " ";
    }
    cout << "\n";*/
    return result;
}

vector<ll> get_vb(ll b) {
    vector<ll> result;
    result.push_back(b);
    while (b > 1) {
        if (b % 2 == 0) {
            b /= 2;
        }
        else {
            b--;
        }
        result.push_back(b);
    }
    reverse(result.begin(), result.end());
    /*for (auto i: result) {
        cout << i << " ";
    }
    cout << "\n";*/
    return result;
}

ll solve(ll a, ll b) {
    ll result = -1;

    vector<ll> va = get_va(a);
    vector<ll> vb = get_vb(b);

    for (ll i = 0; i < va.size(); i++) {
        auto lb = lower_bound(vb.begin(), vb.end(), va[i]);
        if (lb != vb.end()) {
            ll poss = (i) + (*lb - va[i]) + (vb.end() - lb - 1);
            if (result == -1 || poss < result) {
                result = poss;
            }
        }   
    }
    return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "soulmates";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) {
        ll a, b;
        cin >> a >> b;
        cout << solve(a, b) << "\n";
    }
	
	return 0;
}