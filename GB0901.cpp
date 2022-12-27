#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N, K;
set<ll> nums;

ll fact(ll i) {
    if (i == 0) return 1;
    return i * fact(i - 1);
}

string get_perm(ll line) {
    line--;
    string result;
    set<ll> nums2 = nums;

    for (ll i = N - 1; i >= 0; i--) {
        ll index = line / fact(i);
        auto digit = nums2.begin();
        advance(digit, index);

        result += to_string(*digit) + " ";
        nums2.erase(digit);

        line -= index * fact(i);
    }
    
    return result;
}

ll get_line(vector<ll> perm) {
    ll result = 0;
    set<ll> nums2 = nums;
    
    for (ll i = 0; i < N; i++) {
        ll index = distance(nums2.begin(), nums2.find(perm[i]));
        result += index * fact(N - 1 - i);

        nums2.erase(perm[i]);
    }

    return result + 1;
}

int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	
	string fname = "GB0901";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
    cin >> N >> K;

	for (ll i = 1; i <= N; i++) {
        nums.insert(i);
    }

    for (ll i = 0; i < K; i++) {
        string c;
        cin >> c;
        if (c == "P") {
            ll line;
            cin >> line;
            cout << get_perm(line) << "\n";
        }
        else {
            vector<ll> perm;
            for (ll j = 0; j < N; j++) {
                ll a;
                cin >> a;
                perm.push_back(a);
            }
            cout << get_line(perm) << "\n";
        }
    }

	return 0;
}