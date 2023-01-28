#include <bits/stdc++.h>
#define MAXN 510
using namespace std;

typedef long long ll;

ll N, M;
string seqs1[MAXN];
string seqs2[MAXN];

bool works(ll a, ll b) {
    ll len = b - a + 1;
    set<string> s;
    for (ll i = 0; i < N; i++) {
        //cout << seqs1[i].substr(a, len) << "\n";
        s.insert(seqs1[i].substr(a, len));
    }
    for (ll i = 0; i < N; i++) {
        if (s.find(seqs2[i].substr(a, len)) != s.end()) {
            return false;
        }
    }
    //cout << a << " " << b << " w\n";
    return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAA1102";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
    cin >> N >> M;

    for (ll i = 0; i < N; i++) {
        cin >> seqs1[i];
    }

    for (ll i = 0; i < N; i++) {
        cin >> seqs2[i];
    }

    ll ans = M;

    for (ll i = 0; i < M; i++) {
        if (!works(0, i)) continue;

        ll low = 0;
        ll high = i;

        while (high - low > 1) {
            ll mid = (low + high) / 2;
            if (works(mid, i)) {
                low = mid;
            }
            else {
                high = mid;
            }
        }

        //cout << i << " " << low << "\n";
        ans = min(ans, i - low + 1);
    }

    cout << ans << "\n";
	
	return 0;
}