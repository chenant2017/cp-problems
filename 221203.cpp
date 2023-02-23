#include <bits/stdc++.h>
#define MAX 310
using namespace std;

typedef long long ll;

ll N;
ll a[MAX][MAX];
vector<ll> arr;

ll range(ll b, ll i) {
    ll mi = 1e18;
    ll ma = -1e18;

    for (ll j = i; j < arr.size(); j++) {
        mi = min(mi, arr[j]);
        ma = max(ma, arr[j]);
    }

    mi = min(mi, b);
    ma = max(ma, b);

    return ma - mi;
}

bool works(ll b, ll j) {
    for (ll i = 0; i < j - 1; i++) {
        if (range(b, i) != a[i][j]) {
            return false;
        }
    }
    return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "221203";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) {
        for (ll j = i; j < N; j++) {
            cin >> a[i][j];
        }
    }

    arr.push_back(0); 

    for (ll j = 1; j < N; j++) {
        ll diff = a[j - 1][j];
        //cout << diff << " diff\n";

        ll upper = arr[j - 1] + diff;
        ll lower = arr[j - 1] - diff;

        if (works(upper, j)) {
            arr.push_back(upper);
        }
        else {
            arr.push_back(lower);
        }
    }

    for (ll i = 0; i < arr.size() - 1; i++) {
        cout << arr[i] << " ";
    }
    cout << arr[arr.size() - 1] << "\n";
	
	return 0;
}