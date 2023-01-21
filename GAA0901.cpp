#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

typedef long long ll;

ll N, M;
ll daily[MAXN];

bool works(ll maxe) {
    ll sum = 0;
    ll count = 1;

    for (ll i = 0; i < N; i++) {
        if (daily[i] > maxe) return false;
        if (sum + daily[i] <= maxe) {
            sum += daily[i];
        }
        else {
            count++;
            sum = daily[i];
        }
    }

    return count <= M;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAA0901";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N >> M;

    for (ll i = 0; i < N; i++) {
        cin >> daily[i];
    }

    ll low = 0;
    ll high = 1e6 + 5;

    while (high - low > 1) {
        ll mid = (low + high) / 2;
        if (works(mid)) {
            high = mid;
        }
        else {
            low = mid;
        }
    }

    cout << high << "\n";
	
	return 0;
}