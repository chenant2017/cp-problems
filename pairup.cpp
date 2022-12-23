#include <bits/stdc++.h>
#define f first 
#define s second
#define MAXN 100010
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N;
pll cows[MAXN];

ll solve() {
    ll result = 0;
    ll ptr1 = 0;
    ll ptr2 = N - 1;

    while (ptr1 < ptr2) {
        ll time = cows[ptr1].f + cows[ptr2].f;
        result = max(result, time);

        if (cows[ptr1].s < cows[ptr2].s) {
            cows[ptr2].s -= cows[ptr1].s;
            ptr1++;
        }   
        else if (cows[ptr1].s > cows[ptr2].s) {
            cows[ptr1].s -= cows[ptr2].s;
            ptr2--;
        }
        else {
            ptr1++;
            ptr2--;
        }
    }

    if (ptr1 == ptr2) {
        result = max(result, 2 * cows[ptr1].f);
    }

    return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string fname = "pairup";
	freopen((fname + ".in").c_str(), "r", stdin);
	freopen((fname + ".out").c_str(), "w", stdout);
	
	cin >> N;

    for (ll i = 0; i < N; i++) {
        cin >> cows[i].s >> cows[i].f;
    }

    sort(cows, cows + N);

    cout << solve() << "\n";
	
	return 0;
}