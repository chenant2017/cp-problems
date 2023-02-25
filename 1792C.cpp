#include <bits/stdc++.h>
#define MAX 200010
using namespace std;

typedef long long ll;

ll N, T;
ll arr[MAX];
ll ind[MAX];

ll solve() {
    for (ll i = 1; i <= N; i++) {
        ind[arr[i]] = i;
    }

    ll val1, val2;
    if (N % 2 == 1) {
        val1 = N / 2 + 1;
        val2 = val1;
    }
    else {
        val1 = N / 2;
        val2 = N / 2 + 1;
    }

    ll ptr1 = ind[val1];
    ll ptr2 = ind[val2];
    ll count = 0;

    while (true) {
        //cout << ptr1 << " " << ptr2 << "\n";
        if (ptr1 > ptr2) break;
        if (val1 == 0) break;
        if (ind[val1] > ptr1 || ind[val2] < ptr2) {
            break;
        }

        ptr1 = ind[val1];
        ptr2 = ind[val2];

        if (ptr1 != ptr2) {
            count++;
        }
        
        val1--;
        val2++;
    }   

    return N / 2 - count;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "1792C";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> T;

    while (T--) {
        cin >> N;
        for (ll i = 1; i <= N; i++) {
            cin >> arr[i];
        }
        cout << solve() << "\n";
    }
	
	return 0;
}