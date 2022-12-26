#include <bits/stdc++.h>
#define MAXN 1010

using namespace std;

typedef long long ll;

ll N;
ll line[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GB0802";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) {
        cin >> line[i];
    }

    ll ans = 0;

    for (ll i = 0; i < N - 1; i++) {
        ll smallest = N + 1;
        ll partner;
        for (ll j = i + 1; j < N; j++) {
            if (line[j] < smallest) {
                partner = j;
                smallest = line[j];
            }
        }
        if (line[i] != line[partner]) {
            swap(line[i], line[partner]);
            ans++;
        }
    }

    cout << ans << "\n";
	
	return 0;
}