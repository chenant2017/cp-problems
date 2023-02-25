#include <bits/stdc++.h>
#define MAX 100010
using namespace std;

typedef long long ll;

ll N, T;
ll a[MAX];
ll b[MAX];

ll solve() {
    ll j = 0;
    for (ll i = 0; i < N; i++) {
        while (j < N && a[j] != b[i]) {
            j++;
        }
        if (j == N) {
            return N - i;
        }
    }
    return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "1776H";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> T;

    while (T--) {
        cin >> N;
        for (ll i = N - 1; i >= 0; i--) {
            cin >> a[i];
        }
        for (ll i = N - 1; i >= 0; i--) {
            cin >> b[i];
        }

        cout << solve() << endl;
    }
	
	return 0;
}