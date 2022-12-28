#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

typedef long long ll;

ll N, K, L;
ll citations[MAXN];

bool works(ll h) {
    ll good = 0;
    ll remaining = K * L;
    for (ll i = 0; i < N; i++) {
        if (citations[i] >= h) {
            good++;
        }
        else if (citations[i] + K >= h) {
            if (remaining >= h - citations[i]) {
                remaining -= h - citations[i];
                good++;
            }
        }
    }

    return good >= h;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "acowdemia";
	//freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
    cin >> N >> K >> L;

    for (ll i = 0; i < N; i++) {
        cin >> citations[i];
    }

    sort(citations, citations + N, greater<ll>());

    ll h = 0;
    ll jump = N / 2;

    while (jump > 0) {
        if (works(h + jump)) {
            h += jump;
        }
        else {
            jump /= 2;
        }
    }

    cout << h << "\n";
	
	return 0;
}