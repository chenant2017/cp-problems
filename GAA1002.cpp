#include <bits/stdc++.h>
#define MAXN 100000
using namespace std;

typedef long long ll;

ll N;
vector<ll> barn (MAXN);
ll pf[MAXN];
vector<ll> rotated;
ll source2[MAXN];

ll get_source(ll i, ll* source) {
    ll s = source[i];
    while (barn[s] == 0) {
        s = source[s];
    }
    return s;
}

void get_sources(ll* source) {
    ll ptr1 = 0;
    ll ptr2 = 0;

    while (ptr2 < N) {
        if (ptr1 == ptr2) {
            ptr2++;
        }
        else if (barn[ptr2] == 0) {
            source[ptr2] = ptr1;
            ptr2++;
        }
        else {
            source[ptr2] = ptr1;
            ptr1 = ptr2;
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "GAA1002";
	freopen((fname + ".in").c_str(), "r", stdin);
	//freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) {
        cin >> barn[i];
    }

    ll split = N - 1;

    pf[N] = 0;

    for (ll i = N - 1; i >= 0; i--) {
        pf[i] = pf[i + 1] + barn[i] - 1;
    }

    ll maxpf = -1e18;

    for (ll i = N - 1; i >= 0; i--) {
        if (barn[i] == 0 && pf[i] > maxpf) {
            maxpf = pf[i];
            split = i;
        }
    }

    for (ll i = split + 1; i < N; i++) {
        rotated.push_back(barn[i]);
    }

    for (ll i = 0; i <= split; i++) {
        rotated.push_back(barn[i]);
    }

    barn = rotated;

    get_sources(source2);

    ll ans = 0;

    for (ll i = N - 1; i >= 0; i--) {
        if (barn[i] == 1) continue;
        assert(barn[i] == 0);
        ll s = get_source(i, source2);
        barn[s]--;
        barn[i]++;
        ans += pow(s - i, 2);
    }

    cout << ans << "\n";
	
	return 0;
}