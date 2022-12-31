#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

typedef long long ll;

ll N, M;

multiset<ll> s_in;
ll f[MAXN];
ll s[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GB1104";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
    
    cin >> N >> M;

    for (ll i = 0; i < N; i++) {
        cin >> f[i];
        cin >> s[i];
    }

    ll sum = f[0];
    s_in.insert(s[0]);
    ll ptr2 = 0;
    ll ans = 1e10;

    for (ll ptr1 = 0; ptr1 < N; ptr1++) {
        while (ptr2 + 1 < N && sum < M) {
            ptr2++;
            sum += f[ptr2];
            s_in.insert(s[ptr2]);
        }

        if (ptr2 + 1 == N && sum < M) {
            break;
        }

        ans = min(ans, *s_in.rbegin());

        sum -= f[ptr1];
        s_in.erase(s[ptr1]);
    }

    cout << ans << "\n";
	
	return 0;
}